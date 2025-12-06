cmake_minimum_required(VERSION 3.16)

project(SuavPlugin LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(/Zc:__cplusplus)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.5.3 REQUIRED COMPONENTS Core Widgets Gui Qml QuickWidgets Quick)

file(GLOB_RECURSE SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cxx"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.qml"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.qrc"
)

add_library(SuavPlugin MODULE ${SOURCES})

set_target_properties(SuavPlugin PROPERTIES
    OUTPUT_NAME "SuavPlugin"
    PREFIX ""
    SUFFIX ".dll"
)

set(LMCDL_ROOT "C:/Program Files/LMCDL/vcsi" CACHE PATH "LMCDL installation directory")
set(LMCDL_SDK_DIR "${LMCDL_ROOT}/sdk")
set(LMCDL_LIB_DIR "${LMCDL_SDK_DIR}/lib")

get_filename_component(MAVSDK_ROOT_ABS "${CMAKE_CURRENT_SOURCE_DIR}/../mavsdk/mavsdk-windows-x86" ABSOLUTE)
set(MAVSDK_INCLUDE_DIR "${MAVSDK_ROOT_ABS}/include")
set(MAVSDK_LIB_DIR "${MAVSDK_ROOT_ABS}/Release/lib")
set(MAVSDK_BIN_DIR "${MAVSDK_ROOT_ABS}/Release/bin")

if(NOT EXISTS "${MAVSDK_LIB_DIR}/mavsdk.lib")
    message(FATAL_ERROR "MAVSDK lib not found at ${MAVSDK_LIB_DIR}/mavsdk.lib")
endif()

target_include_directories(SuavPlugin PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/sw
    ${CMAKE_CURRENT_SOURCE_DIR}/sw/casino
    ${CMAKE_CURRENT_SOURCE_DIR}/sw/vehicle
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    "${LMCDL_SDK_DIR}/include"
    "${MAVSDK_INCLUDE_DIR}"
)

target_link_libraries(SuavPlugin PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::QuickWidgets
    "${LMCDL_LIB_DIR}/vcsiapi.lib"
    "${LMCDL_LIB_DIR}/VcsiPluginApi.lib"
    "${LMCDL_LIB_DIR}/VcsiCoreValuesApi.lib"
    "${MAVSDK_LIB_DIR}/mavsdk.lib"
)

set(PLUGIN_DIR "${LMCDL_ROOT}/bin/plugins/vcsi")

add_custom_command(TARGET SuavPlugin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "${PLUGIN_DIR}"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:SuavPlugin> "${PLUGIN_DIR}/$<TARGET_FILE_NAME:SuavPlugin>"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${MAVSDK_BIN_DIR}/mavsdk.dll" "${PLUGIN_DIR}/mavsdk.dll"
)