# CMake generated Testfile for 
# Source directory: /work/zhaoy/Bureau/framework/alien/standalone/src/core/tests
# Build directory: /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(core.seq "/work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/tests/core.gtest.seq")
set_tests_properties(core.seq PROPERTIES  _BACKTRACE_TRIPLES "/work/zhaoy/Bureau/framework/alien/standalone/CMake/LoadAlienTest.cmake;62;add_test;/work/zhaoy/Bureau/framework/alien/standalone/src/core/tests/CMakeLists.txt;60;alien_test;/work/zhaoy/Bureau/framework/alien/standalone/src/core/tests/CMakeLists.txt;0;")
add_test(core.mpi "/work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/tests/core.gtest.mpi")
set_tests_properties(core.mpi PROPERTIES  _BACKTRACE_TRIPLES "/work/zhaoy/Bureau/framework/alien/standalone/CMake/LoadAlienTest.cmake;62;add_test;/work/zhaoy/Bureau/framework/alien/standalone/src/core/tests/CMakeLists.txt;65;alien_test;/work/zhaoy/Bureau/framework/alien/standalone/src/core/tests/CMakeLists.txt;0;")
add_test(core.mpi.mpi-2 "/soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/impi/2021.4.0-GCC-11.2.0/mpi/2021.4.0/bin/mpiexec" "-n" "2" "/work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/tests/core.gtest.mpi")
set_tests_properties(core.mpi.mpi-2 PROPERTIES  ENVIRONMENT "OMPI_MCA_rmaps_base_oversubscribe=1" _BACKTRACE_TRIPLES "/work/zhaoy/Bureau/framework/alien/standalone/CMake/LoadAlienTest.cmake;108;add_test;/work/zhaoy/Bureau/framework/alien/standalone/src/core/tests/CMakeLists.txt;72;alien_test;/work/zhaoy/Bureau/framework/alien/standalone/src/core/tests/CMakeLists.txt;0;")
