﻿# ----------------------------------------------------------------------------
# ----------------------------------------------------------------------------
# Runtime Arcane pour les accélérateurs

include(srcs.cmake)

arcane_add_library(arcane_accelerator
  INPUT_PATH ${Arcane_SOURCE_DIR}/src
  RELATIVE_PATH arcane/accelerator
  FILES ${ARCANE_SOURCES}
  )

arcane_accelerator_add_source_files(MemoryCopier.cc CommonUtils.cc)

target_link_libraries(arcane_accelerator PUBLIC
  arcane_core
  arcane_accelerator_core
  "$<TARGET_NAME_IF_EXISTS:arcane_accelerator_cuda>"
  "$<TARGET_NAME_IF_EXISTS:arcane_accelerator_hip>"
  "$<TARGET_NAME_IF_EXISTS:arcane_accelerator_sycl>"
)

# Cette cible est optionnelle pour éviter que le code n'utilisant
# pas les accélérateurs ait besoin d'un runtime accélérateur
# (par exemple 'cudart')
arcane_register_library(arcane_accelerator OPTIONAL)

# ----------------------------------------------------------------------------

option(ARCANE_EXECUTE_ACCELERATOR_GOOGLETEST "True if we run accelerator googletest. This require GPU driver" ON)
if (GTEST_FOUND AND ARCANE_EXECUTE_ACCELERATOR_GOOGLETEST)
  add_subdirectory(tests)
endif()

# ----------------------------------------------------------------------------
# Local Variables:
# tab-width: 2
# indent-tabs-mode: nil
# coding: utf-8-with-signature
# End:
