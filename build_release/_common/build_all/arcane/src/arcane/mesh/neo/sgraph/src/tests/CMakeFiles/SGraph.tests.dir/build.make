# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/CMake/3.28.1-GCCcore-11.2.0/bin/cmake

# The command to remove a file.
RM = /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/CMake/3.28.1-GCCcore-11.2.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /work/zhaoy/Bureau/framework

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /work/zhaoy/Bureau/framework/build_release

# Include any dependencies generated for this target.
include _common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/compiler_depend.make

# Include the progress variables for this target.
include _common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/progress.make

# Include the compile flags for this target's objects.
include _common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/flags.make

_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/GraphTest.cpp.o: _common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/flags.make
_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/GraphTest.cpp.o: /work/zhaoy/Bureau/framework/arctools/neo/sgraph/src/tests/GraphTest.cpp
_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/GraphTest.cpp.o: _common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/GraphTest.cpp.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/GraphTest.cpp.o -MF CMakeFiles/SGraph.tests.dir/GraphTest.cpp.o.d -o CMakeFiles/SGraph.tests.dir/GraphTest.cpp.o -c /work/zhaoy/Bureau/framework/arctools/neo/sgraph/src/tests/GraphTest.cpp

_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/GraphTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SGraph.tests.dir/GraphTest.cpp.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/arctools/neo/sgraph/src/tests/GraphTest.cpp > CMakeFiles/SGraph.tests.dir/GraphTest.cpp.i

_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/GraphTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SGraph.tests.dir/GraphTest.cpp.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/arctools/neo/sgraph/src/tests/GraphTest.cpp -o CMakeFiles/SGraph.tests.dir/GraphTest.cpp.s

# Object files for target SGraph.tests
SGraph_tests_OBJECTS = \
"CMakeFiles/SGraph.tests.dir/GraphTest.cpp.o"

# External object files for target SGraph.tests
SGraph_tests_EXTERNAL_OBJECTS =

_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/SGraph.tests: _common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/GraphTest.cpp.o
_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/SGraph.tests: _common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/build.make
_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/SGraph.tests: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/googletest/1.11.0-GCCcore-11.2.0/lib64/libgtest_main.so.1.11.0
_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/SGraph.tests: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/googletest/1.11.0-GCCcore-11.2.0/lib64/libgtest.so.1.11.0
_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/SGraph.tests: _common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SGraph.tests"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SGraph.tests.dir/link.txt --verbose=$(VERBOSE)
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/CMake/3.28.1-GCCcore-11.2.0/bin/cmake -D TEST_TARGET=SGraph.tests -D TEST_EXECUTABLE=/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/SGraph.tests -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=SGraph.tests_TESTS -D CTEST_FILE=/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/SGraph.tests[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/CMake/3.28.1-GCCcore-11.2.0/share/cmake-3.28/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/build: _common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/SGraph.tests
.PHONY : _common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/build

_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/clean:
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests && $(CMAKE_COMMAND) -P CMakeFiles/SGraph.tests.dir/cmake_clean.cmake
.PHONY : _common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/clean

_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/depend:
	cd /work/zhaoy/Bureau/framework/build_release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/zhaoy/Bureau/framework /work/zhaoy/Bureau/framework/arctools/neo/sgraph/src/tests /work/zhaoy/Bureau/framework/build_release /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _common/build_all/arcane/src/arcane/mesh/neo/sgraph/src/tests/CMakeFiles/SGraph.tests.dir/depend

