set(Arcane_VERSION 3.13.1.0)


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was ArcaneConfig.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

# ----------------------------------------------------------------------------

# Indique si on fait un find_dependency des packages publics
set(ARCANE_USE_FIND_DEPENDENCIES ON)

# Indique si on fait charge implicitement les chemins des packages issus
# de la configuration de Arcane. Cela permet à l'utilisateur de ne pas les
# spécifier et de garantir la cohérence des chemins des packages.
if(NOT DEFINED ARCANE_USE_CONFIGURATION_PATH)
  set(ARCANE_USE_CONFIGURATION_PATH TRUE)
endif()

# ----------------------------------------------------------------------------
# Défini une variable 'ARCANE_PREFIX_DIR' car PACKAGE_PREFIX_DIR
# peut changer avec des includes
set(ARCANE_PREFIX_DIR "${PACKAGE_PREFIX_DIR}")
include(${CMAKE_CURRENT_LIST_DIR}/ArcanePathHints.cmake)

# ----------------------------------------------------------------------------
# Ajoute lecture des chemins par défaut si ces derniers ne sont pas
# spécifiés par l'utilisateur. Ajoute aussi au CMAKE_PREFIX_PATH celui
# utilisé lors de la configuration de Arcane. Cela permet à l'utilisateur de
# le surcharger sans être obligé de le spécifier

if (ARCANE_USE_CONFIGURATION_PATH)
  include(${CMAKE_CURRENT_LIST_DIR}/ArcaneConfigCache.cmake)
  if (ARCANE_CMAKE_PREFIX_PATH)
    list(APPEND CMAKE_PREFIX_PATH "${ARCANE_CMAKE_PREFIX_PATH}")
  endif()
endif()

# ----------------------------------------------------------------------------
# Récupère le chemin de 'arccon'

if (ARCANE_USE_FIND_DEPENDENCIES)
  find_package(Arccon REQUIRED
    HINTS "${ARCANE_ARCCON_HINT_PATH}"
    "${ARCANE_PREFIX_DIR}/${ARCANE_ARCCON_CONFIG_INSTALL_DIR}"
    )
endif()

# ----------------------------------------------------------------------------
# Récupère le chemin de 'arccore'
# Si on export les packages, i faut dire à Arccore de ne pas faire
# les find_dependency() car cela nécessite l'utilisation de Arccon et aussi
# de positionner par l'utilisateur les chemins des différents packages.
if (FALSE)
  set(ARCCORE_NO_FIND_DEPENDENCY TRUE)
endif()
find_package(Arccore REQUIRED
  HINTS "${ARCANE_ARCCORE_HINT_PATH}"
  "${ARCANE_PREFIX_DIR}/${ARCANE_ARCCORE_CONFIG_INSTALL_DIR}"
  )

# ----------------------------------------------------------------------------
# Récupère le chemin de 'axl2cc'
# On positionne une variable 'ARCANE_AXL2CC' pour des raisons de compatibilité
# mais il faudrait utiliser directement AXLSTAR_AXL2CC.

find_package(Axlstar REQUIRED
  HINTS "${ARCANE_AXLSTAR_HINT_PATH}"
  "${ARCANE_PREFIX_DIR}/${ARCANE_AXLSTAR_CONFIG_INSTALL_DIR}"
  )
if (NOT AXLSTAR_AXL2CC)
  message(FATAL_ERROR "Variable 'AXLSTAR_AXL2CC' is not defined")
endif()
set(ARCANE_AXL2CC "${AXLSTAR_AXL2CC}")

# ----------------------------------------------------------------------------
# Support pour '.Net'.
set(ARCANE_CORECLR_VERSION "6.0" CACHE STRING ".Net coreclr version" FORCE)

