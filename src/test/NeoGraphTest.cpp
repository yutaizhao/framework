// -*- tab-width: 2; indent-tabs-mode: nil; coding: utf-8-with-signature -*-
//-----------------------------------------------------------------------------
// Copyright 2000-2021 CEA (www.cea.fr) IFPEN (www.ifpenergiesnouvelles.com)
// See the top-level COPYRIGHT file for details.
// SPDX-License-Identifier: Apache-2.0
//-----------------------------------------------------------------------------
/*---------------------------------------------------------------------------*/
/* NeoGraphTest                                    (C) 2000-2021             */
/*                                                                           */
/* Test dag plug in Neo MeshBase                                             */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#include <gtest/gtest.h>
#include "neo/Neo.h"

//----------------------------------------------------------------------------/

void _addAlgorithms(Neo::MeshBase& mesh, Neo::Family& item_family, std::vector<int>& algo_order)
{
  // Consume P1 produce P2
  mesh.addAlgorithm(Neo::InProperty{ item_family,"prop1"},
                    Neo::OutProperty{ item_family,"prop2"},
                    [&algo_order]([[maybe_unused]] Neo::PropertyT<Neo::utils::Int32> const& p1,
                    [[maybe_unused]] Neo::PropertyT<Neo::utils::Int32>& p2){
    std::cout << "Algo 2 "<< std::endl;
    algo_order.push_back(2);
  });
  // Produce P1
  mesh.addAlgorithm(Neo::OutProperty{ item_family,"prop1"}, [&algo_order]([[maybe_unused]] Neo::PropertyT<Neo::utils::Int32>& p1){
    std::cout << "Algo 1 "<< std::endl;
    algo_order.push_back(1);
  });
}

TEST(NeoGraphTest,BaseTest)
{
  Neo::MeshBase mesh{"test_mesh"};
  mesh.addFamily(Neo::ItemKind::IK_Cell, "cell_family");
  Neo::Family& cell_family = mesh.getFamily(Neo::ItemKind::IK_Cell, "cell_family");
  cell_family.addProperty<Neo::utils::Int32>("prop1");
  cell_family.addProperty<Neo::utils::Int32>("prop2");
  std::vector<int> algo_index(3);
  std::vector<int> algo_order;

  _addAlgorithms(mesh, cell_family, algo_order);
  mesh.applyAlgorithms(Neo::MeshBase::AlgorithmExecutionOrder::FIFO);
  EXPECT_TRUE(std::equal(algo_order.begin(), algo_order.end(), std::vector{2,1}.begin()));
  algo_order.clear();

  _addAlgorithms(mesh, cell_family, algo_order);
  mesh.applyAlgorithms(Neo::MeshBase::AlgorithmExecutionOrder::DAG);
  EXPECT_TRUE(std::equal(algo_order.begin(), algo_order.end(), std::vector{1,2}.begin()));
  algo_order.clear();

  _addAlgorithms(mesh, cell_family, algo_order);
  mesh.applyAlgorithms(Neo::MeshBase::AlgorithmExecutionOrder::LIFO);
  EXPECT_TRUE(std::equal(algo_order.begin(), algo_order.end(), std::vector{1,2}.begin()));
  algo_order.clear();
}

//----------------------------------------------------------------------------/

TEST(NeoGraphTest,OneProducingAlgoTest)
{
  Neo::MeshBase mesh{ "test_mesh" };
  mesh.addFamily(Neo::ItemKind::IK_Cell, "cell_family");
  Neo::Family& cell_family = mesh.getFamily(Neo::ItemKind::IK_Cell, "cell_family");
  bool is_called = false;

  // First try without adding property: algo not called
  mesh.addAlgorithm(Neo::OutProperty{cell_family,"prop1"},[&is_called]([[maybe_unused]]Neo::PropertyT<Neo::utils::Int32> & p1) {
    std::cout << "Algo 1" << std::endl;
    is_called = true;
  });
  mesh.applyAlgorithms(Neo::MeshBase::AlgorithmExecutionOrder::DAG);
  EXPECT_FALSE(is_called);

  // Now add property: algo must be called
  cell_family.addProperty<Neo::utils::Int32>("prop1");
  mesh.addAlgorithm(Neo::OutProperty{cell_family,"prop1"},[&is_called]([[maybe_unused]]Neo::PropertyT<Neo::utils::Int32> & p1) {
    std::cout << "Algo 1" << std::endl;
    is_called = true;
  });

  mesh.applyAlgorithms(Neo::MeshBase::AlgorithmExecutionOrder::DAG);
  EXPECT_TRUE(is_called);
}

