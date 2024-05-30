# ----------------------------------------------------------------------------
# Méthodes utilitaires pour les codes utilisants Axlstar

# ----------------------------------------------------------------------------

# Allow functions to add library dependency, even outside the source directory.
cmake_policy(SET CMP0079 NEW)

# ----------------------------------------------------------------------------
# TODO:
# - faire la doc de cette fonction
# - permettre de l'appeler en spécifiant plusieurs fichiers 'axl'.
# - renommer avec la syntaxe cmake et préfixé par 'axlstar'. Par exemple:
#   'axlstar_generate_from_axl'
function(generateAxl target)

  set(options        INSTALL_GENERATED_FILES NO_COPY NO_ARCANE NO_MESH USER_INSTALL_PREFIX)
  set(oneValueArgs   AXL_OPTION_GENERATION_MODE NAMESPACE )
  set(multiValueArgs)

  cmake_parse_arguments(ARGS "" "" "" )

  if (ARGS_USER_INSTALL_PREFIX)
    set(axl_path /work/zhaoy/Bureau/framework/build_release//axl)
  else ()
    set(axl_path /work/zhaoy/Bureau/framework/build_release/Axlstar/axl)
  endif ()

  if(NOT EXISTS )
    file(MAKE_DIRECTORY )
  endif()

  set(axl_share_path /work/zhaoy/Bureau/framework/build_release/share/axl)

  if(NOT EXISTS )
    file(MAKE_DIRECTORY )
  endif()

  set(axl )

  if(VERBOSE)
    set(verbose_args "--verbose=1")
  else()
    set(verbose_args "--verbose=0")
  endif()

  foreach(axl_file )

    get_filename_component(name  NAME_WE)

    if(NOT ARGS_NO_COPY)
      set(copy_args --copy /_.axl)
    endif()
    
    set(header_args --header-path )
    set(output_args --output-path )
    target_include_directories( PRIVATE
      $<BUILD_INTERFACE:>
    )

    if(IS_ABSOLUTE )
      set(file )
    else()
      set(file /work/zhaoy/Bureau/framework/axlstar/)
    endif()

    if(NOT EXISTS )
      get_source_file_property(is_generated  GENERATED)
      if(NOT )
        logFatalError("axl file  doesn't exist")
      endif()
    endif()
    # Note: maintenant on utilise toujours 'axl2ccT4'.

    if(ARGS_NAMESPACE)
      set(namespace )
    else()
      set(namespace "Arcane")
    endif()
    if(ARGS_NO_ARCANE)
      set(with_arcane no)
    else()
      set(with_arcane yes)
    endif()
    if(ARGS_NO_MESH)
      set(with_mesh no)
    else()
      set(with_mesh yes)
    endif()
    set(COMMENT_MESSAGE)
    if(ARGS_AXL_OPTION_GENERATION_MODE STREQUAL "ALL")
      set(options_generation_mode all)
      set(generated_files /_axl.h
        /_IOptions.h
        /_StrongOptions.h
        /_CaseOptionsT.h)
      set(COMMENT_MESSAGE "Building AXL generated file _axl.h [CaseOptions + StrongOptions]")
      target_link_libraries( PRIVATE axlstar_options)
    elseif(ARGS_AXL_OPTION_GENERATION_MODE STREQUAL "STRONG_OPTIONS_ONLY")
      set(options_generation_mode strongoption)
      set(generated_files /_axl.h
        /_IOptions.h
        /_StrongOptions.h)
      set(COMMENT_MESSAGE "Building AXL generated file _axl.h [StrongOptions]")
      target_link_libraries( PRIVATE axlstar_options)
    else()
      set(options_generation_mode caseoption)
      set(generated_files /_axl.h)
      set(COMMENT_MESSAGE "Building AXL generated file _axl.h [CaseOptions]")
    endif()
    add_custom_command(
      OUTPUT  
      DEPENDS  /work/zhaoy/Bureau/framework/build_release/bin/axlstar_dlls/Axlstar.Axl2ccT4.dll
      COMMAND /work/zhaoy/Bureau/framework/build_release/bin/axl2ccT4
      ARGS    
              
              
              
              --gen-target 
              --namespace-simple-types 
              --with-arcane 
              --with-mesh 
              
      COMMENT 
      )

    foreach(generated_file )
      set_source_files_properties(
         PROPERTIES GENERATED ON
      )
    endforeach()

    add_custom_target(_axl_ DEPENDS )
    add_dependencies( _axl_)

#    target_sources( PRIVATE )

    set_property(GLOBAL APPEND PROPERTY AXL_DB )

    if(ARGS_INSTALL_GENERATED_FILES)
        if (ARGS_USER_INSTALL_PREFIX)
            install(FILES  DESTINATION include//axl)
        else ()
            install(FILES  DESTINATION include/Axlstar/axl)
        endif ()
    endif()

  endforeach()

  target_include_directories( PRIVATE
    $<BUILD_INTERFACE:>
  )

endfunction()

# ----------------------------------------------------------------------------
# ----------------------------------------------------------------------------

function(generateAxlDataBase)

  get_property(axls GLOBAL PROPERTY AXL_DB)

  foreach(axl )
    set(AXL_STR "\n")
  endforeach()

  file(WRITE /work/zhaoy/Bureau/framework/build_release/_common/build_all/arcane/axlstar/axldb.txt )

endfunction()
