# CMake generated Testfile for 
# Source directory: /work/zhaoy/Bureau/framework/alien/standalone/src/movesemantic/tests
# Build directory: /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/movesemantic/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(move.seq "/work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/movesemantic/tests/move.gtest.seq")
set_tests_properties(move.seq PROPERTIES  _BACKTRACE_TRIPLES "/work/zhaoy/Bureau/framework/alien/standalone/CMake/LoadAlienTest.cmake;62;add_test;/work/zhaoy/Bureau/framework/alien/standalone/src/movesemantic/tests/CMakeLists.txt;60;alien_test;/work/zhaoy/Bureau/framework/alien/standalone/src/movesemantic/tests/CMakeLists.txt;0;")
add_test(move.mpi "/work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/movesemantic/tests/move.gtest.mpi")
set_tests_properties(move.mpi PROPERTIES  _BACKTRACE_TRIPLES "/work/zhaoy/Bureau/framework/alien/standalone/CMake/LoadAlienTest.cmake;62;add_test;/work/zhaoy/Bureau/framework/alien/standalone/src/movesemantic/tests/CMakeLists.txt;65;alien_test;/work/zhaoy/Bureau/framework/alien/standalone/src/movesemantic/tests/CMakeLists.txt;0;")
add_test(move.mpi.mpi-4 "/soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/impi/2021.4.0-GCC-11.2.0/mpi/2021.4.0/bin/mpiexec" "-n" "4" "/work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/movesemantic/tests/move.gtest.mpi")
set_tests_properties(move.mpi.mpi-4 PROPERTIES  ENVIRONMENT "OMPI_MCA_rmaps_base_oversubscribe=1" _BACKTRACE_TRIPLES "/work/zhaoy/Bureau/framework/alien/standalone/CMake/LoadAlienTest.cmake;108;add_test;/work/zhaoy/Bureau/framework/alien/standalone/src/movesemantic/tests/CMakeLists.txt;72;alien_test;/work/zhaoy/Bureau/framework/alien/standalone/src/movesemantic/tests/CMakeLists.txt;0;")
