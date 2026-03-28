# Install script for directory: C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents/libs/cpp/parse

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/install")
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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/parse/Debug/libevents_parserd.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/parse/Release/libevents_parser.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/parse/MinSizeRel/libevents_parser.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/parse/RelWithDebInfo/libevents_parser.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libevents/parse" TYPE FILE FILES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents/libs/cpp/parse/parser.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libevents/parse/nlohmann" TYPE FILE FILES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents/libs/cpp/parse/nlohmann/json_fwd.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/parse/Debug/libevents_health_and_arming_checksd.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/parse/Release/libevents_health_and_arming_checks.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/parse/MinSizeRel/libevents_health_and_arming_checks.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/parse/RelWithDebInfo/libevents_health_and_arming_checks.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libevents/parse" TYPE FILE FILES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents/libs/cpp/parse/health_and_arming_checks.h")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/parse/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
