add_test([=[DirectedGraphTest.UnitTest]=]  /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/SGraph.tests [==[--gtest_filter=DirectedGraphTest.UnitTest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DirectedGraphTest.UnitTest]=]  PROPERTIES WORKING_DIRECTORY /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DirectedGraphTest.VertexTest]=]  /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/SGraph.tests [==[--gtest_filter=DirectedGraphTest.VertexTest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DirectedGraphTest.VertexTest]=]  PROPERTIES WORKING_DIRECTORY /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DirectedGraphTest.EdgeTest]=]  /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/SGraph.tests [==[--gtest_filter=DirectedGraphTest.EdgeTest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DirectedGraphTest.EdgeTest]=]  PROPERTIES WORKING_DIRECTORY /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DirectedGraphTest.EdgeTestConst]=]  /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/SGraph.tests [==[--gtest_filter=DirectedGraphTest.EdgeTestConst]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DirectedGraphTest.EdgeTestConst]=]  PROPERTIES WORKING_DIRECTORY /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DirectedAcyclicGraphTest.UnitTest]=]  /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/SGraph.tests [==[--gtest_filter=DirectedAcyclicGraphTest.UnitTest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DirectedAcyclicGraphTest.UnitTest]=]  PROPERTIES WORKING_DIRECTORY /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DirectedAcyclicGraphTest.UserClassTest]=]  /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/SGraph.tests [==[--gtest_filter=DirectedAcyclicGraphTest.UserClassTest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DirectedAcyclicGraphTest.UserClassTest]=]  PROPERTIES WORKING_DIRECTORY /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DirectedAcyclicGraphTest.VertexComparatorTest]=]  /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/SGraph.tests [==[--gtest_filter=DirectedAcyclicGraphTest.VertexComparatorTest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DirectedAcyclicGraphTest.VertexComparatorTest]=]  PROPERTIES WORKING_DIRECTORY /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DirectedAcyclicGraphTest.EdgeComparatorTest]=]  /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/SGraph.tests [==[--gtest_filter=DirectedAcyclicGraphTest.EdgeComparatorTest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DirectedAcyclicGraphTest.EdgeComparatorTest]=]  PROPERTIES WORKING_DIRECTORY /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DirectedAcyclicGraphTest.VertexStreamConverterTest]=]  /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/SGraph.tests [==[--gtest_filter=DirectedAcyclicGraphTest.VertexStreamConverterTest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DirectedAcyclicGraphTest.VertexStreamConverterTest]=]  PROPERTIES WORKING_DIRECTORY /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DirectedAcyclicGraphTest.EdgeStreamConverterTest]=]  /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/SGraph.tests [==[--gtest_filter=DirectedAcyclicGraphTest.EdgeStreamConverterTest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DirectedAcyclicGraphTest.EdgeStreamConverterTest]=]  PROPERTIES WORKING_DIRECTORY /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  SGraph.tests_TESTS DirectedGraphTest.UnitTest DirectedGraphTest.VertexTest DirectedGraphTest.EdgeTest DirectedGraphTest.EdgeTestConst DirectedAcyclicGraphTest.UnitTest DirectedAcyclicGraphTest.UserClassTest DirectedAcyclicGraphTest.VertexComparatorTest DirectedAcyclicGraphTest.EdgeComparatorTest DirectedAcyclicGraphTest.VertexStreamConverterTest DirectedAcyclicGraphTest.EdgeStreamConverterTest)
