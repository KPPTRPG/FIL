cmake_minimum_required(VERSION 3.10)
enable_testing()
option(KPP_DYLIB "Option for dynamic libraries" OFF)
option(KPP_LOG "Logger on for " OFF)
option(ae2f_IS_SHARED "" ${KPP_DYLIB})

set(KPP_STRLEN 512 CACHE STRING "")
set(KPP_STRLINE 32 CACHE STRING "")
set(KPP_TOKL 64 CACHE STRING "")
set(KPP_TOKC 1024 CACHE STRING "")
set(KPP_TOKML 65536 CACHE STRING "")

set(FIL_RANGE_DOT_COUNT 5 CACHE STRING "")
set(FIL_RANGE_OBJ_COUNT 20 CACHE STRING "")

include(cmake.cmake)

ae2f_CoreLibFetch(ae2f Core main)

link_libraries(Core)

project(FIL LANGUAGES C CXX)
if(NOT TARGET ${PROJECT_NAME})

configure_file(
    ${PROJECT_SOURCE_DIR}/hin/MaxStrLen.h 
    ${PROJECT_SOURCE_DIR}/include/KPP/MaxStrLen.auto.h
)

configure_file(
    ${PROJECT_SOURCE_DIR}/hin/Log.h
    ${PROJECT_SOURCE_DIR}/include/KPP/Log.auto.h
)

configure_file(
    ${PROJECT_SOURCE_DIR}/hin/TokMgr.h 
    ${PROJECT_SOURCE_DIR}/include/KPP/TokMgr.auto.h
)

configure_file(
	${PROJECT_SOURCE_DIR}/hin/Range.h
	${PROJECT_SOURCE_DIR}/include/KPP/FIL/Range.auto.h
)

ae2f_CoreLibTent(
    KPP-H INTERFACE include KPP

    hin/Log.h
    include/KPP/Log.h
    include/KPP/Log.auto.h

    include/KPP/InitWithArgs.h

    hin/MaxStrLen.h
    include/KPP/MaxStrLen.h
    include/KPP/MaxStrLen.auto.h

    hin/TokMgr.h
    include/KPP/TokMgr.h
    include/KPP/TokMgr.auto.h
)
target_link_libraries(KPP-H INTERFACE Core)

ae2f_CoreLibTent(
    KPP ${ae2f_LIBPREFIX} include KPP
    src/MaxStrLen.c
    src/TokMgr.c
    src/warp.h
)
ae2f_CoreTestTent(KPP test/KPP)
configure_file(${PROJECT_SOURCE_DIR}/test/tokquery ${PROJECT_BINARY_DIR}/TOKMGRTEST)
target_link_libraries(KPP PUBLIC KPP-H)

ae2f_CoreLibTent(
    FIL-H INTERFACE include KPP
    include/KPP/FIL.h
    include/KPP/FIL/Bias.h
    include/KPP/FIL/Glob.h

    hin/Log.h
    include/KPP/Log.h
    include/KPP/Log.auto.h

    hin/Range.h
    include/KPP/FIL/Range.h
    include/KPP/FIL/Range.auto.h
)
target_link_libraries(FIL-H INTERFACE KPP-H)

ae2f_CoreLibTent(
	FIL ${ae2f_LIBPREFIX} include KPP
	src/FIL/Bias.c
	src/FIL/Glob.c
	src/FIL/Range.c
	src/FIL/warp.h
)

target_link_libraries(FIL PUBLIC FIL-H)
target_link_libraries(FIL PUBLIC KPP)
ae2f_CoreTestTent(
	FIL test/FIL
)

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
	FILAB src/FIL/Adv/main.c
)

target_link_libraries(FILAB PRIVATE FILAdv)

add_executable(
	FILABJ src/FIL/Adv/mainjson.c
)

target_link_libraries(FILABJ PRIVATE FILAdv)

endif()
