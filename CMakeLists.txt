cmake_minimum_required(VERSION 3.10)
enable_testing()
option(FIL_DYLIB "Option for dynamic libraries" OFF)
option(FIL_LOG "Logger on for " ON)
option(ae2f_IS_SHARED "" ${KPPTRPG_DYLIB})

set(FIL_STRLEN 512 CACHE STRING "")
set(FIL_STRLINE 30 CACHE STRING "")

include(cmake.cmake)

ae2f_CoreLibFetch(ae2f Core main)

link_libraries(Core)

project(FIL)
if(NOT TARGET ${PROJECT_NAME})

configure_file(${PROJECT_SOURCE_DIR}/hin/MaxStrLen.h    ${PROJECT_SOURCE_DIR}/include/KPP/FIL/MaxStrLen/Env.h)
configure_file(${PROJECT_SOURCE_DIR}/hin/Log.h          ${PROJECT_SOURCE_DIR}/include/KPP/Log/Log.h)

ae2f_CoreLibTent(
    KPP INTERFACE include KPP
    include/KPP/Log.h
    include/KPP/Log/Log.h
    include/KPP/InitWithArgs.h
    hin/Log.h
)
target_link_libraries(KPP INTERFACE Core)

ae2f_CoreLibTent(
    FIL-H INTERFACE include KPP
    include/KPP/FIL.h
    include/KPP/FIL/Bias.h
    include/KPP/FIL/Glob.h
    hin/MaxStrLen.h
    include/KPP/FIL/MaxStrLen.h
    include/KPP/FIL/MaxStrLen/Env.h

    hin/Log.h
    include/KPP/Log.h
    include/KPP/Log/Log.h
)
target_link_libraries(FIL-H INTERFACE KPP)

ae2f_CoreLibTent(
    FIL ${ae2f_LIBPREFIX} include KPP
    src/FIL/Bias.c
    src/FIL/MaxStrLen.c
    src/FIL/warp.h
)

target_link_libraries(FIL PUBLIC FIL-H)

ae2f_CoreLibTent(
    FILAdv-H INTERFACE include KPP
    include/KPP/FIL/Adv.h
    include/KPP/FIL/Adv/Brood.h
    include/KPP/FIL/Adv/Info.h
    include/KPP/FIL/Adv/Stat.h
)

target_link_libraries(FILAdv-H INTERFACE FIL-H)

ae2f_CoreLibTent(
    FILAdv ${ae2f_LIBPREFIX} include KPP
    src/FIL/Adv.c
    src/FIL/Adv/warp.h
    src/FIL/Adv/Info.c
    src/FIL/Adv/Brood.c
    src/FIL/Adv/Stat.c
)

target_link_libraries(FILAdv PUBLIC FILAdv-H)
target_link_libraries(FILAdv PUBLIC FIL)

add_executable(
    FILAdvBin src/FIL/Adv/main.c
)

endif()
