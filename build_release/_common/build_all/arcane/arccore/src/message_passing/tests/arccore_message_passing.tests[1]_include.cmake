if(EXISTS "/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/message_passing/tests/arccore_message_passing.tests[1]_tests.cmake")
  include("/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/message_passing/tests/arccore_message_passing.tests[1]_tests.cmake")
else()
  add_test(arccore_message_passing.tests_NOT_BUILT arccore_message_passing.tests_NOT_BUILT)
endif()
