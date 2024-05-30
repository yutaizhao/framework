# Install script for directory: /work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/binutils/2.37-GCCcore-11.2.0/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/corefinement" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/ParallelCorefinementService.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/corefinement" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/ParallelCorefinementService.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/corefinement" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/IParallelCorefinement.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/corefinement/surfaceutils" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/surfaceutils/ISurfaceUtils.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/corefinement/surfaceutils" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/surfaceutils/ISurface.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/corefinement/surfaceutils/geometrykernelsurfacetools" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceInternalUtils.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/corefinement/surfaceutils/geometrykernelsurfacetools" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceImpl.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/corefinement/surfaceutils/geometrykernelsurfacetools" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceToolsService.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/corefinement/surfaceutils/geometrykernelsurfacetools" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceInternalUtils.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/corefinement/surfaceutils/geometrykernelsurfacetools" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceImpl.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/corefinement/surfaceutils/geometrykernelsurfacetools" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/corefinement/surfaceutils/geometrykernelsurfacetools/GeometryKernelSurfaceToolsService.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/axl" TYPE FILE FILES "/work/zhaoy/Bureau/framework/build_release/share/axl/ParallelCorefinement_arcane_corefinement.axl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/axl" TYPE FILE FILES "/work/zhaoy/Bureau/framework/build_release/share/axl/GeometryKernelSurfaceTools_arcane_corefinement_surfaceutils_geometrykernelsurfacetools.axl")
endif()

