add_test([=[ArcaneDataTypes.Misc]=]  /work/zhaoy/Bureau/framework/build_release/lib/arcane_core.tests [==[--gtest_filter=ArcaneDataTypes.Misc]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[ArcaneDataTypes.Misc]=]  PROPERTIES WORKING_DIRECTORY /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/core/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  arcane_core.tests_TESTS ArcaneDataTypes.Misc)
