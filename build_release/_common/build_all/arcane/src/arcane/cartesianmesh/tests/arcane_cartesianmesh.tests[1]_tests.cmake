add_test([=[CartesianMeshV2.TestCartesianNumbering]=]  /work/zhaoy/Bureau/framework/build_release/lib/arcane_cartesianmesh.tests [==[--gtest_filter=CartesianMeshV2.TestCartesianNumbering]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[CartesianMeshV2.TestCartesianNumbering]=]  PROPERTIES WORKING_DIRECTORY /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/cartesianmesh/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[CartesianMeshV2.TestCartesianGrid]=]  /work/zhaoy/Bureau/framework/build_release/lib/arcane_cartesianmesh.tests [==[--gtest_filter=CartesianMeshV2.TestCartesianGrid]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[CartesianMeshV2.TestCartesianGrid]=]  PROPERTIES WORKING_DIRECTORY /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/cartesianmesh/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  arcane_cartesianmesh.tests_TESTS CartesianMeshV2.TestCartesianNumbering CartesianMeshV2.TestCartesianGrid)
