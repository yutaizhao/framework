#!/bin/sh
ARCANE_VTU_DATA_MODE_TO_ASCII=1
export ARCANE_VTU_DATA_MODE_TO_ASCII
/work/zhaoy/Bureau/framework/build_release/bin/arcane_partition_mesh -n 2 -p 4 --writer VtuNewMeshWriter tube5x5x100.vtk && /work/zhaoy/Bureau/framework/build_release/bin/arcane_test_driver launch -n 4 -m 2 /work/zhaoy/Bureau/framework/arcane/tests/testHydro-5-vtu.arc
