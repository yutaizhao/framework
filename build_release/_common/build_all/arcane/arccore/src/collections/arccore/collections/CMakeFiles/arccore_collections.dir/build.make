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
include _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/compiler_depend.make

# Include the progress variables for this target.
include _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/progress.make

# Include the compile flags for this target's objects.
include _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/flags.make

_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/Array.cc.o: _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/flags.make
_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/Array.cc.o: /work/zhaoy/Bureau/framework/arccore/src/collections/arccore/collections/Array.cc
_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/Array.cc.o: _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/Array.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/collections/arccore/collections && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/Array.cc.o -MF CMakeFiles/arccore_collections.dir/Array.cc.o.d -o CMakeFiles/arccore_collections.dir/Array.cc.o -c /work/zhaoy/Bureau/framework/arccore/src/collections/arccore/collections/Array.cc

_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/Array.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/arccore_collections.dir/Array.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/collections/arccore/collections && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/arccore/src/collections/arccore/collections/Array.cc > CMakeFiles/arccore_collections.dir/Array.cc.i

_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/Array.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/arccore_collections.dir/Array.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/collections/arccore/collections && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/arccore/src/collections/arccore/collections/Array.cc -o CMakeFiles/arccore_collections.dir/Array.cc.s

_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/Array2.cc.o: _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/flags.make
_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/Array2.cc.o: /work/zhaoy/Bureau/framework/arccore/src/collections/arccore/collections/Array2.cc
_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/Array2.cc.o: _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/Array2.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/collections/arccore/collections && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/Array2.cc.o -MF CMakeFiles/arccore_collections.dir/Array2.cc.o.d -o CMakeFiles/arccore_collections.dir/Array2.cc.o -c /work/zhaoy/Bureau/framework/arccore/src/collections/arccore/collections/Array2.cc

_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/Array2.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/arccore_collections.dir/Array2.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/collections/arccore/collections && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/arccore/src/collections/arccore/collections/Array2.cc > CMakeFiles/arccore_collections.dir/Array2.cc.i

_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/Array2.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/arccore_collections.dir/Array2.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/collections/arccore/collections && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/arccore/src/collections/arccore/collections/Array2.cc -o CMakeFiles/arccore_collections.dir/Array2.cc.s

_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/MemoryAllocationOptions.cc.o: _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/flags.make
_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/MemoryAllocationOptions.cc.o: /work/zhaoy/Bureau/framework/arccore/src/collections/arccore/collections/MemoryAllocationOptions.cc
_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/MemoryAllocationOptions.cc.o: _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/MemoryAllocationOptions.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/collections/arccore/collections && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/MemoryAllocationOptions.cc.o -MF CMakeFiles/arccore_collections.dir/MemoryAllocationOptions.cc.o.d -o CMakeFiles/arccore_collections.dir/MemoryAllocationOptions.cc.o -c /work/zhaoy/Bureau/framework/arccore/src/collections/arccore/collections/MemoryAllocationOptions.cc

_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/MemoryAllocationOptions.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/arccore_collections.dir/MemoryAllocationOptions.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/collections/arccore/collections && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/arccore/src/collections/arccore/collections/MemoryAllocationOptions.cc > CMakeFiles/arccore_collections.dir/MemoryAllocationOptions.cc.i

_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/MemoryAllocationOptions.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/arccore_collections.dir/MemoryAllocationOptions.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/collections/arccore/collections && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/arccore/src/collections/arccore/collections/MemoryAllocationOptions.cc -o CMakeFiles/arccore_collections.dir/MemoryAllocationOptions.cc.s

_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/MemoryAllocator.cc.o: _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/flags.make
_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/MemoryAllocator.cc.o: /work/zhaoy/Bureau/framework/arccore/src/collections/arccore/collections/MemoryAllocator.cc
_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/MemoryAllocator.cc.o: _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/MemoryAllocator.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/collections/arccore/collections && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/MemoryAllocator.cc.o -MF CMakeFiles/arccore_collections.dir/MemoryAllocator.cc.o.d -o CMakeFiles/arccore_collections.dir/MemoryAllocator.cc.o -c /work/zhaoy/Bureau/framework/arccore/src/collections/arccore/collections/MemoryAllocator.cc

_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/MemoryAllocator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/arccore_collections.dir/MemoryAllocator.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/collections/arccore/collections && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/arccore/src/collections/arccore/collections/MemoryAllocator.cc > CMakeFiles/arccore_collections.dir/MemoryAllocator.cc.i

_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/MemoryAllocator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/arccore_collections.dir/MemoryAllocator.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/collections/arccore/collections && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/arccore/src/collections/arccore/collections/MemoryAllocator.cc -o CMakeFiles/arccore_collections.dir/MemoryAllocator.cc.s

# Object files for target arccore_collections
arccore_collections_OBJECTS = \
"CMakeFiles/arccore_collections.dir/Array.cc.o" \
"CMakeFiles/arccore_collections.dir/Array2.cc.o" \
"CMakeFiles/arccore_collections.dir/MemoryAllocationOptions.cc.o" \
"CMakeFiles/arccore_collections.dir/MemoryAllocator.cc.o"

# External object files for target arccore_collections
arccore_collections_EXTERNAL_OBJECTS =

lib/libarccore_collections.so: _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/Array.cc.o
lib/libarccore_collections.so: _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/Array2.cc.o
lib/libarccore_collections.so: _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/MemoryAllocationOptions.cc.o
lib/libarccore_collections.so: _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/MemoryAllocator.cc.o
lib/libarccore_collections.so: _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/build.make
lib/libarccore_collections.so: lib/libarccore_base.so
lib/libarccore_collections.so: _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX shared library ../../../../../../../../lib/libarccore_collections.so"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/collections/arccore/collections && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arccore_collections.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/build: lib/libarccore_collections.so
.PHONY : _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/build

_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/clean:
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/collections/arccore/collections && $(CMAKE_COMMAND) -P CMakeFiles/arccore_collections.dir/cmake_clean.cmake
.PHONY : _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/clean

_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/depend:
	cd /work/zhaoy/Bureau/framework/build_release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/zhaoy/Bureau/framework /work/zhaoy/Bureau/framework/arccore/src/collections/arccore/collections /work/zhaoy/Bureau/framework/build_release /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/collections/arccore/collections /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _common/build_all/arcane/arccore/src/collections/arccore/collections/CMakeFiles/arccore_collections.dir/depend
