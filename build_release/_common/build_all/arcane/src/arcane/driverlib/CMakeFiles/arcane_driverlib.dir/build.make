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
include _common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/compiler_depend.make

# Include the progress variables for this target.
include _common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/progress.make

# Include the compile flags for this target's objects.
include _common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/flags.make

_common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/ArcaneCodeService.cc.o: _common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/flags.make
_common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/ArcaneCodeService.cc.o: /work/zhaoy/Bureau/framework/arcane/src/arcane/driverlib/ArcaneCodeService.cc
_common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/ArcaneCodeService.cc.o: _common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/ArcaneCodeService.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/driverlib && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/ArcaneCodeService.cc.o -MF CMakeFiles/arcane_driverlib.dir/ArcaneCodeService.cc.o.d -o CMakeFiles/arcane_driverlib.dir/ArcaneCodeService.cc.o -c /work/zhaoy/Bureau/framework/arcane/src/arcane/driverlib/ArcaneCodeService.cc

_common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/ArcaneCodeService.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/arcane_driverlib.dir/ArcaneCodeService.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/driverlib && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/arcane/src/arcane/driverlib/ArcaneCodeService.cc > CMakeFiles/arcane_driverlib.dir/ArcaneCodeService.cc.i

_common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/ArcaneCodeService.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/arcane_driverlib.dir/ArcaneCodeService.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/driverlib && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/arcane/src/arcane/driverlib/ArcaneCodeService.cc -o CMakeFiles/arcane_driverlib.dir/ArcaneCodeService.cc.s

# Object files for target arcane_driverlib
arcane_driverlib_OBJECTS = \
"CMakeFiles/arcane_driverlib.dir/ArcaneCodeService.cc.o"

# External object files for target arcane_driverlib
arcane_driverlib_EXTERNAL_OBJECTS =

lib/libarcane_driverlib.so: _common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/ArcaneCodeService.cc.o
lib/libarcane_driverlib.so: _common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/build.make
lib/libarcane_driverlib.so: lib/libarcane_std.so
lib/libarcane_driverlib.so: lib/libarccore_message_passing_mpi.so
lib/libarcane_driverlib.so: lib/libarcane_hdf5.so
lib/libarcane_driverlib.so: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/HDF5/1.12.1-gimpi-2021b/lib/libhdf5.so
lib/libarcane_driverlib.so: lib/libarcane_mesh.so
lib/libarcane_driverlib.so: lib/libarcane_impl.so
lib/libarcane_driverlib.so: lib/libarcane_core.so
lib/libarcane_driverlib.so: lib/libarcane_accelerator_core.so
lib/libarcane_driverlib.so: lib/libarccore_message_passing.so
lib/libarcane_driverlib.so: lib/libarccore_serialize.so
lib/libarcane_driverlib.so: lib/libarcane_utils.so
lib/libarcane_driverlib.so: lib/libarccore_trace.so
lib/libarcane_driverlib.so: lib/libarccore_collections.so
lib/libarcane_driverlib.so: lib/libarccore_concurrency.so
lib/libarcane_driverlib.so: lib/libarccore_base.so
lib/libarcane_driverlib.so: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GLib/2.70.1-GCCcore-11.2.0/lib/libglib-2.0.so
lib/libarcane_driverlib.so: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GLib/2.70.1-GCCcore-11.2.0/lib/libgthread-2.0.so
lib/libarcane_driverlib.so: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GLib/2.70.1-GCCcore-11.2.0/lib/libgmodule-2.0.so
lib/libarcane_driverlib.so: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/HDF5/1.12.1-gimpi-2021b/lib/libhdf5.so
lib/libarcane_driverlib.so: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/impi/2021.4.0-GCC-11.2.0/mpi/2021.4.0/lib/libmpicxx.so
lib/libarcane_driverlib.so: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/impi/2021.4.0-GCC-11.2.0/mpi/2021.4.0/lib/release/libmpi.so
lib/libarcane_driverlib.so: /lib64/librt.a
lib/libarcane_driverlib.so: /lib64/libpthread.a
lib/libarcane_driverlib.so: /lib64/libdl.a
lib/libarcane_driverlib.so: _common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../../../../../lib/libarcane_driverlib.so"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/driverlib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arcane_driverlib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/build: lib/libarcane_driverlib.so
.PHONY : _common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/build

_common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/clean:
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/driverlib && $(CMAKE_COMMAND) -P CMakeFiles/arcane_driverlib.dir/cmake_clean.cmake
.PHONY : _common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/clean

_common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/depend:
	cd /work/zhaoy/Bureau/framework/build_release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/zhaoy/Bureau/framework /work/zhaoy/Bureau/framework/arcane/src/arcane/driverlib /work/zhaoy/Bureau/framework/build_release /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/driverlib /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _common/build_all/arcane/src/arcane/driverlib/CMakeFiles/arcane_driverlib.dir/depend
