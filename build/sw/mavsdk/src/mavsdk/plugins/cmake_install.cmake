# Install script for directory: C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/sw/mavsdk/src/mavsdk/plugins

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/action/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/action_server/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/arm_authorizer_server/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/calibration/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/camera/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/camera_server/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/component_metadata/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/component_metadata_server/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/events/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/failure/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/follow_me/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/ftp/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/ftp_server/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/geofence/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/gimbal/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/gripper/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/info/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/log_files/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/log_streaming/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/manual_control/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/mission/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/mission_raw/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/mission_raw_server/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/mocap/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/offboard/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/param/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/param_server/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/rtk/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/server_utility/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/shell/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/telemetry/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/telemetry_server/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/transponder/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/tune/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/winch/cmake_install.cmake")
  include("C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/mavlink_passthrough/cmake_install.cmake")

endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/src/mavsdk/plugins/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
