# Install script for directory: /work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/ArcaneMpi.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/IVariableSynchronizerMpiCommunicator.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiDatatypeList.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiErrorHandler.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiParallelMng.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiParallelDispatch.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiParallelNonBlockingCollective.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiParallelNonBlockingCollectiveDispatch.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiSerializeMessage.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiSerializeMessageList.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiTimerMng.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiBatchMainFactory.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/ArcaneMpi.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiDatatypeList.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiParallelMng.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiParallelDispatch.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiParallelNonBlockingCollective.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiParallelNonBlockingCollectiveDispatch.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiSerializeMessage.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiSerializeMessageList.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiTimerMng.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiBatchMainFactory.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiAdapter.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiDatatype.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiLock.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arcane/parallel/mpi" TYPE FILE FILES "/work/zhaoy/Bureau/framework/arcane/src/arcane/parallel/mpi/MpiTimeInterval.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libarcane_mpi.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libarcane_mpi.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libarcane_mpi.so"
         RPATH "\$ORIGIN:/usr/local/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/work/zhaoy/Bureau/framework/build_release/lib/libarcane_mpi.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libarcane_mpi.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libarcane_mpi.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libarcane_mpi.so"
         OLD_RPATH "/work/zhaoy/Bureau/framework/build_release/lib:"
         NEW_RPATH "\$ORIGIN:/usr/local/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/binutils/2.37-GCCcore-11.2.0/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libarcane_mpi.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/src/arcane/parallel/mpi/CMakeFiles/arcane_mpi.dir/install-cxx-module-bmi-Release.cmake" OPTIONAL)
endif()

