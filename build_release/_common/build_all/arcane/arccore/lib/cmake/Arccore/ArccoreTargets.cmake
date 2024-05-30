# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.8)
   message(FATAL_ERROR "CMake >= 2.8.0 required")
endif()
if(CMAKE_VERSION VERSION_LESS "2.8.3")
   message(FATAL_ERROR "CMake >= 2.8.3 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.8.3...3.26)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

if(CMAKE_VERSION VERSION_LESS 3.0.0)
  message(FATAL_ERROR "This file relies on consumers using CMake 3.0.0 or greater.")
endif()

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_cmake_targets_defined "")
set(_cmake_targets_not_defined "")
set(_cmake_expected_targets "")
foreach(_cmake_expected_target IN ITEMS arccore_build_compile_flags arccore_full arccore_base arccore_collections arccore_concurrency arccore_trace arccore_serialize arccore_message_passing arccore_message_passing_mpi)
  list(APPEND _cmake_expected_targets "${_cmake_expected_target}")
  if(TARGET "${_cmake_expected_target}")
    list(APPEND _cmake_targets_defined "${_cmake_expected_target}")
  else()
    list(APPEND _cmake_targets_not_defined "${_cmake_expected_target}")
  endif()
endforeach()
unset(_cmake_expected_target)
if(_cmake_targets_defined STREQUAL _cmake_expected_targets)
  unset(_cmake_targets_defined)
  unset(_cmake_targets_not_defined)
  unset(_cmake_expected_targets)
  unset(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT _cmake_targets_defined STREQUAL "")
  string(REPLACE ";" ", " _cmake_targets_defined_text "${_cmake_targets_defined}")
  string(REPLACE ";" ", " _cmake_targets_not_defined_text "${_cmake_targets_not_defined}")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_cmake_targets_defined_text}\nTargets not yet defined: ${_cmake_targets_not_defined_text}\n")
endif()
unset(_cmake_targets_defined)
unset(_cmake_targets_not_defined)
unset(_cmake_expected_targets)


# Create imported target arccore_build_compile_flags
add_library(arccore_build_compile_flags INTERFACE IMPORTED)

set_target_properties(arccore_build_compile_flags PROPERTIES
  INTERFACE_COMPILE_OPTIONS "-g;-fvisibility-inlines-hidden;-fvisibility=hidden;-Wconversion;-Wno-sign-conversion;\$<\$<COMPILE_LANGUAGE:CXX>:-Wpedantic>;-Wextra;-fdiagnostics-color=always"
)

# Create imported target arccore_full
add_library(arccore_full INTERFACE IMPORTED)

set_target_properties(arccore_full PROPERTIES
  INTERFACE_LINK_LIBRARIES "arccore_base;arccore_collections;arccore_concurrency;arccore_trace;arccore_serialize;arccore_message_passing;arccore_message_passing_mpi"
)

# Create imported target arccore_base
add_library(arccore_base SHARED IMPORTED)

set_target_properties(arccore_base PROPERTIES
  INTERFACE_COMPILE_FEATURES "cxx_std_17"
  INTERFACE_INCLUDE_DIRECTORIES "/work/zhaoy/Bureau/framework/arccore/src/base;/work/zhaoy/Bureau/framework/build_release"
  INTERFACE_LINK_LIBRARIES "arccore_build_compile_flags"
)

# Create imported target arccore_collections
add_library(arccore_collections SHARED IMPORTED)

set_target_properties(arccore_collections PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/work/zhaoy/Bureau/framework/arccore/src/collections"
  INTERFACE_LINK_LIBRARIES "arccore_base"
)

# Create imported target arccore_concurrency
add_library(arccore_concurrency SHARED IMPORTED)

set_target_properties(arccore_concurrency PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/work/zhaoy/Bureau/framework/arccore/src/concurrency"
  INTERFACE_LINK_LIBRARIES "arccore_base"
)

