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
include _common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/compiler_depend.make

# Include the progress variables for this target.
include _common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/progress.make

# Include the compile flags for this target's objects.
include _common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/flags.make

_common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/TestSerialize.cc.o: _common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/flags.make
_common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/TestSerialize.cc.o: /work/zhaoy/Bureau/framework/arccore/src/serialize/tests/TestSerialize.cc
_common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/TestSerialize.cc.o: _common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/TestSerialize.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/serialize/tests && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/TestSerialize.cc.o -MF CMakeFiles/arccore_serialize.tests.dir/TestSerialize.cc.o.d -o CMakeFiles/arccore_serialize.tests.dir/TestSerialize.cc.o -c /work/zhaoy/Bureau/framework/arccore/src/serialize/tests/TestSerialize.cc

_common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/TestSerialize.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/arccore_serialize.tests.dir/TestSerialize.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/serialize/tests && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/arccore/src/serialize/tests/TestSerialize.cc > CMakeFiles/arccore_serialize.tests.dir/TestSerialize.cc.i

_common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/TestSerialize.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/arccore_serialize.tests.dir/TestSerialize.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/serialize/tests && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/arccore/src/serialize/tests/TestSerialize.cc -o CMakeFiles/arccore_serialize.tests.dir/TestSerialize.cc.s

# Object files for target arccore_serialize.tests
arccore_serialize_tests_OBJECTS = \
"CMakeFiles/arccore_serialize.tests.dir/TestSerialize.cc.o"

# External object files for target arccore_serialize.tests
arccore_serialize_tests_EXTERNAL_OBJECTS =

lib/arccore_serialize.tests: _common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/TestSerialize.cc.o
lib/arccore_serialize.tests: _common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/build.make
lib/arccore_serialize.tests: lib/libarccore_serialize.so
lib/arccore_serialize.tests: lib/libarccore_collections.so
lib/arccore_serialize.tests: lib/libarccore_base.so
lib/arccore_serialize.tests: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/googletest/1.11.0-GCCcore-11.2.0/lib64/libgtest_main.so.1.11.0
lib/arccore_serialize.tests: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/googletest/1.11.0-GCCcore-11.2.0/lib64/libgtest.so.1.11.0
lib/arccore_serialize.tests: _common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../../../../../lib/arccore_serialize.tests"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/serialize/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arccore_serialize.tests.dir/link.txt --verbose=$(VERBOSE)
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/serialize/tests && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/CMake/3.28.1-GCCcore-11.2.0/bin/cmake -D TEST_TARGET=arccore_serialize.tests -D TEST_EXECUTABLE=/work/zhaoy/Bureau/framework/build_release/lib/arccore_serialize.tests -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/serialize/tests -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=arccore_serialize.tests_TESTS -D CTEST_FILE=/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/serialize/tests/arccore_serialize.tests[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=30 -D TEST_XML_OUTPUT_DIR= -P /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/CMake/3.28.1-GCCcore-11.2.0/share/cmake-3.28/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
_common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/build: lib/arccore_serialize.tests
.PHONY : _common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/build

_common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/clean:
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/serialize/tests && $(CMAKE_COMMAND) -P CMakeFiles/arccore_serialize.tests.dir/cmake_clean.cmake
.PHONY : _common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/clean

_common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/depend:
	cd /work/zhaoy/Bureau/framework/build_release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/zhaoy/Bureau/framework /work/zhaoy/Bureau/framework/arccore/src/serialize/tests /work/zhaoy/Bureau/framework/build_release /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/serialize/tests /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _common/build_all/arcane/arccore/src/serialize/tests/CMakeFiles/arccore_serialize.tests.dir/depend