# ----------------------------------------------------------------------------
# Support pour les accélérateurs.
#
# La variable 'ARCANE_HAS_ACCELERATOR' est définie si Arcane a été compilée avec
# le support des accélérateurs. Dans ce cas, il est possible d'utiliser la macro
# 'arcane_enable_cuda' ou 'arcane_enable_rocmhip' pour rechercher les différents composants nécessaires.

set(ARCANE_HAS_ACCELERATOR "" CACHE BOOL "Is Arcane compiled with Accelerator support?" FORCE)
set(ARCANE_HAS_CUDA "" CACHE BOOL "Is Arcane compiled with CUDA support?" FORCE)
set(ARCANE_HAS_HIP "" CACHE BOOL "Is Arcane compiled with HIP support?" FORCE)
set(ARCANE_CUDA_COMPILER_HINT "")
set(ARCANE_HIP_COMPILER_HINT "")
set(ARCANE_HIP_DIR_HINT "")
set(ARCANE_DEFAULT_HIP_ARCHITECTURES "" CACHE STRING "Default GPU architectures?" FORCE)
set(ARCANE_HAS_DOTNET_WRAPPER "FALSE" CACHE BOOL "Is C# wrapping enabled?" FORCE)
set(ARCANE_HAS_ACCELERATOR_API "FALSE" CACHE BOOL "True Arcane has accelerator API" FORCE)

macro(arcane_internal_enable_cuda)
  if (ARCANE_HAS_CUDA)
    # Pour le support du C++20 avec NVCC, il faut au moins cmake 3.26
    cmake_minimum_required(VERSION 3.26 FATAL_ERROR)
    # La commande 'enable_language(CUDA)' a besoin que la variable
    # d'environnement 'CUDACXX' ou la variable cmake 'CMAKE_CUDA_COMPILER'
    # soit définie. Si ce n'est pas le cas, utilise le chemin du compilateur
    # utilisé pour compiler Arcane.
    if(NOT DEFINED ENV{CUDACXX} AND NOT CMAKE_CUDA_COMPILER)
      set(CMAKE_CUDA_COMPILER "${ARCANE_CUDA_COMPILER_HINT}")
    endif()
    message(STATUS "ArcaneCUDA: CMAKE_CUDA_COMPILER = ${CMAKE_CUDA_COMPILER}")

    enable_language(CUDA)
    # A partir de CMake 3.18, il faut spécifier une architecture GPU pour CUDA
    if (NOT CMAKE_CUDA_ARCHITECTURES)
      set(CMAKE_CUDA_ARCHITECTURES 50 60 70 80 CACHE STRING "Default architectures" FORCE)
    endif()

    find_package(CUDAToolkit REQUIRED)
  else()
    message(FATAL_ERROR "Can not enable CUDA because Arcane is not compiled with CUDA support")
  endif()
endmacro()

macro(arcane_internal_enable_hip)
  if (ARCANE_HAS_HIP)
    # La commande 'enable_language(HIP)' a besoin que la variable
    # d'environnement 'HIPCXX' ou la variable cmake 'CMAKE_HIP_COMPILER'
    # soit définie. Si ce n'est pas le cas, utilise le chemin du compilateur
    # utilisé pour compiler Arcane.
    if(NOT DEFINED ENV{HIPCXX} AND NOT CMAKE_HIP_COMPILER)
      set(CMAKE_HIP_COMPILER "${ARCANE_HIP_COMPILER_HINT}")
    endif()
    message(STATUS "ArcaneHIP: CMAKE_HIP_COMPILER = ${CMAKE_HIP_COMPILER}")

    # Il faut au moins la version 3.21 de CMake pour HIP
    enable_language(HIP)
    if (NOT CMAKE_HIP_ARCHITECTURES)
      set(CMAKE_HIP_ARCHITECTURES ${ARCANE_DEFAULT_HIP_ARCHITECTURES} CACHE STRING "Default architectures" FORCE)
    endif()

    # Il faut ajouter dans CMAKE_MODULE_PATH le chemin ou se trouve ROCM.
    # On suppose que Hip_ROOT a été positionné lors du configure de Arcane et qu'il
    # est dans ${ROCM_ROOT}/hip/lib/cmake/hip.
    set(_SAVED_CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH})
    if (ARCANE_HIP_DIR_HINT)
      # NOTE: Cette commande 'cmake_path' n'existe qu'à partir de CMake 3.20
      cmake_path(GET ARCANE_HIP_DIR_HINT PARENT_PATH _path_result1)
      cmake_path(GET _path_result1 PARENT_PATH _path_result2)
      cmake_path(GET _path_result2 PARENT_PATH _path_result)
      if (_path_result)
        list(APPEND CMAKE_PREFIX_PATH "${_path_result}")
      endif()
      message(STATUS "Computed CMAKE_PREFIX_PATH for Hip : ${CMAKE_PREFIX_PATH}")
    endif()
    find_package(Hip REQUIRED "${ARCANE_HIP_DIR_HINT}")
    set(CMAKE_PREFIX_PATH ${_SAVED_CMAKE_PREFIX_PATH})
  else()
    message(FATAL_ERROR "Can not enable HIP because Arcane is not compiled with HIP support")
  endif()