# Create imported target arccore_trace
add_library(arccore_trace SHARED IMPORTED)

set_target_properties(arccore_trace PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/work/zhaoy/Bureau/framework/arccore/src/trace"
  INTERFACE_LINK_LIBRARIES "arccore_base"
)

# Create imported target arccore_serialize
add_library(arccore_serialize SHARED IMPORTED)

set_target_properties(arccore_serialize PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/work/zhaoy/Bureau/framework/arccore/src/serialize"
  INTERFACE_LINK_LIBRARIES "arccore_collections;arccore_base"
)

# Create imported target arccore_message_passing
add_library(arccore_message_passing SHARED IMPORTED)

set_target_properties(arccore_message_passing PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/work/zhaoy/Bureau/framework/arccore/src/message_passing"
  INTERFACE_LINK_LIBRARIES "arccore_serialize;arccore_collections;arccore_trace;arccore_base"
)

# Create imported target arccore_message_passing_mpi
add_library(arccore_message_passing_mpi SHARED IMPORTED)

set_target_properties(arccore_message_passing_mpi PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/work/zhaoy/Bureau/framework/arccore/src/message_passing_mpi"
  INTERFACE_LINK_LIBRARIES "arccore_trace;arccore_message_passing;arccore_collections;arccore_concurrency;arcconpkg_MPI"
)

# Import target "arccore_base" for configuration "Release"
set_property(TARGET arccore_base APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(arccore_base PROPERTIES
  IMPORTED_LOCATION_RELEASE "/work/zhaoy/Bureau/framework/build_release/lib/libarccore_base.so"
  IMPORTED_SONAME_RELEASE "libarccore_base.so"
  )

# Import target "arccore_collections" for configuration "Release"
set_property(TARGET arccore_collections APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(arccore_collections PROPERTIES
  IMPORTED_LOCATION_RELEASE "/work/zhaoy/Bureau/framework/build_release/lib/libarccore_collections.so"
  IMPORTED_SONAME_RELEASE "libarccore_collections.so"
  )

# Import target "arccore_concurrency" for configuration "Release"
set_property(TARGET arccore_concurrency APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(arccore_concurrency PROPERTIES
  IMPORTED_LOCATION_RELEASE "/work/zhaoy/Bureau/framework/build_release/lib/libarccore_concurrency.so"
  IMPORTED_SONAME_RELEASE "libarccore_concurrency.so"
  )

# Import target "arccore_trace" for configuration "Release"
set_property(TARGET arccore_trace APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(arccore_trace PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "arccore_concurrency"
  IMPORTED_LOCATION_RELEASE "/work/zhaoy/Bureau/framework/build_release/lib/libarccore_trace.so"
  IMPORTED_SONAME_RELEASE "libarccore_trace.so"
  )

# Import target "arccore_serialize" for configuration "Release"
set_property(TARGET arccore_serialize APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(arccore_serialize PROPERTIES
  IMPORTED_LOCATION_RELEASE "/work/zhaoy/Bureau/framework/build_release/lib/libarccore_serialize.so"
  IMPORTED_SONAME_RELEASE "libarccore_serialize.so"
  )

# Import target "arccore_message_passing" for configuration "Release"
set_property(TARGET arccore_message_passing APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(arccore_message_passing PROPERTIES
  IMPORTED_LOCATION_RELEASE "/work/zhaoy/Bureau/framework/build_release/lib/libarccore_message_passing.so"
  IMPORTED_SONAME_RELEASE "libarccore_message_passing.so"
  )

# Import target "arccore_message_passing_mpi" for configuration "Release"
set_property(TARGET arccore_message_passing_mpi APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(arccore_message_passing_mpi PROPERTIES
  IMPORTED_LOCATION_RELEASE "/work/zhaoy/Bureau/framework/build_release/lib/libarccore_message_passing_mpi.so"
  IMPORTED_SONAME_RELEASE "libarccore_message_passing_mpi.so"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)