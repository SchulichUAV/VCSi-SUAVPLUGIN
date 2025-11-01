# sw/CMakeLists.txt
include_directories(${CMAKE_SOURCE_DIR}/json/single_include)
add_executable(vcsi_plugin main.cxx parameters/parameter.cxx parameters/param_utils.cxx parameters/ParameterModule.cxx)