endmacro()

# Macro pour activer le support des accélérateurs.
# A utiliser avant les autres commandes 'arcane_accelerator_...'
macro(arcane_accelerator_enable)
  if (ARCANE_HAS_CUDA)
    arcane_internal_enable_cuda()
  endif()
  if (ARCANE_HAS_HIP)
    arcane_internal_enable_hip()
  endif()
endmacro()

# Indique que les fichiers passés en argument doivent être compilés avec le support accélérateur
# correspondant.
function(arcane_accelerator_add_source_files)
  if (ARCANE_HAS_CUDA)
    foreach(_x ${ARGN})
      message(STATUS "Add CUDA language to file '${_x}'")
      set_source_files_properties(${_x} PROPERTIES LANGUAGE CUDA)
    endforeach()
  endif()
  if (ARCANE_HAS_HIP)
    foreach(_x ${ARGN})
      message(STATUS "Add HIP language to file '${_x}'")
      set_source_files_properties(${_x} PROPERTIES LANGUAGE HIP)
    endforeach()
  endif()
endfunction()

# Ajoute à la cible 'target_name' les informations nécessaires pour utiliser
# les accélérateurs. Il faut avoir appeler 'arcane_enable_cuda' avant.
function(arcane_accelerator_add_to_target target_name)
  if (NOT target_name)
    message(FATAL_ERROR "Invalid null argument 'target_name' (${target_name}) to 'arcane_accelerator_add_to_target' function")
  endif()
  target_link_libraries(${target_name} PUBLIC arcane_accelerator)
  if (ARCANE_HAS_CUDA)
    target_link_libraries(${target_name} PUBLIC arcane_accelerator_cuda_runtime)
    set_property(TARGET ${target_name} PROPERTY CUDA_ARCHITECTURES ${CMAKE_CUDA_ARCHITECTURES})
  endif()
  if (ARCANE_HAS_HIP)
    target_link_libraries(${target_name} PUBLIC arcane_accelerator_hip_runtime)
    set_property(TARGET ${target_name} PROPERTY HIP_ARCHITECTURES ${CMAKE_HIP_ARCHITECTURES})
  endif()
endfunction()

# ----------------------------------------------------------------------------

macro(arcane_internal_add_alias target_name)
  if (NOT TARGET "${target_name}")
    add_library("${target_name}" ALIAS "Arcane::${target_name}")
    #    message(STATUS "ADD_ALIAS: ${_target_name} ALIAS Arcane::${_target_name}")
  endif()
endmacro()

# ----------------------------------------------------------------------------

