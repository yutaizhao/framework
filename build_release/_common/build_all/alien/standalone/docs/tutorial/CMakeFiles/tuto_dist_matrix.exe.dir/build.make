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
include _common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/compiler_depend.make

# Include the progress variables for this target.
include _common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/progress.make

# Include the compile flags for this target's objects.
include _common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/flags.make

_common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/dist_matrix.cpp.o: _common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/flags.make
_common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/dist_matrix.cpp.o: /work/zhaoy/Bureau/framework/alien/standalone/docs/tutorial/dist_matrix.cpp
_common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/dist_matrix.cpp.o: _common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/dist_matrix.cpp.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/docs/tutorial && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/dist_matrix.cpp.o -MF CMakeFiles/tuto_dist_matrix.exe.dir/dist_matrix.cpp.o.d -o CMakeFiles/tuto_dist_matrix.exe.dir/dist_matrix.cpp.o -c /work/zhaoy/Bureau/framework/alien/standalone/docs/tutorial/dist_matrix.cpp

_common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/dist_matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tuto_dist_matrix.exe.dir/dist_matrix.cpp.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/docs/tutorial && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/alien/standalone/docs/tutorial/dist_matrix.cpp > CMakeFiles/tuto_dist_matrix.exe.dir/dist_matrix.cpp.i

_common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/dist_matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tuto_dist_matrix.exe.dir/dist_matrix.cpp.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/docs/tutorial && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/alien/standalone/docs/tutorial/dist_matrix.cpp -o CMakeFiles/tuto_dist_matrix.exe.dir/dist_matrix.cpp.s

# Object files for target tuto_dist_matrix.exe
tuto_dist_matrix_exe_OBJECTS = \
"CMakeFiles/tuto_dist_matrix.exe.dir/dist_matrix.cpp.o"

# External object files for target tuto_dist_matrix.exe
tuto_dist_matrix_exe_EXTERNAL_OBJECTS =

_common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe: _common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/dist_matrix.cpp.o
_common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe: _common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/build.make
_common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe: _common/build_all/alien/standalone/src/refsemantic/libalien_semantic_ref.so
_common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe: _common/build_all/alien/standalone/src/core/libalien_core.so
_common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe: lib/libarccore_message_passing_mpi.so
_common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe: lib/libarccore_message_passing.so
_common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe: lib/libarccore_serialize.so
_common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/impi/2021.4.0-GCC-11.2.0/mpi/2021.4.0/lib/libmpicxx.so
_common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/impi/2021.4.0-GCC-11.2.0/mpi/2021.4.0/lib/release/libmpi.so
_common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe: /lib64/librt.a
_common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe: /lib64/libpthread.a
_common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe: /lib64/libdl.a
_common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe: lib/libarccore_trace.so
_common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe: lib/libarccore_concurrency.so
_common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe: lib/libarccore_collections.so
_common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe: lib/libarccore_base.so
_common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/Boost/1.78.0-GCC-11.2.0/lib/libboost_program_options-mt-x64.so.1.78.0
_common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/imkl/2021.4.0/mkl/2021.4.0/lib/intel64/libmkl_intel_lp64.so
_common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/imkl/2021.4.0/mkl/2021.4.0/lib/intel64/libmkl_intel_thread.so
_common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/imkl/2021.4.0/mkl/2021.4.0/lib/intel64/libmkl_core.so
_common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/ifort/2021.4.0/compiler/2021.4.0/linux/compiler/lib/intel64_lin/libiomp5.so
_common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe: _common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tuto_dist_matrix.exe"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/docs/tutorial && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tuto_dist_matrix.exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/build: _common/build_all/alien/standalone/docs/tutorial/tuto_dist_matrix.exe
.PHONY : _common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/build

_common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/clean:
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/docs/tutorial && $(CMAKE_COMMAND) -P CMakeFiles/tuto_dist_matrix.exe.dir/cmake_clean.cmake
.PHONY : _common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/clean

_common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/depend:
	cd /work/zhaoy/Bureau/framework/build_release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/zhaoy/Bureau/framework /work/zhaoy/Bureau/framework/alien/standalone/docs/tutorial /work/zhaoy/Bureau/framework/build_release /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/docs/tutorial /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _common/build_all/alien/standalone/docs/tutorial/CMakeFiles/tuto_dist_matrix.exe.dir/depend
