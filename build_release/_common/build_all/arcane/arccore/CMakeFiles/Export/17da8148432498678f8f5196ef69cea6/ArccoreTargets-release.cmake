#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Arccore::arccore_base" for configuration "Release"
set_property(TARGET Arccore::arccore_base APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arccore::arccore_base PROPERTIES
  IMPORTED_LOCATION_RELEASE "/usr/local/lib/libarccore_base.so"
  IMPORTED_SONAME_RELEASE "libarccore_base.so"
  )

list(APPEND _cmake_import_check_targets Arccore::arccore_base )
list(APPEND _cmake_import_check_files_for_Arccore::arccore_base "/usr/local/lib/libarccore_base.so" )

# Import target "Arccore::arccore_collections" for configuration "Release"
set_property(TARGET Arccore::arccore_collections APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arccore::arccore_collections PROPERTIES
  IMPORTED_LOCATION_RELEASE "/usr/local/lib/libarccore_collections.so"
  IMPORTED_SONAME_RELEASE "libarccore_collections.so"
  )

list(APPEND _cmake_import_check_targets Arccore::arccore_collections )
list(APPEND _cmake_import_check_files_for_Arccore::arccore_collections "/usr/local/lib/libarccore_collections.so" )

# Import target "Arccore::arccore_concurrency" for configuration "Release"
set_property(TARGET Arccore::arccore_concurrency APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arccore::arccore_concurrency PROPERTIES
  IMPORTED_LOCATION_RELEASE "/usr/local/lib/libarccore_concurrency.so"
  IMPORTED_SONAME_RELEASE "libarccore_concurrency.so"
  )

list(APPEND _cmake_import_check_targets Arccore::arccore_concurrency )
list(APPEND _cmake_import_check_files_for_Arccore::arccore_concurrency "/usr/local/lib/libarccore_concurrency.so" )

# Import target "Arccore::arccore_trace" for configuration "Release"
set_property(TARGET Arccore::arccore_trace APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arccore::arccore_trace PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Arccore::arccore_concurrency"
  IMPORTED_LOCATION_RELEASE "/usr/local/lib/libarccore_trace.so"
  IMPORTED_SONAME_RELEASE "libarccore_trace.so"
  )

list(APPEND _cmake_import_check_targets Arccore::arccore_trace )
list(APPEND _cmake_import_check_files_for_Arccore::arccore_trace "/usr/local/lib/libarccore_trace.so" )

# Import target "Arccore::arccore_serialize" for configuration "Release"
set_property(TARGET Arccore::arccore_serialize APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arccore::arccore_serialize PROPERTIES
  IMPORTED_LOCATION_RELEASE "/usr/local/lib/libarccore_serialize.so"
  IMPORTED_SONAME_RELEASE "libarccore_serialize.so"
  )

list(APPEND _cmake_import_check_targets Arccore::arccore_serialize )
list(APPEND _cmake_import_check_files_for_Arccore::arccore_serialize "/usr/local/lib/libarccore_serialize.so" )

# Import target "Arccore::arccore_message_passing" for configuration "Release"
set_property(TARGET Arccore::arccore_message_passing APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arccore::arccore_message_passing PROPERTIES
  IMPORTED_LOCATION_RELEASE "/usr/local/lib/libarccore_message_passing.so"
  IMPORTED_SONAME_RELEASE "libarccore_message_passing.so"
  )

list(APPEND _cmake_import_check_targets Arccore::arccore_message_passing )
list(APPEND _cmake_import_check_files_for_Arccore::arccore_message_passing "/usr/local/lib/libarccore_message_passing.so" )

# Import target "Arccore::arccore_message_passing_mpi" for configuration "Release"
set_property(TARGET Arccore::arccore_message_passing_mpi APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arccore::arccore_message_passing_mpi PROPERTIES
  IMPORTED_LOCATION_RELEASE "/usr/local/lib/libarccore_message_passing_mpi.so"
  IMPORTED_SONAME_RELEASE "libarccore_message_passing_mpi.so"
  )

list(APPEND _cmake_import_check_targets Arccore::arccore_message_passing_mpi )
list(APPEND _cmake_import_check_files_for_Arccore::arccore_message_passing_mpi "/usr/local/lib/libarccore_message_passing_mpi.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