//----------------------------------------------------------------------------/

TEST(NeoGraphTest,OneConsumingProducingAlgoTest){
  Neo::MeshBase mesh{ "test_mesh" };
  mesh.addFamily(Neo::ItemKind::IK_Cell, "cell_family");
  Neo::Family& cell_family = mesh.getFamily(Neo::ItemKind::IK_Cell, "cell_family");
  bool is_called = false;
  mesh.addAlgorithm(Neo::InProperty{cell_family,"prop1",Neo::PropertyStatus::ExistingProperty},
                    Neo::OutProperty{cell_family,"prop2"},[&is_called]([[maybe_unused]]Neo::PropertyT<Neo::utils::Int32> const& p1,
                                                                       [[maybe_unused]]Neo::PropertyT<Neo::utils::Int32> & p2) {
    std::cout << "Algo 1" << std::endl;
    is_called = true;
  });

  // First try without adding property: algo not called
  auto mesh_no_prop = mesh;
  mesh_no_prop.applyAlgorithms(Neo::MeshBase::AlgorithmExecutionOrder::DAG);
  EXPECT_FALSE(is_called);

  // Second try adding only produced property: algo still not called
  auto mesh_prop2 = mesh;
  mesh_prop2.getFamily(Neo::ItemKind::IK_Cell, "cell_family").addProperty<Neo::utils::Int32>("prop2");
  mesh_prop2.applyAlgorithms(Neo::MeshBase::AlgorithmExecutionOrder::DAG);
  EXPECT_FALSE(is_called);

  // Third try  adding only produced property: algo still not called
  auto mesh_prop1 = mesh;
  mesh_prop1.getFamily(Neo::ItemKind::IK_Cell, "cell_family").addProperty<Neo::utils::Int32>("prop1");
  mesh_prop1.applyAlgorithms(Neo::MeshBase::AlgorithmExecutionOrder::DAG);
  EXPECT_FALSE(is_called);

  // Last try adding both properties: algo called
  mesh.getFamily(Neo::ItemKind::IK_Cell, "cell_family").addProperty<Neo::utils::Int32>("prop1");
  mesh.getFamily(Neo::ItemKind::IK_Cell, "cell_family").addProperty<Neo::utils::Int32>("prop2");
  mesh.applyAlgorithms(Neo::MeshBase::AlgorithmExecutionOrder::DAG);
  EXPECT_TRUE(is_called);
  // Rk: if prop1 had been a ComputedProperty, the algo would not have been called, since no producing algo
  // see bellow
  is_called = false;
  mesh.addAlgorithm(Neo::InProperty{cell_family,"prop1",Neo::PropertyStatus::ComputedProperty}, // ComputedProperty is the default
                    Neo::OutProperty{cell_family,"prop2"},[&is_called]([[maybe_unused]]Neo::PropertyT<Neo::utils::Int32> const& p1,
                                                                       [[maybe_unused]]Neo::PropertyT<Neo::utils::Int32> & p2) {
      is_called = true;
  });
  mesh.applyAlgorithms(Neo::MeshBase::AlgorithmExecutionOrder::DAG);
  EXPECT_FALSE(is_called); // algo not called, since no one produces prop1, a ComputedProperty

  // Detect cycle in graph : Produce and consume same property
  mesh.addAlgorithm(Neo::InProperty{cell_family,"prop1",Neo::PropertyStatus::ExistingProperty},
                    Neo::OutProperty{cell_family,"prop1"},[]([[maybe_unused]]Neo::PropertyT<Neo::utils::Int32> const& p1,
                                                             [[maybe_unused]]Neo::PropertyT<Neo::utils::Int32> & p1_bis) {});
  EXPECT_THROW(mesh.applyAlgorithms(Neo::MeshBase::AlgorithmExecutionOrder::DAG),std::runtime_error);
  // Check that dag is cleared even when throws
  EXPECT_NO_THROW(mesh.applyAlgorithms(Neo::MeshBase::AlgorithmExecutionOrder::DAG));
  // Cycle does throw even if algo is not triggered: eg if Prop 1 does not exist
  mesh_no_prop.addAlgorithm(Neo::InProperty{cell_family,"prop1",Neo::PropertyStatus::ExistingProperty},
                            Neo::OutProperty{cell_family,"prop1"},[]([[maybe_unused]]Neo::PropertyT<Neo::utils::Int32> const& p1,
                                                                     [[maybe_unused]]Neo::PropertyT<Neo::utils::Int32> & p1_bis) {});
  EXPECT_THROW(mesh_no_prop.applyAndKeepAlgorithms(Neo::MeshBase::AlgorithmExecutionOrder::DAG),std::runtime_error);
  // if algorithms are kept must still throw
  EXPECT_THROW(mesh_no_prop.applyAlgorithms(Neo::MeshBase::AlgorithmExecutionOrder::DAG),std::runtime_error);
}

