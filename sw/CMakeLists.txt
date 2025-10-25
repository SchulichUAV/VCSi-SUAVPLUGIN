cmake_minimum_required(VERSION 3.15)
project(SuavPlugin LANGUAGES CXX)

# ---- Qt setup ----
find_package(Qt6 REQUIRED COMPONENTS Core)

# ---- Source files ----
set(SOURCES
    SuavPlugin.cpp
    SuavPlugin.h
)

# ---- Build the plugin (shared library) ----
qt_add_plugin(SuavPlugin
    CLASS_NAME SuavPlugin
    OUTPUT_NAME "hello_world"        # Name of the DLL (change if needed)
    SOURCES ${SOURCES}
)

# ---- Include paths ----
target_include_directories(SuavPlugin
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../include   # if LmCdl headers are above
)

# ---- Link libraries ----
target_link_libraries(SuavPlugin
    PRIVATE
        Qt6::Core
        LmCdl::CdlInterfaces        # if provided by LMCDL SDK
)

# ---- C++ standard ----
set_target_properties(SuavPlugin PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
