add_test([=[MessagePassing.OneStat]=]  /work/zhaoy/Bureau/framework/build_release/lib/arccore_message_passing.tests [==[--gtest_filter=MessagePassing.OneStat]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[MessagePassing.OneStat]=]  PROPERTIES WORKING_DIRECTORY /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/message_passing/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  arccore_message_passing.tests_TESTS MessagePassing.OneStat)
