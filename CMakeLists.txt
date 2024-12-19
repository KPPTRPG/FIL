cmake_minimum_required(VERSION 3.10)

project(FairyInLnk)

if(NOT TARGET ${PROJECT_NAME})

option(FAIRYINLNK_EXBIN "Option for executables" ON)
option(FAIRYINLNK_EXBIN "Option for dynamic libraries" OFF)
option(FAIRYINLNK_EXBIN "" ${KPPTRPG_DYLIB})

set(FAIRYINLNK_MAXSTRLEN 32767 CACHE STRING "")
configure_file(${PROJECT_SOURCE_DIR}/hin/MaxStrLen.h ${PROJECT_SOURCE_DIR}/include/FairyInLnk/MaxStrLen.h)

add_subdirectory(ae2f)
link_libraries(Ds)

ae2f_CoreLibTent(
    ${PROJECT_NAME}
    INTERFACE
    include KPP
    "include/FairyInLnk/MaxStrLen.h"
)

endif()