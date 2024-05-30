#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Alien::alien_core" for configuration "Release"
set_property(TARGET Alien::alien_core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Alien::alien_core PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libalien_core.so"
  IMPORTED_SONAME_RELEASE "libalien_core.so"
  )

list(APPEND _cmake_import_check_targets Alien::alien_core )
list(APPEND _cmake_import_check_files_for_Alien::alien_core "${_IMPORT_PREFIX}/lib/libalien_core.so" )

# Import target "Alien::alien_semantic_ref" for configuration "Release"
set_property(TARGET Alien::alien_semantic_ref APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Alien::alien_semantic_ref PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libalien_semantic_ref.so"
  IMPORTED_SONAME_RELEASE "libalien_semantic_ref.so"
  )

list(APPEND _cmake_import_check_targets Alien::alien_semantic_ref )
list(APPEND _cmake_import_check_files_for_Alien::alien_semantic_ref "${_IMPORT_PREFIX}/lib/libalien_semantic_ref.so" )

# Import target "Alien::alien_semantic_move" for configuration "Release"
set_property(TARGET Alien::alien_semantic_move APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Alien::alien_semantic_move PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libalien_semantic_move.so"
  IMPORTED_SONAME_RELEASE "libalien_semantic_move.so"
  )

list(APPEND _cmake_import_check_targets Alien::alien_semantic_move )
list(APPEND _cmake_import_check_files_for_Alien::alien_semantic_move "${_IMPORT_PREFIX}/lib/libalien_semantic_move.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
