# -*- tab-width: 2; indent-tabs-mode: nil; coding: utf-8-with-signature -*-

# Macro pour positionner une variable si elle ne l'est pas déjà
macro(arcane_set_if_unset)
  if(NOT ${ARGV0})
    message(VERBOSE "SET: ${ARGV0} to ${ARGV1}")
    set(${ARGV0} "${ARGV1}")
  endif()
endmacro()

set(ARCANE_CMAKE_PREFIX_PATH "")
arcane_set_if_unset(Axlstar_ROOT "/work/zhaoy/Bureau/framework/_common/build_all/../../axlstar")
arcane_set_if_unset(Arccore_ROOT "/work/zhaoy/Bureau/framework/_common/build_all/../../arccore")
arcane_set_if_unset(GTest_DIR "/soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/googletest/1.11.0-GCCcore-11.2.0/lib64/cmake/GTest")
arcane_set_if_unset(Zoltan2_DIR "/soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/Trilinos/13.2.0-gimkl-2021b-serial/lib64/cmake/Zoltan2")
arcane_set_if_unset(AztecOO_DIR "/soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/Trilinos/13.2.0-gimkl-2021b-serial/lib64/cmake/AztecOO")
arcane_set_if_unset(ML_DIR "/soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/Trilinos/13.2.0-gimkl-2021b-serial/lib64/cmake/ML")
arcane_set_if_unset(Ifpack_DIR "/soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/Trilinos/13.2.0-gimkl-2021b-serial/lib64/cmake/Ifpack")
arcane_set_if_unset(Epetra_DIR "/soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/Trilinos/13.2.0-gimkl-2021b-serial/lib64/cmake/Epetra")
arcane_set_if_unset(Arccon_ROOT "/work/zhaoy/Bureau/framework/_common/build_all/../../arccon")
arcane_set_if_unset(TBB_DIR "/soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/tbb/2021.4.0-GCCcore-11.2.0/lib64/cmake/TBB")
arcane_set_if_unset(hiredis_DIR "/soft/irsrvsoft1/expl/eb/r11/el_9-x86_64/easybuild/software/hiredis/1.0.2-GCCcore-11.2.0/share/hiredis")
