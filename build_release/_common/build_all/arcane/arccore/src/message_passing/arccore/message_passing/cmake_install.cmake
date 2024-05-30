# Install script for directory: /work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/BasicSerializeMessage.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/MessagePassingGlobal.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/Communicator.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/Dispatchers.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/GatherMessageInfo.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/MessageId.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/MessageTag.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/MessageRank.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/MessageSourceInfo.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/PointToPointMessageInfo.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/PointToPointSerializerMng.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/Request.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/IRequestList.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/ISerializeMessage.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/ISerializeDispatcher.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/RequestListBase.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/ISerializeMessageList.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/IStat.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/IDispatchers.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/ITypeDispatcher.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/IControlDispatcher.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/IProfiler.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/IMessagePassingMng.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/MessagePassingMng.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/Messages.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/Stat.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arccore/message_passing" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arccore/src/message_passing/arccore/message_passing/SerializeMessageList.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib/libarccore_message_passing.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib/libarccore_message_passing.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/lib/libarccore_message_passing.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/libarccore_message_passing.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/lib" TYPE SHARED_LIBRARY FILES "/work/zhaoy/Bureau/framework/build_release/lib/libarccore_message_passing.so")
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib/libarccore_message_passing.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib/libarccore_message_passing.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/local/lib/libarccore_message_passing.so"
         OLD_RPATH "/work/zhaoy/Bureau/framework/build_release/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/binutils/2.37-GCCcore-11.2.0/bin/strip" "$ENV{DESTDIR}/usr/local/lib/libarccore_message_passing.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

