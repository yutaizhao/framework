if(EXISTS "/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/trace/tests/arccore_trace.tests[1]_tests.cmake")
  include("/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/trace/tests/arccore_trace.tests[1]_tests.cmake")
else()
  add_test(arccore_trace.tests_NOT_BUILT arccore_trace.tests_NOT_BUILT)
endif()