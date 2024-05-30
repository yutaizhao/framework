add_test([=[Serialize.Misc]=]  /work/zhaoy/Bureau/framework/build_release/lib/arccore_serialize.tests [==[--gtest_filter=Serialize.Misc]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Serialize.Misc]=]  PROPERTIES WORKING_DIRECTORY /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/serialize/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  arccore_serialize.tests_TESTS Serialize.Misc)
