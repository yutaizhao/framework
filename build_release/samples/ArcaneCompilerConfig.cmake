# Indique qu'on veut des bibliothèques dynamiques (indispensable avec les services)
set(BUILD_SHARED_LIBS TRUE)
set(Arcane_ROOT "/usr/local" CACHE PATH "Arcane cmake root path" FORCE)
set(CMAKE_VERBOSE_MAKEFILE TRUE CACHE BOOL "Verbose makefile?" FORCE)
set(CMAKE_C_COMPILER "/soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/cc" CACHE PATH "C Compiler" FORCE)
set(CMAKE_CXX_COMPILER "/soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++" CACHE PATH "C++ Compiler" FORCE)
set(CMAKE_CUDA_HOST_COMPILER "/soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++" CACHE PATH "CUDA Host Compiler" FORCE)
set(CMAKE_HIP_HOST_COMPILER "/soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/GCCcore/11.2.0/bin/c++" CACHE PATH "HIP Host Compiler" FORCE)
set(CMAKE_CXX_FLAGS_INIT "  " CACHE STRING "Default flags for C++ compiler" FORCE)
set(CMAKE_EXE_LINKER_FLAGS "" CACHE STRING "Default flags for linker" FORCE)
set(CMAKE_SHARED_LINKER_FLAGS "" CACHE STRING "Default flags for linker" FORCE)

# ----------------------------------------------------------------------------
# Local Variables:
# tab-width: 2
# indent-tabs-mode: nil
# coding: utf-8
# End:
