createLibrary(logger
  EXPORT alien/AlienLoggerExport.h
  )

addSources(logger
  alien/Logger/Logger.cc
  )

set(AXL_OPTION_GENERATION_TYPE "ALL")
set(NAMESPACE_TYPE "Arcane")
set(IS_WITH_ARCANE "")
set(IS_WITH_MESH "NO_MESH")

generateAxl(logger
    alien/Logger/Arcane/SolverLogger.axl
    AXL_OPTION_GENERATION_MODE ${AXL_OPTION_GENERATION_TYPE}
    NAMESPACE ${NAMESPACE_TYPE}
    ${IS_WITH_ARCANE}
    ${IS_WITH_MESH}
    INSTALL_GENERATED_FILES
    USER_INSTALL_PREFIX ALIEN
    )

addSources(logger
    alien/Logger/Arcane/SolverLoggerService.cc
    )


linkLibraries(logger Alien::alien_core arcane_core)

commit(logger)

target_include_directories(logger PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>)

install(DIRECTORY alien 
        DESTINATION include
        FILES_MATCHING PATTERN "*.h"
  )
