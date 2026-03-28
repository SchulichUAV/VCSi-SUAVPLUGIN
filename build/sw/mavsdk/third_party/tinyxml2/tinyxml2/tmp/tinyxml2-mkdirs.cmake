# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2")
  file(MAKE_DIRECTORY "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2")
endif()
file(MAKE_DIRECTORY
  "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2-build"
  "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2"
  "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/tmp"
  "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2-stamp"
  "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src"
  "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2-stamp"
)

set(configSubDirs Debug;Release;MinSizeRel;RelWithDebInfo)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2-stamp${cfgdir}") # cfgdir has leading slash
endif()
