set(Arccore_VERSION 2.7.0.0)


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was ArccoreConfig.cmake.in                            ########

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

include(${PACKAGE_PREFIX_DIR}/lib/cmake/Arccore/ArccoreTargets.cmake)

include(CMakeFindDependencyMacro)

if(NOT ARCCORE_NO_FIND_DEPENDENCY)
  find_dependency(Arccon)
  # Add FindPackage from Arccon
  list(APPEND CMAKE_MODULE_PATH ${ARCCON_MODULE_PATH})
  if (ON)
    find_dependency(MPI)
  endif()
  find_dependency(Glib)
  # Remove FindPackage Arccon paths
  list(REMOVE_AT CMAKE_MODULE_PATH -1)
endif()

get_target_property(_AFULL Arccore::arccore_full INTERFACE_LINK_LIBRARIES)

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


set(Arccore_LIBRARIES Arccore::arccore_full)
set(Arccore_INCLUDE_DIRS ${_AINCFULL})

set(ARCCORE_CHECK NO)
set(ARCCORE_DEBUG NO)
set(ARCCORE_BUILD_MODE Release)
set(ARCCORE_ENABLE_GLIB TRUE)

check_required_components(Arccore)

set(Arccore_FOUND YES)

# ----------------------------------------------------------------------------
# Local Variables:
# tab-width: 2
# indent-tabs-mode: nil
# coding: utf-8-with-signature
# End:
