#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "libevents_parser" for configuration "Debug"
set_property(TARGET libevents_parser APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(libevents_parser PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libevents_parserd.lib"
  )

list(APPEND _cmake_import_check_targets libevents_parser )
list(APPEND _cmake_import_check_files_for_libevents_parser "${_IMPORT_PREFIX}/lib/libevents_parserd.lib" )

# Import target "libevents_health_and_arming_checks" for configuration "Debug"
set_property(TARGET libevents_health_and_arming_checks APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(libevents_health_and_arming_checks PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libevents_health_and_arming_checksd.lib"
  )

list(APPEND _cmake_import_check_targets libevents_health_and_arming_checks )
list(APPEND _cmake_import_check_files_for_libevents_health_and_arming_checks "${_IMPORT_PREFIX}/lib/libevents_health_and_arming_checksd.lib" )

# Import target "libevents" for configuration "Debug"
set_property(TARGET libevents APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(libevents PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libeventsd.lib"
  )

list(APPEND _cmake_import_check_targets libevents )
list(APPEND _cmake_import_check_files_for_libevents "${_IMPORT_PREFIX}/lib/libeventsd.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