include(${CMAKE_CURRENT_LIST_DIR}/ArcaneTargets.cmake)
set(_INTERNAL_ARCANE_TARGETS arcane_ios;arcane_mono;arcane_dotnet_coreclr;arcane_mpi;arcane_thread;arcane_mpithread;arcane_utils;arcane_impl;arcane_mesh;arcane_launcher;arcane_core;arcane_geometry;arcane_totalview;arcane_hdf5;arcane_std;arcane_aleph;arcane_aleph_kappa;arcane_aleph_hypre;arcane_aleph_trilinos;arcane_aleph_petsc;arcane_driverlib;arcane_accelerator_core;arcane_cartesianmesh;arcane_cea;arcane_cea_geometric;arcane_cea_tests)
foreach(_lib ${_INTERNAL_ARCANE_TARGETS})
  arcane_internal_add_alias("${_lib}")
endforeach()
arcane_internal_add_alias(arcane_full)
arcane_internal_add_alias(arcane_export_compile_flags)
arcane_internal_add_alias(arcane_build_compile_flags)

# ----------------------------------------------------------------------------

set(_INTERNAL_ARCANE_PACKAGES Axlstar;Arccore;Glib;Valgrind;Mono;MonoEmbed;CoreClrEmbed;Threads;GTest;LibXml2;GeometryKernel;LibUnwind;Papi;Parmetis;PTScotch;Udunits;Zoltan2;Zoltan;BZip2;LZ4;HWLoc;Hiredis;Hypre;AztecOO;ML;Ifpack;Epetra;TrilinosAleph;PETSc;SuperLU;Arccon;ArcDependencies;CoreClrSDK;TBB;Neo;hiredis;PkgConfig;MPI;HDF5)
set(_INTERNAL_ARCANE_FOUND_PACKAGES Glib;HDF5;MPI;HDF5;MPI)

# ----------------------------------------------------------------------------
# Fais un 'find_dependency' de tous les packages trouvés lors de la
# configuration de Arcane.

if (ARCANE_USE_FIND_DEPENDENCIES)
  include(${ARCCON_CMAKE_COMMANDS})

  set(_SAVED_CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}")
  list(APPEND CMAKE_MODULE_PATH ${ARCCON_MODULE_PATH})
  list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/Modules)
  message(VERBOSE "Autodetect Arcane packages CMAKE_MODULE_PATH=${CMAKE_MODULE_PATH}")
  message(VERBOSE "Autodetect Arcane packages list = ${_INTERNAL_ARCANE_FOUND_PACKAGES}")
  foreach(_lib ${_INTERNAL_ARCANE_FOUND_PACKAGES})
    if (NOT TARGET arcconpkg_${_lib})
      find_dependency(${_lib})
    endif()
  endforeach()
  set(CMAKE_MODULE_PATH "${_SAVED_CMAKE_MODULE_PATH}")
endif()

# ----------------------------------------------------------------------------

foreach(_lib ${_INTERNAL_ARCANE_PACKAGES})
  set(_target_name "arcconpkg_${_lib}")
  if (TARGET "Arcane::${_target_name}")
    arcane_internal_add_alias("${_target_name}")
  endif()
  set(_target_name "arcanepkg_${_lib}")
  if (TARGET "Arcane::${_target_name}")
    arcane_internal_add_alias("${_target_name}")
  endif()
endforeach()

# ----------------------------------------------------------------------------

# Chemins pour MPI (nécessite d'avoir inclus ArcaneTargets)
if(TARGET arcane_mpi)
  if(NOT MPIEXEC_EXECUTABLE)
    set(MPIEXEC_EXECUTABLE /soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/impi/2021.4.0-GCC-11.2.0/mpi/2021.4.0/bin/mpiexec)
    set(MPIEXEC_NUMPROC_FLAG -n)
  endif()
endif()

get_target_property(_AFULL arcane_full INTERFACE_LINK_LIBRARIES)

