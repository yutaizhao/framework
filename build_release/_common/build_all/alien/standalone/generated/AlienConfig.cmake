
####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was AlienConfig.cmake.in                            ########

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

# Set and Check must go first else macro might be redefined by find_dependency ...
set_and_check(ALIEN_MODULE_PATH "${PACKAGE_PREFIX_DIR}/lib/cmake/Alien")
set_and_check(ALIEN_TARGET_FILE "${ALIEN_MODULE_PATH}/AlienTargets.cmake")


include(CMakeFindDependencyMacro)

find_dependency(Arccon)
# Add FindPackage from Arccon
list(APPEND CMAKE_MODULE_PATH ${ARCCON_MODULE_PATH})
find_dependency(Arccore)

find_dependency(BLAS)
find_dependency(Boost)
find_dependency(Eigen3)

# Remove FindPackage Arccon paths
list(REMOVE_AT CMAKE_MODULE_PATH -1)

# set_and_check already done.
include(${ALIEN_TARGET_FILE})
list(APPEND CMAKE_MODULE_PATH ${ALIEN_MODULE_PATH})

