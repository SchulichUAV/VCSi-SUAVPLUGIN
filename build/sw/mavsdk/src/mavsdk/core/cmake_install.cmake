# Install script for directory: C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/sw/mavsdk/src/mavsdk/core

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/SuavPlugin")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/Debug/mavsdkd.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/Release/mavsdk.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/MinSizeRel/mavsdk.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/RelWithDebInfo/mavsdk.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mavsdk" TYPE FILE FILES
    "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/sw/mavsdk/src/mavsdk/core/include/mavsdk/autopilot.h"
    "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/sw/mavsdk/src/mavsdk/core/include/mavsdk/base64.h"
    "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/sw/mavsdk/src/mavsdk/core/include/mavsdk/component_type.h"
    "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/sw/mavsdk/src/mavsdk/core/include/mavsdk/connection_result.h"
    "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/sw/mavsdk/src/mavsdk/core/include/mavsdk/deprecated.h"
    "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/sw/mavsdk/src/mavsdk/core/include/mavsdk/handle.h"
    "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/sw/mavsdk/src/mavsdk/core/include/mavsdk/system.h"
    "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/sw/mavsdk/src/mavsdk/core/include/mavsdk/mavsdk.h"
    "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/sw/mavsdk/src/mavsdk/core/include/mavsdk/log_callback.h"
    "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/sw/mavsdk/src/mavsdk/core/include/mavsdk/plugin_base.h"
    "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/sw/mavsdk/src/mavsdk/core/include/mavsdk/server_plugin_base.h"
    "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/sw/mavsdk/src/mavsdk/core/include/mavsdk/geometry.h"
    "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/sw/mavsdk/src/mavsdk/core/include/mavsdk/server_component.h"
    "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/sw/mavsdk/src/mavsdk/core/include/mavsdk/mavlink_address.h"
    "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/sw/mavsdk/src/mavsdk/core/include/mavsdk/vehicle.h"
    "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/sw/mavsdk/src/mavsdk/core/include/mavsdk/overloaded.h"
    "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/core/include/mavsdk/mavlink_include.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mavsdk" TYPE DIRECTORY FILES "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/install/include/mavlink")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/Users/thoma/work/uav/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/core/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
