if(EXISTS "/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/src/tests/Neo.tests[1]_tests.cmake")
  include("/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/src/tests/Neo.tests[1]_tests.cmake")
else()
  add_test(Neo.tests_NOT_BUILT Neo.tests_NOT_BUILT)
endif()