# Parcours l'ensemble des cibles de cette bibliothèque interface
# et définit une variable 'Arcane_INCLUDE_DIRS' qui
# servira pour le find_packages.
# NOTE: on est obligé de déterminer cette liste dans ce fichier
# car si on utilise les 'generator-expression' de cmake, la valeurs
# des variables dépend de la configuration.
foreach(package ${_AFULL})
  if(TARGET ${package})
    get_target_property(_AINC ${package} INTERFACE_INCLUDE_DIRECTORIES)
    if (_AINC)
      list(APPEND _AINCFULL ${_AINC})
    endif (_AINC)
  endif(TARGET ${package})
endforeach(package ${_AFULL})
list(REMOVE_DUPLICATES _AINCFULL)

set(Arcane_LIBRARIES arcane_full)
set(Arcane_INCLUDE_DIRS ${_AINCFULL})

check_required_components(Arcane)

set(Arcane_FOUND YES)

# ----------------------------------------------------------------------------
# Macro pour générer les _axl.h à partir des fichier axl
macro(arcane_generate_axl filename)
  set(options        )
  set(oneValueArgs   COPY_AXL_TO_PATH AXL_RELATIVE_PATH)
  set(multiValueArgs )

  cmake_parse_arguments(ARGS "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

  get_filename_component(_base_filename ${filename} NAME)
  get_filename_component(_base_dirname ${filename} DIRECTORY)

  set(_custom_args)
  set(_add_in_axl_filename)

  if (ARGS_AXL_RELATIVE_PATH)
    list(APPEND _custom_args "-i")
    list(APPEND _custom_args "${ARGS_AXL_RELATIVE_PATH}")
    string(REPLACE "/" "_" _add_in_axl_filename ${ARGS_AXL_RELATIVE_PATH})
    set(_add_in_axl_filename _${_add_in_axl_filename})
  else()
    if (ARGS_COPY_AXL_TO_PATH)
      list(APPEND _custom_args "-i")
      list(APPEND _custom_args "''")
    endif()
  endif()

  if (ARGS_COPY_AXL_TO_PATH)
    list(APPEND _custom_args "--copy")
    list(APPEND _custom_args "${ARGS_COPY_AXL_TO_PATH}/${_base_filename}${_add_in_axl_filename}.axl")
  endif()

  set(dirname ${CMAKE_CURRENT_BINARY_DIR}/${_base_dirname})
  file(MAKE_DIRECTORY ${dirname})
  message(STATUS "Adding AXL generation '${filename}.axl' in '${dirname}'")
  set_source_files_properties(${dirname}/${_base_filename}_axl.h PROPERTIES GENERATED TRUE)
  add_custom_command(OUTPUT ${dirname}/${_base_filename}_axl.h
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${filename}.axl
    COMMAND ${ARCANE_AXL2CC} ARGS -o ${dirname} ${_custom_args} ${CMAKE_CURRENT_SOURCE_DIR}/${filename}.axl)
endmacro()

# Macro pour ajouter le fichier 'axlfilename' à la cible 'target'
macro(arcane_target_add_axl target axlfilename)
  set(options        )
  set(oneValueArgs   COPY_AXL_TO_PATH AXL_RELATIVE_PATH)
  set(multiValueArgs )

  cmake_parse_arguments(ARGS "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

  arcane_generate_axl(${axlfilename} COPY_AXL_TO_PATH ${ARGS_COPY_AXL_TO_PATH} AXL_RELATIVE_PATH ${ARGS_AXL_RELATIVE_PATH})
  target_sources(${target} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/${axlfilename}_axl.h)
  target_include_directories(${target} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
endmacro()

# Fonction pour ajouter à la cible `target_name` les bibliothèques nécessaires
# pour utiliser Arcane.
# En fonction des plateformes, il est possible qu'il y ait besoin d'arguments
# spécifiques
function(arcane_add_arcane_libraries_to_target target_name)
  target_link_libraries(${target_name} PRIVATE arcane_full)
endfunction()

# ----------------------------------------------------------------------------
# Local Variables:
# tab-width: 2
# indent-tabs-mode: nil
# coding: utf-8
# End: