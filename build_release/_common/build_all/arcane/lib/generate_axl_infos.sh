﻿#!/bin/sh
BUILD_PATH=/work/zhaoy/Bureau/framework/build_release
SOURCE_PATH=/work/zhaoy/Bureau/framework
AXL_OUTPATH=${BUILD_PATH}/share/axl
mkdir ${AXL_OUTPATH}
mkdir ${AXL_OUTPATH}/dox
mkdir ${AXL_OUTPATH}/final_axl
#${BUILD_PATH}/bin/axlcopy install -b ${SOURCE_PATH}/src -o ${AXL_OUTPATH} arcane/std
export STDENV_CODE_NAME=Arcane
${BUILD_PATH}/bin/arcane_test_driver launch -arcane_opt arcane_internal
/bin/rm ${AXL_OUTPATH}/final_axl/*.axl
/bin/rm ${AXL_OUTPATH}/dox/*.dox
/bin/rm ${AXL_OUTPATH}/dox/*.md
${BUILD_PATH}/bin/axldoc --generate-final -a ${BUILD_PATH}/lib/arcane_internal.xml -o ${AXL_OUTPATH}/final_axl ${AXL_OUTPATH}
${BUILD_PATH}/bin/axldoc -u User -a ${AXL_OUTPATH}/final_axl/final_internal.xml  -o ${AXL_OUTPATH}/dox ${AXL_OUTPATH}/final_axl/*.axl
