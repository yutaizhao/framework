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
include _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/compiler_depend.make

# Include the progress variables for this target.
include _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/progress.make

# Include the compile flags for this target's objects.
include _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/flags.make

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/converters/to_simple_csr_vector.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/flags.make
_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/converters/to_simple_csr_vector.cc.o: /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/converters/to_simple_csr_vector.cc
_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/converters/to_simple_csr_vector.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/converters/to_simple_csr_vector.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/converters/to_simple_csr_vector.cc.o -MF CMakeFiles/alien_kernel_composite.dir/converters/to_simple_csr_vector.cc.o.d -o CMakeFiles/alien_kernel_composite.dir/converters/to_simple_csr_vector.cc.o -c /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/converters/to_simple_csr_vector.cc

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/converters/to_simple_csr_vector.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/alien_kernel_composite.dir/converters/to_simple_csr_vector.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/converters/to_simple_csr_vector.cc > CMakeFiles/alien_kernel_composite.dir/converters/to_simple_csr_vector.cc.i

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/converters/to_simple_csr_vector.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/alien_kernel_composite.dir/converters/to_simple_csr_vector.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/converters/to_simple_csr_vector.cc -o CMakeFiles/alien_kernel_composite.dir/converters/to_simple_csr_vector.cc.s

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMatrix.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/flags.make
_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMatrix.cc.o: /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeMatrix.cc
_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMatrix.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMatrix.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMatrix.cc.o -MF CMakeFiles/alien_kernel_composite.dir/CompositeMatrix.cc.o.d -o CMakeFiles/alien_kernel_composite.dir/CompositeMatrix.cc.o -c /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeMatrix.cc

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMatrix.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/alien_kernel_composite.dir/CompositeMatrix.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeMatrix.cc > CMakeFiles/alien_kernel_composite.dir/CompositeMatrix.cc.i

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMatrix.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/alien_kernel_composite.dir/CompositeMatrix.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeMatrix.cc -o CMakeFiles/alien_kernel_composite.dir/CompositeMatrix.cc.s

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMatrixElement.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/flags.make
_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMatrixElement.cc.o: /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeMatrixElement.cc
_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMatrixElement.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMatrixElement.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMatrixElement.cc.o -MF CMakeFiles/alien_kernel_composite.dir/CompositeMatrixElement.cc.o.d -o CMakeFiles/alien_kernel_composite.dir/CompositeMatrixElement.cc.o -c /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeMatrixElement.cc

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMatrixElement.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/alien_kernel_composite.dir/CompositeMatrixElement.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeMatrixElement.cc > CMakeFiles/alien_kernel_composite.dir/CompositeMatrixElement.cc.i

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMatrixElement.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/alien_kernel_composite.dir/CompositeMatrixElement.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeMatrixElement.cc -o CMakeFiles/alien_kernel_composite.dir/CompositeMatrixElement.cc.s

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMultiMatrixImpl.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/flags.make
_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMultiMatrixImpl.cc.o: /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeMultiMatrixImpl.cc
_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMultiMatrixImpl.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMultiMatrixImpl.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMultiMatrixImpl.cc.o -MF CMakeFiles/alien_kernel_composite.dir/CompositeMultiMatrixImpl.cc.o.d -o CMakeFiles/alien_kernel_composite.dir/CompositeMultiMatrixImpl.cc.o -c /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeMultiMatrixImpl.cc

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMultiMatrixImpl.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/alien_kernel_composite.dir/CompositeMultiMatrixImpl.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeMultiMatrixImpl.cc > CMakeFiles/alien_kernel_composite.dir/CompositeMultiMatrixImpl.cc.i

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMultiMatrixImpl.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/alien_kernel_composite.dir/CompositeMultiMatrixImpl.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeMultiMatrixImpl.cc -o CMakeFiles/alien_kernel_composite.dir/CompositeMultiMatrixImpl.cc.s

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMultiVectorImpl.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/flags.make
_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMultiVectorImpl.cc.o: /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeMultiVectorImpl.cc
_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMultiVectorImpl.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMultiVectorImpl.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMultiVectorImpl.cc.o -MF CMakeFiles/alien_kernel_composite.dir/CompositeMultiVectorImpl.cc.o.d -o CMakeFiles/alien_kernel_composite.dir/CompositeMultiVectorImpl.cc.o -c /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeMultiVectorImpl.cc

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMultiVectorImpl.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/alien_kernel_composite.dir/CompositeMultiVectorImpl.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeMultiVectorImpl.cc > CMakeFiles/alien_kernel_composite.dir/CompositeMultiVectorImpl.cc.i

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMultiVectorImpl.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/alien_kernel_composite.dir/CompositeMultiVectorImpl.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeMultiVectorImpl.cc -o CMakeFiles/alien_kernel_composite.dir/CompositeMultiVectorImpl.cc.s

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeSpace.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/flags.make
_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeSpace.cc.o: /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeSpace.cc
_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeSpace.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeSpace.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeSpace.cc.o -MF CMakeFiles/alien_kernel_composite.dir/CompositeSpace.cc.o.d -o CMakeFiles/alien_kernel_composite.dir/CompositeSpace.cc.o -c /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeSpace.cc

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeSpace.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/alien_kernel_composite.dir/CompositeSpace.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeSpace.cc > CMakeFiles/alien_kernel_composite.dir/CompositeSpace.cc.i

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeSpace.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/alien_kernel_composite.dir/CompositeSpace.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeSpace.cc -o CMakeFiles/alien_kernel_composite.dir/CompositeSpace.cc.s

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeVector.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/flags.make
_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeVector.cc.o: /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeVector.cc
_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeVector.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeVector.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeVector.cc.o -MF CMakeFiles/alien_kernel_composite.dir/CompositeVector.cc.o.d -o CMakeFiles/alien_kernel_composite.dir/CompositeVector.cc.o -c /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeVector.cc

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeVector.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/alien_kernel_composite.dir/CompositeVector.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeVector.cc > CMakeFiles/alien_kernel_composite.dir/CompositeVector.cc.i

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeVector.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/alien_kernel_composite.dir/CompositeVector.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeVector.cc -o CMakeFiles/alien_kernel_composite.dir/CompositeVector.cc.s

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeVectorElement.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/flags.make
_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeVectorElement.cc.o: /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeVectorElement.cc
_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeVectorElement.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeVectorElement.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeVectorElement.cc.o -MF CMakeFiles/alien_kernel_composite.dir/CompositeVectorElement.cc.o.d -o CMakeFiles/alien_kernel_composite.dir/CompositeVectorElement.cc.o -c /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeVectorElement.cc

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeVectorElement.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/alien_kernel_composite.dir/CompositeVectorElement.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeVectorElement.cc > CMakeFiles/alien_kernel_composite.dir/CompositeVectorElement.cc.i

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeVectorElement.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/alien_kernel_composite.dir/CompositeVectorElement.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite/CompositeVectorElement.cc -o CMakeFiles/alien_kernel_composite.dir/CompositeVectorElement.cc.s

alien_kernel_composite: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/converters/to_simple_csr_vector.cc.o
alien_kernel_composite: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMatrix.cc.o
alien_kernel_composite: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMatrixElement.cc.o
alien_kernel_composite: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMultiMatrixImpl.cc.o
alien_kernel_composite: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeMultiVectorImpl.cc.o
alien_kernel_composite: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeSpace.cc.o
alien_kernel_composite: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeVector.cc.o
alien_kernel_composite: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/CompositeVectorElement.cc.o
alien_kernel_composite: _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/build.make
.PHONY : alien_kernel_composite

# Rule to build all files generated by this target.
_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/build: alien_kernel_composite
.PHONY : _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/build

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/clean:
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite && $(CMAKE_COMMAND) -P CMakeFiles/alien_kernel_composite.dir/cmake_clean.cmake
.PHONY : _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/clean

_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/depend:
	cd /work/zhaoy/Bureau/framework/build_release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/zhaoy/Bureau/framework /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/composite /work/zhaoy/Bureau/framework/build_release /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _common/build_all/alien/standalone/src/core/alien/kernels/composite/CMakeFiles/alien_kernel_composite.dir/depend

