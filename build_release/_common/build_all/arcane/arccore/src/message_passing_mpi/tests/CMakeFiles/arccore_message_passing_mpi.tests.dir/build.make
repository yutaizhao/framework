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
include _common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/compiler_depend.make

# Include the progress variables for this target.
include _common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/progress.make

# Include the compile flags for this target's objects.
include _common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/flags.make

_common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMain.cc.o: _common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/flags.make
_common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMain.cc.o: /work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/tests/TestMain.cc
_common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMain.cc.o: _common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMain.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/message_passing_mpi/tests && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMain.cc.o -MF CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMain.cc.o.d -o CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMain.cc.o -c /work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/tests/TestMain.cc

_common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMain.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMain.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/message_passing_mpi/tests && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/tests/TestMain.cc > CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMain.cc.i

_common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMain.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMain.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/message_passing_mpi/tests && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/tests/TestMain.cc -o CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMain.cc.s

_common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMpi.cc.o: _common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/flags.make
_common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMpi.cc.o: /work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/tests/TestMpi.cc
_common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMpi.cc.o: _common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object _common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMpi.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/message_passing_mpi/tests && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMpi.cc.o -MF CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMpi.cc.o.d -o CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMpi.cc.o -c /work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/tests/TestMpi.cc

_common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMpi.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMpi.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/message_passing_mpi/tests && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/tests/TestMpi.cc > CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMpi.cc.i

_common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMpi.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMpi.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/message_passing_mpi/tests && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/tests/TestMpi.cc -o CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMpi.cc.s

# Object files for target arccore_message_passing_mpi.tests
arccore_message_passing_mpi_tests_OBJECTS = \
"CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMain.cc.o" \
"CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMpi.cc.o"

# External object files for target arccore_message_passing_mpi.tests
arccore_message_passing_mpi_tests_EXTERNAL_OBJECTS =

lib/arccore_message_passing_mpi.tests: _common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMain.cc.o
lib/arccore_message_passing_mpi.tests: _common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/TestMpi.cc.o
lib/arccore_message_passing_mpi.tests: _common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/build.make
lib/arccore_message_passing_mpi.tests: lib/libarccore_message_passing_mpi.so
lib/arccore_message_passing_mpi.tests: lib/libarccore_message_passing.so
lib/arccore_message_passing_mpi.tests: lib/libarccore_trace.so
lib/arccore_message_passing_mpi.tests: lib/libarccore_serialize.so
lib/arccore_message_passing_mpi.tests: lib/libarccore_collections.so
lib/arccore_message_passing_mpi.tests: lib/libarccore_concurrency.so
lib/arccore_message_passing_mpi.tests: lib/libarccore_base.so
lib/arccore_message_passing_mpi.tests: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/impi/2021.4.0-GCC-11.2.0/mpi/2021.4.0/lib/libmpicxx.so
lib/arccore_message_passing_mpi.tests: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/impi/2021.4.0-GCC-11.2.0/mpi/2021.4.0/lib/release/libmpi.so
lib/arccore_message_passing_mpi.tests: /lib64/librt.a
lib/arccore_message_passing_mpi.tests: /lib64/libpthread.a
lib/arccore_message_passing_mpi.tests: /lib64/libdl.a
lib/arccore_message_passing_mpi.tests: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/googletest/1.11.0-GCCcore-11.2.0/lib64/libgtest.so.1.11.0
lib/arccore_message_passing_mpi.tests: _common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../../../../../../lib/arccore_message_passing_mpi.tests"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/message_passing_mpi/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arccore_message_passing_mpi.tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/build: lib/arccore_message_passing_mpi.tests
.PHONY : _common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/build

_common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/clean:
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/message_passing_mpi/tests && $(CMAKE_COMMAND) -P CMakeFiles/arccore_message_passing_mpi.tests.dir/cmake_clean.cmake
.PHONY : _common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/clean

_common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/depend:
	cd /work/zhaoy/Bureau/framework/build_release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/zhaoy/Bureau/framework /work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/tests /work/zhaoy/Bureau/framework/build_release /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/message_passing_mpi/tests /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _common/build_all/arcane/arccore/src/message_passing_mpi/tests/CMakeFiles/arccore_message_passing_mpi.tests.dir/depend
