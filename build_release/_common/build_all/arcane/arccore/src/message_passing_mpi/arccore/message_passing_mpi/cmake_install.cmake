# Install script for directory: /work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/arccore/message_passing_mpi

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing_mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/arccore/message_passing_mpi/IMpiProfiling.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing_mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/arccore/message_passing_mpi/MessagePassingMpiGlobal.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing_mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/arccore/message_passing_mpi/MessagePassingMpiEnum.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing_mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/arccore/message_passing_mpi/MpiAdapter.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing_mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/arccore/message_passing_mpi/MpiLock.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing_mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/arccore/message_passing_mpi/MpiDatatype.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing_mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/arccore/message_passing_mpi/MpiControlDispatcher.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing_mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/arccore/message_passing_mpi/MpiRequest.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing_mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/arccore/message_passing_mpi/MpiRequestList.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing_mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/arccore/message_passing_mpi/MpiSerializeMessageList.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing_mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/arccore/message_passing_mpi/MpiSerializeDispatcher.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing_mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/arccore/message_passing_mpi/MpiTypeDispatcher.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing_mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/arccore/message_passing_mpi/MpiTypeDispatcherImpl.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing_mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/arccore/message_passing_mpi/MpiMessagePassingMng.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing_mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/arccore/message_passing_mpi/NoMpiProfiling.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing_mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi/arccore/message_passing_mpi/StandaloneMpiMessagePassingMng.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib/libarccore_message_passing_mpi.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib/libarccore_message_passing_mpi.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/lib/libarccore_message_passing_mpi.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/libarccore_message_passing_mpi.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/lib" TYPE SHARED_LIBRARY FILES "/work/zhaoy/Bureau/framework/build_release/lib/libarccore_message_passing_mpi.so")
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib/libarccore_message_passing_mpi.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib/libarccore_message_passing_mpi.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/local/lib/libarccore_message_passing_mpi.so"
         OLD_RPATH "/work/zhaoy/Bureau/framework/build_release/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/binutils/2.37-GCCcore-11.2.0/bin/strip" "$ENV{DESTDIR}/usr/local/lib/libarccore_message_passing_mpi.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

