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
include _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/compiler_depend.make

# Include the progress variables for this target.
include _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/progress.make

# Include the compile flags for this target's objects.
include _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/flags.make

arcane/corefinement/ParallelCorefinement_axl.h: /work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/ParallelCorefinement.axl
arcane/corefinement/ParallelCorefinement_axl.h: bin/axlstar_dlls/Axlstar.Axl2ccT4.dll
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ../../../../../../arcane/corefinement/ParallelCorefinement_axl.h"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/corefinement && ../../../../../../bin/axl2ccT4 -i arcane/corefinement -o /work/zhaoy/Bureau/framework/build_release/arcane/corefinement --copy /work/zhaoy/Bureau/framework/build_release/share/axl/ParallelCorefinement_arcane_corefinement.axl /work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/ParallelCorefinement.axl

arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceTools_axl.h: /work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceTools.axl
arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceTools_axl.h: bin/axlstar_dlls/Axlstar.Axl2ccT4.dll
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating ../../../../../../arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceTools_axl.h"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/corefinement && ../../../../../../bin/axl2ccT4 -i arcane/corefinement/surfaceutils/geometrykernelsurfacetools -o /work/zhaoy/Bureau/framework/build_release/arcane/corefinement/surfaceutils/geometrykernelsurfacetools --copy /work/zhaoy/Bureau/framework/build_release/share/axl/GeometryKernelSurfaceTools_arcane_corefinement_surfaceutils_geometrykernelsurfacetools.axl /work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceTools.axl

_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/ParallelCorefinementService.cc.o: _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/flags.make
_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/ParallelCorefinementService.cc.o: /work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/ParallelCorefinementService.cc
_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/ParallelCorefinementService.cc.o: _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/ParallelCorefinementService.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/corefinement && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/ParallelCorefinementService.cc.o -MF CMakeFiles/arcane_corefinement.dir/ParallelCorefinementService.cc.o.d -o CMakeFiles/arcane_corefinement.dir/ParallelCorefinementService.cc.o -c /work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/ParallelCorefinementService.cc

_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/ParallelCorefinementService.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/arcane_corefinement.dir/ParallelCorefinementService.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/corefinement && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/ParallelCorefinementService.cc > CMakeFiles/arcane_corefinement.dir/ParallelCorefinementService.cc.i

_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/ParallelCorefinementService.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/arcane_corefinement.dir/ParallelCorefinementService.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/corefinement && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/ParallelCorefinementService.cc -o CMakeFiles/arcane_corefinement.dir/ParallelCorefinementService.cc.s

_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceInternalUtils.cc.o: _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/flags.make
_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceInternalUtils.cc.o: /work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceInternalUtils.cc
_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceInternalUtils.cc.o: _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceInternalUtils.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/corefinement && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceInternalUtils.cc.o -MF CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceInternalUtils.cc.o.d -o CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceInternalUtils.cc.o -c /work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceInternalUtils.cc

_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceInternalUtils.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceInternalUtils.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/corefinement && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceInternalUtils.cc > CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceInternalUtils.cc.i

_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceInternalUtils.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceInternalUtils.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/corefinement && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceInternalUtils.cc -o CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceInternalUtils.cc.s

_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceImpl.cc.o: _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/flags.make
_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceImpl.cc.o: /work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceImpl.cc
_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceImpl.cc.o: _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceImpl.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/corefinement && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceImpl.cc.o -MF CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceImpl.cc.o.d -o CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceImpl.cc.o -c /work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceImpl.cc

_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceImpl.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceImpl.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/corefinement && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceImpl.cc > CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceImpl.cc.i

_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceImpl.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceImpl.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/corefinement && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceImpl.cc -o CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceImpl.cc.s

_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceToolsService.cc.o: _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/flags.make
_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceToolsService.cc.o: /work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceToolsService.cc
_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceToolsService.cc.o: _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceToolsService.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/corefinement && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceToolsService.cc.o -MF CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceToolsService.cc.o.d -o CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceToolsService.cc.o -c /work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceToolsService.cc

_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceToolsService.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceToolsService.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/corefinement && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceToolsService.cc > CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceToolsService.cc.i

_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceToolsService.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceToolsService.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/corefinement && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceToolsService.cc -o CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceToolsService.cc.s

# Object files for target arcane_corefinement
arcane_corefinement_OBJECTS = \
"CMakeFiles/arcane_corefinement.dir/ParallelCorefinementService.cc.o" \
"CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceInternalUtils.cc.o" \
"CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceImpl.cc.o" \
"CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceToolsService.cc.o"

# External object files for target arcane_corefinement
arcane_corefinement_EXTERNAL_OBJECTS =

lib/libarcane_corefinement.so: _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/ParallelCorefinementService.cc.o
lib/libarcane_corefinement.so: _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceInternalUtils.cc.o
lib/libarcane_corefinement.so: _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceImpl.cc.o
lib/libarcane_corefinement.so: _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceToolsService.cc.o
lib/libarcane_corefinement.so: _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/build.make
lib/libarcane_corefinement.so: lib/libarcane_core.so
lib/libarcane_corefinement.so: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GeometryKernel/2013-GCC-11.2.0/lib/libGeometryKernel.so
lib/libarcane_corefinement.so: lib/libarcane_accelerator_core.so
lib/libarcane_corefinement.so: lib/libarcane_utils.so
lib/libarcane_corefinement.so: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GLib/2.70.1-GCCcore-11.2.0/lib/libglib-2.0.so
lib/libarcane_corefinement.so: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GLib/2.70.1-GCCcore-11.2.0/lib/libgthread-2.0.so
lib/libarcane_corefinement.so: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GLib/2.70.1-GCCcore-11.2.0/lib/libgmodule-2.0.so
lib/libarcane_corefinement.so: lib/libarccore_message_passing.so
lib/libarcane_corefinement.so: lib/libarccore_trace.so
lib/libarcane_corefinement.so: lib/libarccore_concurrency.so
lib/libarcane_corefinement.so: lib/libarccore_serialize.so
lib/libarcane_corefinement.so: lib/libarccore_collections.so
lib/libarcane_corefinement.so: lib/libarccore_base.so
lib/libarcane_corefinement.so: _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX shared library ../../../../../../lib/libarcane_corefinement.so"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/corefinement && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arcane_corefinement.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/build: lib/libarcane_corefinement.so
.PHONY : _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/build

_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/clean:
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/corefinement && $(CMAKE_COMMAND) -P CMakeFiles/arcane_corefinement.dir/cmake_clean.cmake
.PHONY : _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/clean

_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/depend: arcane/corefinement/ParallelCorefinement_axl.h
_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/depend: arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceTools_axl.h
	cd /work/zhaoy/Bureau/framework/build_release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/zhaoy/Bureau/framework /work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement /work/zhaoy/Bureau/framework/build_release /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/corefinement /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _common/build_all/arcane/src/arcane/corefinement/CMakeFiles/arcane_corefinement.dir/depend
