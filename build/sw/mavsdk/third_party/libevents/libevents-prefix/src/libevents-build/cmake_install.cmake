# Install script for directory: C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents/libs/cpp

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/common/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/parse/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/protocol/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/Debug/libeventsd.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/Release/libevents.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/MinSizeRel/libevents.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/RelWithDebInfo/libevents.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libevents/libevents.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libevents/libevents.cmake"
         "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/CMakeFiles/Export/9fa0c39ef44e80cea247a4cab7874ecc/libevents.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libevents/libevents-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libevents/libevents.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/libevents" TYPE FILE FILES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/CMakeFiles/Export/9fa0c39ef44e80cea247a4cab7874ecc/libevents.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/libevents" TYPE FILE FILES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/CMakeFiles/Export/9fa0c39ef44e80cea247a4cab7874ecc/libevents-debug.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/libevents" TYPE FILE FILES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/CMakeFiles/Export/9fa0c39ef44e80cea247a4cab7874ecc/libevents-minsizerel.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/libevents" TYPE FILE FILES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/CMakeFiles/Export/9fa0c39ef44e80cea247a4cab7874ecc/libevents-relwithdebinfo.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/libevents" TYPE FILE FILES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/CMakeFiles/Export/9fa0c39ef44e80cea247a4cab7874ecc/libevents-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/libevents" TYPE FILE FILES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/libeventsConfig.cmake")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
if(CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_COMPONENT MATCHES "^[a-zA-Z0-9_.+-]+$")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
  else()
    string(MD5 CMAKE_INST_COMP_HASH "${CMAKE_INSTALL_COMPONENT}")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INST_COMP_HASH}.txt")
    unset(CMAKE_INST_COMP_HASH)
  endif()
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/libevents/libevents-prefix/src/libevents-build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