//----------------------------------------------------------------------------/

void _addAlgorithmsWithCycle(Neo::MeshBase& mesh, Neo::Family& item_family){
  // Consume P1 produce P2
  mesh.addAlgorithm(Neo::InProperty{ item_family,"prop1"},
                    Neo::OutProperty{ item_family,"prop2"},
                    []([[maybe_unused]] Neo::PropertyT<Neo::utils::Int32> const& p1,
                       [[maybe_unused]] Neo::PropertyT<Neo::utils::Int32>& p2){
                      std::cout << "Algo 2 "<< std::endl;
                    });
  // Produce P1 Consume P2
  mesh.addAlgorithm(Neo::InProperty{ item_family,"prop1"},
                    Neo::OutProperty{ item_family,"prop1"},
                    []([[maybe_unused]] Neo::PropertyT<Neo::utils::Int32>& p1,
                       [[maybe_unused]] Neo::PropertyT<Neo::utils::Int32>& p2){
    std::cout << "Algo 1 "<< std::endl;
  });
}

TEST(NeoGraphTest,CycleDetectionTest)
{
  Neo::MeshBase mesh{ "test_mesh" };
  mesh.addFamily(Neo::ItemKind::IK_Cell, "cell_family");
  Neo::Family& cell_family = mesh.getFamily(Neo::ItemKind::IK_Cell, "cell_family");
  cell_family.addProperty<Neo::utils::Int32>("prop1");
  cell_family.addProperty<Neo::utils::Int32>("prop2");

  _addAlgorithmsWithCycle(mesh, cell_family);
  // Must throw since cycle in graph
  EXPECT_THROW(mesh.applyAlgorithms(Neo::MeshBase::AlgorithmExecutionOrder::DAG),std::runtime_error);
}

//----------------------------------------------------------------------------/

void _addAlgorithmsInputPropNotProduced(Neo::MeshBase& mesh, Neo::Family& item_family, bool& is_algo_called){
  // Consume P1 produce P2
  mesh.addAlgorithm(Neo::InProperty{ item_family,"prop1"},
                    Neo::OutProperty{ item_family,"prop2"},
                    [&is_algo_called]([[maybe_unused]] Neo::PropertyT<Neo::utils::Int32> const& p1,
                       [[maybe_unused]] Neo::PropertyT<Neo::utils::Int32>& p2){
                      std::cout << "Algo 2 "<< std::endl;
                      is_algo_called = true;
                    });
}

TEST(NeoGraphTest,MissingInputPopertyProductionAlgorithmTest)
{
  Neo::MeshBase mesh{ "test_mesh" };
  mesh.addFamily(Neo::ItemKind::IK_Cell, "cell_family");
  Neo::Family& cell_family = mesh.getFamily(Neo::ItemKind::IK_Cell, "cell_family");
  cell_family.addProperty<Neo::utils::Int32>("prop1");
  cell_family.addProperty<Neo::utils::Int32>("prop2");
  bool is_algo_called = false;

  _addAlgorithmsInputPropNotProduced(mesh, cell_family,is_algo_called);
  // Must throw since cycle in graph
  mesh.applyAlgorithms(Neo::MeshBase::AlgorithmExecutionOrder::DAG);
  EXPECT_FALSE(is_algo_called);
}

