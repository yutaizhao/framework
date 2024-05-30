# CMake generated Testfile for 
# Source directory: /work/zhaoy/Bureau/framework/alien/standalone/src/refsemantic/tests
# Build directory: /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/refsemantic/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ref.seq "/work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/refsemantic/tests/ref.gtest.seq")
set_tests_properties(ref.seq PROPERTIES  _BACKTRACE_TRIPLES "/work/zhaoy/Bureau/framework/alien/standalone/CMake/LoadAlienTest.cmake;62;add_test;/work/zhaoy/Bureau/framework/alien/standalone/src/refsemantic/tests/CMakeLists.txt;124;alien_test;/work/zhaoy/Bureau/framework/alien/standalone/src/refsemantic/tests/CMakeLists.txt;0;")
add_test(ref.mpi "/work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/refsemantic/tests/ref.gtest.mpi")
set_tests_properties(ref.mpi PROPERTIES  _BACKTRACE_TRIPLES "/work/zhaoy/Bureau/framework/alien/standalone/CMake/LoadAlienTest.cmake;62;add_test;/work/zhaoy/Bureau/framework/alien/standalone/src/refsemantic/tests/CMakeLists.txt;129;alien_test;/work/zhaoy/Bureau/framework/alien/standalone/src/refsemantic/tests/CMakeLists.txt;0;")
add_test(ref.mpi.mpi-4 "/soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/impi/2021.4.0-GCC-11.2.0/mpi/2021.4.0/bin/mpiexec" "-n" "4" "/work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/refsemantic/tests/ref.gtest.mpi")
set_tests_properties(ref.mpi.mpi-4 PROPERTIES  ENVIRONMENT "OMPI_MCA_rmaps_base_oversubscribe=1" _BACKTRACE_TRIPLES "/work/zhaoy/Bureau/framework/alien/standalone/CMake/LoadAlienTest.cmake;108;add_test;/work/zhaoy/Bureau/framework/alien/standalone/src/refsemantic/tests/CMakeLists.txt;136;alien_test;/work/zhaoy/Bureau/framework/alien/standalone/src/refsemantic/tests/CMakeLists.txt;0;")
