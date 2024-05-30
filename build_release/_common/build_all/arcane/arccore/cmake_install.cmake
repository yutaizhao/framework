# Install script for directory: /work/zhaoy/Bureau/framework/arccore

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "/work/zhaoy/Bureau/framework/build_release/arccore_version.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore" TYPE FILE FILES "/work/zhaoy/Bureau/framework/build_release/arccore/arccore_config.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Arccore" TYPE FILE FILES
    "/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/generated/ArccoreConfig.cmake"
    "/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/generated/ArccoreConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Arccore/ArccoreTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Arccore/ArccoreTargets.cmake"
         "/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/CMakeFiles/Export/17da8148432498678f8f5196ef69cea6/ArccoreTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Arccore/ArccoreTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Arccore/ArccoreTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Arccore" TYPE FILE FILES "/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/CMakeFiles/Export/17da8148432498678f8f5196ef69cea6/ArccoreTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Arccore" TYPE FILE FILES "/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/CMakeFiles/Export/17da8148432498678f8f5196ef69cea6/ArccoreTargets-release.cmake")
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/base/arccore/base/cmake_install.cmake")
  include("/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/base/tests/cmake_install.cmake")
  include("/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/collections/arccore/collections/cmake_install.cmake")
  include("/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/collections/tests/cmake_install.cmake")
  include("/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/concurrency/arccore/concurrency/cmake_install.cmake")
  include("/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/concurrency/tests/cmake_install.cmake")
  include("/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/trace/arccore/trace/cmake_install.cmake")
  include("/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/trace/tests/cmake_install.cmake")
  include("/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/serialize/arccore/serialize/cmake_install.cmake")
  include("/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/serialize/tests/cmake_install.cmake")
  include("/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/message_passing/arccore/message_passing/cmake_install.cmake")
  include("/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/message_passing/tests/cmake_install.cmake")
  include("/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/message_passing_mpi/arccore/message_passing_mpi/cmake_install.cmake")
  include("/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/arccore/src/message_passing_mpi/tests/cmake_install.cmake")

endif()

