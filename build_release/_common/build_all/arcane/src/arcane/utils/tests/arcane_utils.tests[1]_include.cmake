if(EXISTS "/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/utils/tests/arcane_utils.tests[1]_tests.cmake")
  include("/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/utils/tests/arcane_utils.tests[1]_tests.cmake")
else()
  add_test(arcane_utils.tests_NOT_BUILT arcane_utils.tests_NOT_BUILT)
endif()