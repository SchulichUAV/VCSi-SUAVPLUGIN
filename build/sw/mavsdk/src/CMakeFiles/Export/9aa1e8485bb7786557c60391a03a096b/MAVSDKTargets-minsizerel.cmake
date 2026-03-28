#----------------------------------------------------------------
# Generated CMake target import file for configuration "MinSizeRel".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "MAVSDK::mavsdk" for configuration "MinSizeRel"
set_property(TARGET MAVSDK::mavsdk APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(MAVSDK::mavsdk PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/mavsdk.lib"
  )

list(APPEND _cmake_import_check_targets MAVSDK::mavsdk )
list(APPEND _cmake_import_check_files_for_MAVSDK::mavsdk "${_IMPORT_PREFIX}/lib/mavsdk.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
