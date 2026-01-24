cmake_minimum_required(VERSION 3.16)

project(SuavPlugin LANGUAGES CXX)

# --- VISUAL STUDIO FIX ---
if(NOT CMAKE_BUILD_TYPE AND MSVC)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Force Release build" FORCE)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(/Zc:__cplusplus)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.5.3 REQUIRED COMPONENTS Core Widgets Gui Qml QuickWidgets Quick QuickLayouts)

# --- MAVSDK CONFIGURATION ---
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build static libs" FORCE)
set(BUILD_MAVSDK_SERVER OFF CACHE BOOL "Disable server" FORCE)
set(MAVSDK_BUILD_TESTS OFF CACHE BOOL "Disable tests" FORCE)
set(MAVSDK_BUILD_EXAMPLES OFF CACHE BOOL "Disable examples" FORCE)
set(MAVSDK_BUILD_INTEGRATION_TESTS OFF CACHE BOOL "Disable integration tests" FORCE)
set(BUILD_WITHOUT_CURL ON CACHE BOOL "Disable HTTP/S (OpenSSL) deps" FORCE)

# Build MAVSDK
add_subdirectory(mavsdk)

# --- PLUGIN SOURCE SELECTION ---
file(GLOB_RECURSE SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cxx"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.qml"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.qrc"
)

# Exclude mavsdk folder to prevent double-compilation
foreach(tempPath ${SOURCES})
    if(tempPath MATCHES "/mavsdk/")
        list(REMOVE_ITEM SOURCES ${tempPath})
    endif()
endforeach()

add_library(SuavPlugin MODULE ${SOURCES})

set_target_properties(SuavPlugin PROPERTIES
    OUTPUT_NAME "SuavPlugin"
    PREFIX ""
    SUFFIX ".dll"
)

set(LMCDL_ROOT "C:/Program Files/LMCDL/vcsi" CACHE PATH "LMCDL installation directory")
set(LMCDL_SDK_DIR "${LMCDL_ROOT}/sdk")
set(LMCDL_LIB_DIR "${LMCDL_SDK_DIR}/lib")

target_include_directories(SuavPlugin PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/sw
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    "${LMCDL_SDK_DIR}/include"
    
    "${CMAKE_CURRENT_SOURCE_DIR}/mavsdk/src/mavsdk/core/include"
    
    "${CMAKE_CURRENT_SOURCE_DIR}/mavsdk/src/mavsdk/plugins/telemetry/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/mavsdk/src/mavsdk/plugins/action/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/mavsdk/src/mavsdk/plugins/mission/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/mavsdk/src/mavsdk/plugins/param/include"
)

target_link_libraries(SuavPlugin PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::QuickWidgets
    Qt6::QuickLayouts
    "${LMCDL_LIB_DIR}/vcsiapi.lib"
    "${LMCDL_LIB_DIR}/VcsiPluginApi.lib"
    "${LMCDL_LIB_DIR}/VcsiCoreValuesApi.lib"
    
    mavsdk
)

set(PLUGIN_DIR "${LMCDL_ROOT}/bin/plugins/vcsi")

add_custom_command(TARGET SuavPlugin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "${PLUGIN_DIR}"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:SuavPlugin> "${PLUGIN_DIR}/$<TARGET_FILE_NAME:SuavPlugin>"
)