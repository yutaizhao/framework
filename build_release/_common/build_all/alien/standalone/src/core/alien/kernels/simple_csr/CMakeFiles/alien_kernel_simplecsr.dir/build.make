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
include _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/compiler_depend.make

# Include the progress variables for this target.
include _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/progress.make

# Include the compile flags for this target's objects.
include _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/flags.make

_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/algebra/SimpleCSRInternalLinearAlgebra.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/flags.make
_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/algebra/SimpleCSRInternalLinearAlgebra.cc.o: /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/algebra/SimpleCSRInternalLinearAlgebra.cc
_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/algebra/SimpleCSRInternalLinearAlgebra.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/algebra/SimpleCSRInternalLinearAlgebra.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/algebra/SimpleCSRInternalLinearAlgebra.cc.o -MF CMakeFiles/alien_kernel_simplecsr.dir/algebra/SimpleCSRInternalLinearAlgebra.cc.o.d -o CMakeFiles/alien_kernel_simplecsr.dir/algebra/SimpleCSRInternalLinearAlgebra.cc.o -c /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/algebra/SimpleCSRInternalLinearAlgebra.cc

_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/algebra/SimpleCSRInternalLinearAlgebra.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/alien_kernel_simplecsr.dir/algebra/SimpleCSRInternalLinearAlgebra.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/algebra/SimpleCSRInternalLinearAlgebra.cc > CMakeFiles/alien_kernel_simplecsr.dir/algebra/SimpleCSRInternalLinearAlgebra.cc.i

_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/algebra/SimpleCSRInternalLinearAlgebra.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/alien_kernel_simplecsr.dir/algebra/SimpleCSRInternalLinearAlgebra.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/algebra/SimpleCSRInternalLinearAlgebra.cc -o CMakeFiles/alien_kernel_simplecsr.dir/algebra/SimpleCSRInternalLinearAlgebra.cc.s

_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/DistStructInfo.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/flags.make
_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/DistStructInfo.cc.o: /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/DistStructInfo.cc
_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/DistStructInfo.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/DistStructInfo.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/DistStructInfo.cc.o -MF CMakeFiles/alien_kernel_simplecsr.dir/DistStructInfo.cc.o.d -o CMakeFiles/alien_kernel_simplecsr.dir/DistStructInfo.cc.o -c /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/DistStructInfo.cc

_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/DistStructInfo.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/alien_kernel_simplecsr.dir/DistStructInfo.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/DistStructInfo.cc > CMakeFiles/alien_kernel_simplecsr.dir/DistStructInfo.cc.i

_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/DistStructInfo.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/alien_kernel_simplecsr.dir/DistStructInfo.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/DistStructInfo.cc -o CMakeFiles/alien_kernel_simplecsr.dir/DistStructInfo.cc.s

_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRMatrix.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/flags.make
_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRMatrix.cc.o: /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/SimpleCSRMatrix.cc
_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRMatrix.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRMatrix.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRMatrix.cc.o -MF CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRMatrix.cc.o.d -o CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRMatrix.cc.o -c /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/SimpleCSRMatrix.cc

_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRMatrix.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRMatrix.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/SimpleCSRMatrix.cc > CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRMatrix.cc.i

_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRMatrix.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRMatrix.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/SimpleCSRMatrix.cc -o CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRMatrix.cc.s

_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRVector.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/flags.make
_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRVector.cc.o: /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/SimpleCSRVector.cc
_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRVector.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRVector.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRVector.cc.o -MF CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRVector.cc.o.d -o CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRVector.cc.o -c /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/SimpleCSRVector.cc

_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRVector.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRVector.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/SimpleCSRVector.cc > CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRVector.cc.i

_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRVector.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRVector.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/SimpleCSRVector.cc -o CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRVector.cc.s

_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRDistributorImpl.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/flags.make
_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRDistributorImpl.cc.o: /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/redistribution/SimpleCSRDistributorImpl.cc
_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRDistributorImpl.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRDistributorImpl.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRDistributorImpl.cc.o -MF CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRDistributorImpl.cc.o.d -o CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRDistributorImpl.cc.o -c /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/redistribution/SimpleCSRDistributorImpl.cc

_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRDistributorImpl.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRDistributorImpl.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/redistribution/SimpleCSRDistributorImpl.cc > CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRDistributorImpl.cc.i

_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRDistributorImpl.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRDistributorImpl.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/redistribution/SimpleCSRDistributorImpl.cc -o CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRDistributorImpl.cc.s

_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRVectorRedistributor.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/flags.make
_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRVectorRedistributor.cc.o: /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/redistribution/SimpleCSRVectorRedistributor.cc
_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRVectorRedistributor.cc.o: _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/work/zhaoy/Bureau/framework/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRVectorRedistributor.cc.o"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRVectorRedistributor.cc.o -MF CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRVectorRedistributor.cc.o.d -o CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRVectorRedistributor.cc.o -c /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/redistribution/SimpleCSRVectorRedistributor.cc

_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRVectorRedistributor.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRVectorRedistributor.cc.i"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/redistribution/SimpleCSRVectorRedistributor.cc > CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRVectorRedistributor.cc.i

_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRVectorRedistributor.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRVectorRedistributor.cc.s"
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr && /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr/redistribution/SimpleCSRVectorRedistributor.cc -o CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRVectorRedistributor.cc.s

alien_kernel_simplecsr: _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/algebra/SimpleCSRInternalLinearAlgebra.cc.o
alien_kernel_simplecsr: _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/DistStructInfo.cc.o
alien_kernel_simplecsr: _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRMatrix.cc.o
alien_kernel_simplecsr: _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/SimpleCSRVector.cc.o
alien_kernel_simplecsr: _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRDistributorImpl.cc.o
alien_kernel_simplecsr: _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/redistribution/SimpleCSRVectorRedistributor.cc.o
alien_kernel_simplecsr: _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/build.make
.PHONY : alien_kernel_simplecsr

# Rule to build all files generated by this target.
_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/build: alien_kernel_simplecsr
.PHONY : _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/build

_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/clean:
	cd /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr && $(CMAKE_COMMAND) -P CMakeFiles/alien_kernel_simplecsr.dir/cmake_clean.cmake
.PHONY : _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/clean

_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/depend:
	cd /work/zhaoy/Bureau/framework/build_release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/zhaoy/Bureau/framework /work/zhaoy/Bureau/framework/alien/standalone/src/core/alien/kernels/simple_csr /work/zhaoy/Bureau/framework/build_release /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr /work/zhaoy/Bureau/framework/build_release/_common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _common/build_all/alien/standalone/src/core/alien/kernels/simple_csr/CMakeFiles/alien_kernel_simplecsr.dir/depend

