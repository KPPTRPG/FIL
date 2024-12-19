cmake_minimum_required(VERSION 3.10)

option(FIL_EXBIN "Option for executables. When it is off, main functions will have different names" ON)
option(FIL_DYLIB "Option for dynamic libraries" OFF)
option(ae2f_IS_SHARED "" ${KPPTRPG_DYLIB})

set(FIL_STRLEN 512 CACHE STRING "")
set(FIL_STRLEN_LONG 32768 CACHE STRING "")
set(FIL_FLAGMAXLEN 16 CACHE STRING "")

add_subdirectory(ae2f)
link_libraries(Ds)

project(FIL)

if(NOT TARGET ${PROJECT_NAME})
configure_file(${PROJECT_SOURCE_DIR}/hin/MaxStrLen.h ${PROJECT_SOURCE_DIR}/include/FIL/MaxStrLen.h)
configure_file(${PROJECT_SOURCE_DIR}/hin/Left.h ${PROJECT_SOURCE_DIR}/include/FIL/Left.h)
ae2f_CoreLibTent(
    ${PROJECT_NAME}
    INTERFACE
    include KPP
    "include/FIL.h"
    "include/FIL/MaxStrLen.h"
    "include/FIL/Bias.h"
    "include/FIL/Flag.h"
)

link_libraries(${PROJECT_NAME})

ae2f_CoreLibTent(
    ${PROJECT_NAME}IO
    ${ae2f_LIBPREFIX}
    include KPP
    "include/FIL/IO.h"
    "include/FIL/Left.h"
    "src/IO.c"
    "src/Left.c"
)

link_libraries(${PROJECT_NAME}IO)

ae2f_CoreLibTent(
    ${PROJECT_NAME}Glob
    ${ae2f_LIBPREFIX}
    include KPP
    "include/FIL/Glob.h"
    "src/Glob.c"
)

link_libraries(${PROJECT_NAME}Glob)

ae2f_CoreLibTent(
    ${PROJECT_NAME}Adv
    ${ae2f_LIBPREFIX}
    include KPP
    "include/FIL/Adv.h"
    "include/FIL/Adv/Brood.h"
    "include/FIL/Adv/Info.h"
    "include/FIL/Adv/Stat.h"
    "src/Adv.c"
    "src/Adv/Brood.c"
    "src/Adv/Info.c"
    "src/Adv/Stat.c"
)

link_libraries(${PROJECT_NAME}Adv)

endif()