void _addAlgorithmsInexistingPropProduction(Neo::MeshBase& mesh, Neo::Family& item_family, bool& called){
  // Produce P1
  mesh.addAlgorithm(Neo::OutProperty{ item_family,"prop1"}, []([[maybe_unused]] Neo::PropertyT<Neo::utils::Int32>& p1){
    std::cout << "Algo 1 "<< std::endl;
  });
  // Produce P2
  mesh.addAlgorithm(Neo::OutProperty{ item_family,"prop2"}, []([[maybe_unused]] Neo::PropertyT<Neo::utils::Int32>& p2){
    std::cout << "Algo 2 "<< std::endl;
  });
  // Consume P1 & P2, produce P3
  mesh.addAlgorithm(Neo::InProperty{ item_family,"prop1"},
                    Neo::InProperty{ item_family,"prop2"},
                    Neo::OutProperty{ item_family,"prop3"},
                    []([[maybe_unused]] Neo::PropertyT<Neo::utils::Int32> const& p1,
                       [[maybe_unused]] Neo::PropertyT<Neo::utils::Int32> const& p2,
                       [[maybe_unused]] Neo::PropertyT<Neo::utils::Int32>& p3){
                      std::cout << "Algo 3 "<< std::endl;
                    });
  // Consume P1, produce P4
  mesh.addAlgorithm(Neo::InProperty{ item_family,"prop1"},
                    Neo::OutProperty{ item_family,"prop4"},
                    []([[maybe_unused]] Neo::PropertyT<Neo::utils::Int32> const& p1,
                       [[maybe_unused]] Neo::PropertyT<Neo::utils::Int32>& p3){
                      std::cout << "Algo 4 "<< std::endl;
                    });
  // Consume P2, produce P5
  mesh.addAlgorithm(Neo::InProperty{ item_family,"prop2"},
                    Neo::OutProperty{ item_family,"prop5"},
                    []([[maybe_unused]] Neo::PropertyT<Neo::utils::Int32> const& p1,
                       [[maybe_unused]] Neo::PropertyT<Neo::utils::Int32>& p3){
                      std::cout << "Algo 5 "<< std::endl;
                    });

}

TEST(NeoGraphTest,ProducingInexistingPropertyTest)
{
  Neo::MeshBase mesh{ "test_mesh" };
  mesh.addFamily(Neo::ItemKind::IK_Cell, "cell_family");
  Neo::Family& cell_family = mesh.getFamily(Neo::ItemKind::IK_Cell, "cell_family");
  bool is_algo_called = false;
  cell_family.addProperty<Neo::utils::Int32>("prop1");
  cell_family.addProperty<Neo::utils::Int32>("prop2");
//  cell_family.addProperty<Neo::utils::Int32>("prop3");
//  cell_family.addProperty<Neo::utils::Int32>("prop4");
//  cell_family.addProperty<Neo::utils::Int32>("prop5");
// todo pour ok prop1 et prop2 : il faut ajouter self edge

  _addAlgorithmsInexistingPropProduction(mesh, cell_family,is_algo_called);
  // Must throw since cycle in graph
  mesh.applyAlgorithms(Neo::MeshBase::AlgorithmExecutionOrder::DAG);
//  EXPECT_FALSE(is_algo_called);
}


TEST(NeoGraphTest,OneFamilyOnePropertyTest){

  // Aucun sens !! gros cycle !!
  Neo::MeshBase mesh{"test_mesh"};
  mesh.addFamily(Neo::ItemKind::IK_Cell, "cell_family");
  Neo::Family& cell_family = mesh.getFamily(Neo::ItemKind::IK_Cell, "cell_family");
  // Fill a property on the created cells, must be done after cell creation !
  cell_family.addProperty<Neo::utils::Int32>("prop");
  mesh.addAlgorithm(Neo::InProperty{cell_family,cell_family.lidPropName()},
                    Neo::OutProperty{cell_family,"prop"},
                    [](Neo::ItemLidsProperty const& cell_lid_prop, Neo::PropertyT<Neo::utils::Int32>& prop){
                        std::cout << "Fill property after cell creation "<< std::endl;
                        prop.init(cell_lid_prop.values(),42);
                    });
  mesh.addAlgorithm(Neo::InProperty{cell_family,"prop"},
                    Neo::OutProperty{cell_family,"prop"},
                    []([[maybe_unused]]Neo::PropertyT<Neo::utils::Int32> const& previous_prop, Neo::PropertyT<Neo::utils::Int32>& prop){
    std::cout << "Modify property after fill "<< std::endl;
    // previous prop added to create a dependence
    for (auto& val : prop) {
      val += 1;
    }
  });
  mesh.addAlgorithm(Neo::OutProperty{cell_family,cell_family.lidPropName()},
                    [](Neo::ItemLidsProperty & cell_lid_prop){
                        std::cout << "Create Cells "<< std::endl;
                        cell_lid_prop.append({0,1,2});
                    });
  mesh.applyAlgorithms(Neo::MeshBase::AlgorithmExecutionOrder::DAG);
  auto& prop = cell_family.getConcreteProperty<Neo::PropertyT<Neo::utils::Int32>>("prop");
  EXPECT_EQ(prop.size(),mesh.nbItems(Neo::ItemKind::IK_Cell));
  std::vector<int> ref_values(mesh.nbItems(Neo::ItemKind::IK_Cell),43);
  auto values = prop.values();
  EXPECT_TRUE(std::equal(values.begin(),values.end(),ref_values.begin()));
}

//----------------------------------------------------------------------------/
//----------------------------------------------------------------------------/