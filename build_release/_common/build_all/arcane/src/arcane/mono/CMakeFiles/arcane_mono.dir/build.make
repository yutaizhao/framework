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
include _common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/compiler_depend.make

# Include the progress variables for this target.
include _common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/progress.make

# Include the compile flags for this target's objects.
include _common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/flags.make

_common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/ArcaneMono.cc.o: _common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/flags.make
_common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/ArcaneMono.cc.o: /work/zhaoy/Bureau/framework/arcane/src/arcane/mono/ArcaneMono.cc
_common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/ArcaneMono.cc.o: _common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/ArcaneMono.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mono && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/ArcaneMono.cc.o -MF CMakeFiles/arcane_mono.dir/ArcaneMono.cc.o.d -o CMakeFiles/arcane_mono.dir/ArcaneMono.cc.o -c /work/zhaoy/Bureau/framework/arcane/src/arcane/mono/ArcaneMono.cc

_common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/ArcaneMono.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/arcane_mono.dir/ArcaneMono.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mono && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/arcane/src/arcane/mono/ArcaneMono.cc > CMakeFiles/arcane_mono.dir/ArcaneMono.cc.i

_common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/ArcaneMono.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/arcane_mono.dir/ArcaneMono.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mono && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/arcane/src/arcane/mono/ArcaneMono.cc -o CMakeFiles/arcane_mono.dir/ArcaneMono.cc.s

# Object files for target arcane_mono
arcane_mono_OBJECTS = \
"CMakeFiles/arcane_mono.dir/ArcaneMono.cc.o"

# External object files for target arcane_mono
arcane_mono_EXTERNAL_OBJECTS =

lib/libarcane_mono.so: _common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/ArcaneMono.cc.o
lib/libarcane_mono.so: _common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/build.make
lib/libarcane_mono.so: lib/libarcane_utils.so
lib/libarcane_mono.so: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/Mono/6.12.0.122-GCCcore-11.2.0/lib/libmonosgen-2.0.so
lib/libarcane_mono.so: /usr/lib64/libm.so
lib/libarcane_mono.so: /usr/lib64/libpthread.a
lib/libarcane_mono.so: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GLib/2.70.1-GCCcore-11.2.0/lib/libglib-2.0.so
lib/libarcane_mono.so: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GLib/2.70.1-GCCcore-11.2.0/lib/libgthread-2.0.so
lib/libarcane_mono.so: /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GLib/2.70.1-GCCcore-11.2.0/lib/libgmodule-2.0.so
lib/libarcane_mono.so: lib/libarccore_trace.so
lib/libarcane_mono.so: lib/libarccore_concurrency.so
lib/libarcane_mono.so: lib/libarccore_collections.so
lib/libarcane_mono.so: lib/libarccore_base.so
lib/libarcane_mono.so: _common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../../../../../lib/libarcane_mono.so"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mono && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arcane_mono.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/build: lib/libarcane_mono.so
.PHONY : _common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/build

_common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/clean:
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mono && $(CMAKE_COMMAND) -P CMakeFiles/arcane_mono.dir/cmake_clean.cmake
.PHONY : _common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/clean

_common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/depend:
	cd /work/zhaoy/Bureau/framework/build_release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/zhaoy/Bureau/framework /work/zhaoy/Bureau/framework/arcane/src/arcane/mono /work/zhaoy/Bureau/framework/build_release /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mono /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _common/build_all/arcane/src/arcane/mono/CMakeFiles/arcane_mono.dir/depend
