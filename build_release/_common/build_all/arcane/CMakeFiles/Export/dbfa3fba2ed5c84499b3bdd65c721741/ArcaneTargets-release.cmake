#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Arcane::arcane_ios" for configuration "Release"
set_property(TARGET Arcane::arcane_ios APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_ios PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_ios.so"
  IMPORTED_SONAME_RELEASE "libarcane_ios.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_ios )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_ios "${_IMPORT_PREFIX}/lib/libarcane_ios.so" )

# Import target "Arcane::arcane_mono" for configuration "Release"
set_property(TARGET Arcane::arcane_mono APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_mono PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Arcane::arcane_utils"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_mono.so"
  IMPORTED_SONAME_RELEASE "libarcane_mono.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_mono )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_mono "${_IMPORT_PREFIX}/lib/libarcane_mono.so" )

# Import target "Arcane::arcane_dotnet_coreclr" for configuration "Release"
set_property(TARGET Arcane::arcane_dotnet_coreclr APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_dotnet_coreclr PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Arcane::arcane_core;Arcane::arcane_utils"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_dotnet_coreclr.so"
  IMPORTED_SONAME_RELEASE "libarcane_dotnet_coreclr.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_dotnet_coreclr )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_dotnet_coreclr "${_IMPORT_PREFIX}/lib/libarcane_dotnet_coreclr.so" )

# Import target "Arcane::arcane_mpi" for configuration "Release"
set_property(TARGET Arcane::arcane_mpi APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_mpi PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_mpi.so"
  IMPORTED_SONAME_RELEASE "libarcane_mpi.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_mpi )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_mpi "${_IMPORT_PREFIX}/lib/libarcane_mpi.so" )

# Import target "Arcane::arcane_thread" for configuration "Release"
set_property(TARGET Arcane::arcane_thread APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_thread PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "TBB::tbb"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_thread.so"
  IMPORTED_SONAME_RELEASE "libarcane_thread.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_thread )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_thread "${_IMPORT_PREFIX}/lib/libarcane_thread.so" )

# Import target "Arcane::arcane_mpithread" for configuration "Release"
set_property(TARGET Arcane::arcane_mpithread APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_mpithread PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_mpithread.so"
  IMPORTED_SONAME_RELEASE "libarcane_mpithread.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_mpithread )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_mpithread "${_IMPORT_PREFIX}/lib/libarcane_mpithread.so" )

# Import target "Arcane::arcane_utils" for configuration "Release"
set_property(TARGET Arcane::arcane_utils APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_utils PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_utils.so"
  IMPORTED_SONAME_RELEASE "libarcane_utils.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_utils )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_utils "${_IMPORT_PREFIX}/lib/libarcane_utils.so" )

# Import target "Arcane::arcane_impl" for configuration "Release"
set_property(TARGET Arcane::arcane_impl APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_impl PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_impl.so"
  IMPORTED_SONAME_RELEASE "libarcane_impl.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_impl )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_impl "${_IMPORT_PREFIX}/lib/libarcane_impl.so" )

# Import target "Arcane::arcane_mesh" for configuration "Release"
set_property(TARGET Arcane::arcane_mesh APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_mesh PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Neo::Neo"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_mesh.so"
  IMPORTED_SONAME_RELEASE "libarcane_mesh.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_mesh )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_mesh "${_IMPORT_PREFIX}/lib/libarcane_mesh.so" )

# Import target "Arcane::arcane_launcher" for configuration "Release"
set_property(TARGET Arcane::arcane_launcher APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_launcher PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_launcher.so"
  IMPORTED_SONAME_RELEASE "libarcane_launcher.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_launcher )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_launcher "${_IMPORT_PREFIX}/lib/libarcane_launcher.so" )

# Import target "Arcane::arcane_core" for configuration "Release"
set_property(TARGET Arcane::arcane_core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_core PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_core.so"
  IMPORTED_SONAME_RELEASE "libarcane_core.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_core )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_core "${_IMPORT_PREFIX}/lib/libarcane_core.so" )

# Import target "Arcane::arcane_geometry" for configuration "Release"
set_property(TARGET Arcane::arcane_geometry APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_geometry PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_geometry.so"
  IMPORTED_SONAME_RELEASE "libarcane_geometry.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_geometry )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_geometry "${_IMPORT_PREFIX}/lib/libarcane_geometry.so" )

# Import target "Arcane::arcane_totalview" for configuration "Release"
set_property(TARGET Arcane::arcane_totalview APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_totalview PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_totalview.so"
  IMPORTED_SONAME_RELEASE "libarcane_totalview.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_totalview )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_totalview "${_IMPORT_PREFIX}/lib/libarcane_totalview.so" )

# Import target "Arcane::arcane_hdf5" for configuration "Release"
set_property(TARGET Arcane::arcane_hdf5 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_hdf5 PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_hdf5.so"
  IMPORTED_SONAME_RELEASE "libarcane_hdf5.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_hdf5 )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_hdf5 "${_IMPORT_PREFIX}/lib/libarcane_hdf5.so" )

# Import target "Arcane::arcane_std" for configuration "Release"
set_property(TARGET Arcane::arcane_std APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_std PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "hiredis::hiredis"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_std.so"
  IMPORTED_SONAME_RELEASE "libarcane_std.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_std )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_std "${_IMPORT_PREFIX}/lib/libarcane_std.so" )

# Import target "Arcane::arcane_aleph" for configuration "Release"
set_property(TARGET Arcane::arcane_aleph APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_aleph PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_aleph.so"
  IMPORTED_SONAME_RELEASE "libarcane_aleph.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_aleph )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_aleph "${_IMPORT_PREFIX}/lib/libarcane_aleph.so" )

# Import target "Arcane::arcane_aleph_kappa" for configuration "Release"
set_property(TARGET Arcane::arcane_aleph_kappa APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_aleph_kappa PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Arcane::arcane_aleph"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_aleph_kappa.so"
  IMPORTED_SONAME_RELEASE "libarcane_aleph_kappa.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_aleph_kappa )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_aleph_kappa "${_IMPORT_PREFIX}/lib/libarcane_aleph_kappa.so" )

# Import target "Arcane::arcane_aleph_hypre" for configuration "Release"
set_property(TARGET Arcane::arcane_aleph_hypre APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_aleph_hypre PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Arcane::arcane_aleph"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_aleph_hypre.so"
  IMPORTED_SONAME_RELEASE "libarcane_aleph_hypre.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_aleph_hypre )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_aleph_hypre "${_IMPORT_PREFIX}/lib/libarcane_aleph_hypre.so" )

# Import target "Arcane::arcane_aleph_trilinos" for configuration "Release"
set_property(TARGET Arcane::arcane_aleph_trilinos APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_aleph_trilinos PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_aleph_trilinos.so"
  IMPORTED_SONAME_RELEASE "libarcane_aleph_trilinos.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_aleph_trilinos )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_aleph_trilinos "${_IMPORT_PREFIX}/lib/libarcane_aleph_trilinos.so" )

# Import target "Arcane::arcane_aleph_petsc" for configuration "Release"
set_property(TARGET Arcane::arcane_aleph_petsc APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_aleph_petsc PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_aleph_petsc.so"
  IMPORTED_SONAME_RELEASE "libarcane_aleph_petsc.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_aleph_petsc )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_aleph_petsc "${_IMPORT_PREFIX}/lib/libarcane_aleph_petsc.so" )

# Import target "Arcane::arcane_driverlib" for configuration "Release"
set_property(TARGET Arcane::arcane_driverlib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_driverlib PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_driverlib.so"
  IMPORTED_SONAME_RELEASE "libarcane_driverlib.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_driverlib )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_driverlib "${_IMPORT_PREFIX}/lib/libarcane_driverlib.so" )

# Import target "Arcane::arcane_accelerator_core" for configuration "Release"
set_property(TARGET Arcane::arcane_accelerator_core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_accelerator_core PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_accelerator_core.so"
  IMPORTED_SONAME_RELEASE "libarcane_accelerator_core.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_accelerator_core )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_accelerator_core "${_IMPORT_PREFIX}/lib/libarcane_accelerator_core.so" )

# Import target "Arcane::arcane_cartesianmesh" for configuration "Release"
set_property(TARGET Arcane::arcane_cartesianmesh APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_cartesianmesh PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Arcane::arcane_mesh"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_cartesianmesh.so"
  IMPORTED_SONAME_RELEASE "libarcane_cartesianmesh.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_cartesianmesh )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_cartesianmesh "${_IMPORT_PREFIX}/lib/libarcane_cartesianmesh.so" )

# Import target "Arcane::arcane_cea" for configuration "Release"
set_property(TARGET Arcane::arcane_cea APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_cea PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_cea.so"
  IMPORTED_SONAME_RELEASE "libarcane_cea.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_cea )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_cea "${_IMPORT_PREFIX}/lib/libarcane_cea.so" )

# Import target "Arcane::arcane_cea_geometric" for configuration "Release"
set_property(TARGET Arcane::arcane_cea_geometric APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_cea_geometric PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_cea_geometric.so"
  IMPORTED_SONAME_RELEASE "libarcane_cea_geometric.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_cea_geometric )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_cea_geometric "${_IMPORT_PREFIX}/lib/libarcane_cea_geometric.so" )

# Import target "Arcane::arcane_cea_tests" for configuration "Release"
set_property(TARGET Arcane::arcane_cea_tests APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Arcane::arcane_cea_tests PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libarcane_cea_tests.so"
  IMPORTED_SONAME_RELEASE "libarcane_cea_tests.so"
  )

list(APPEND _cmake_import_check_targets Arcane::arcane_cea_tests )
list(APPEND _cmake_import_check_files_for_Arcane::arcane_cea_tests "${_IMPORT_PREFIX}/lib/libarcane_cea_tests.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
