cmake_minimum_required(VERSION 3.10)
enable_testing()
option(KPP_DYLIB "Option for dynamic libraries" OFF)
option(KPP_LOG "Logger on for " ON)
option(ae2f_IS_SHARED "" ${KPP_DYLIB})

set(KPP_STRLEN 512 CACHE STRING "")
set(KPP_STRLINE 32 CACHE STRING "")
set(KPP_TOKL 64 CACHE STRING "")
set(KPP_TOKC 32 CACHE STRING "")
set(KPP_TOKML 1024 CACHE STRING "")

include(cmake.cmake)

ae2f_CoreLibFetch(ae2f Core main)

link_libraries(Core)

project(FIL)
if(NOT TARGET ${PROJECT_NAME})

configure_file(
    ${PROJECT_SOURCE_DIR}/hin/MaxStrLen.h 
    ${PROJECT_SOURCE_DIR}/include/KPP/MaxStrLen/Env.h
)

configure_file(
    ${PROJECT_SOURCE_DIR}/hin/Log.h
    ${PROJECT_SOURCE_DIR}/include/KPP/Log/Log.h
)

configure_file(
    ${PROJECT_SOURCE_DIR}/hin/TokMgr.h 
    ${PROJECT_SOURCE_DIR}/include/KPP/TokMgr/Lmts.h
)

ae2f_CoreLibTent(
    KPP-H INTERFACE include KPP
    include/KPP/Log.h
    include/KPP/Log/Log.h
    include/KPP/InitWithArgs.h
    hin/MaxStrLen.h
    include/KPP/MaxStrLen.h
    include/KPP/MaxStrLen/Env.h
    hin/Log.h

    include/KPP/TokMgr.h
    include/KPP/TokMgr/Lmts.h
)
target_link_libraries(KPP-H INTERFACE Core)

ae2f_CoreLibTent(
    KPP ${ae2f_LIBPREFIX} include KPP
    src/MaxStrLen.c
    src/TokMgr.c
    src/warp.h
)
ae2f_CoreTestTent(KPP test/KPP)
configure_file(${PROJECT_SOURCE_DIR}/test/KPP/tokquery ${PROJECT_BINARY_DIR}/TOKMGRTEST)
target_link_libraries(KPP PUBLIC KPP-H)

ae2f_CoreLibTent(
    FIL-H INTERFACE include KPP
    include/KPP/FIL.h
    include/KPP/FIL/Bias.h
    include/KPP/FIL/Glob.h

    hin/Log.h
    include/KPP/Log.h
    include/KPP/Log/Log.h
)
target_link_libraries(FIL-H INTERFACE KPP-H)

ae2f_CoreLibTent(
    FIL ${ae2f_LIBPREFIX} include KPP
    src/FIL/Bias.c
    src/FIL/Glob.c
    src/FIL/warp.h
)

target_link_libraries(FIL PUBLIC FIL-H)
target_link_libraries(FIL PUBLIC KPP)

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

target_link_libraries(FILAdvBin PRIVATE FILAdv)

endif()
