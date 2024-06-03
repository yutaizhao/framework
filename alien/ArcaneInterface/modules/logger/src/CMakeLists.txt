createLibrary(logger
  EXPORT alien/AlienLoggerExport.h
  )

addSources(logger
  alien/Logger/Logger.cc
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
