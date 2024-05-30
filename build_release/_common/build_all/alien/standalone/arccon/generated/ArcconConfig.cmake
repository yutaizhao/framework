set(Arccon_VERSION 1.5.0)


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was ArcconConfig.cmake.in                            ########

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

set_and_check(ARCCON_MODULE_PATH_SYSTEM "${PACKAGE_PREFIX_DIR}/lib/arccon/build-system")
set_and_check(ARCCON_MODULE_PATH_M "${PACKAGE_PREFIX_DIR}/lib/arccon/build-system/Modules")

set_and_check(ARCCON_CMAKE_COMMANDS "${PACKAGE_PREFIX_DIR}/lib/arccon/build-system/commands/commands.cmake")
set(ARCCON_PACKAGE_DIRS ${ARCCON_PACKAGE_DIR_SYSTEM} ${ARCCON_PACKAGE_DIR_M})
set(ARCCON_MODULE_PATH ${ARCCON_MODULE_PATH_SYSTEM} ${ARCCON_MODULE_PATH_M})
