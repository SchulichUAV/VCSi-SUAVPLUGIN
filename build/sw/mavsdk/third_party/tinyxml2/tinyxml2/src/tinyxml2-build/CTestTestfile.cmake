# CMake generated Testfile for 
# Source directory: C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2
# Build directory: C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2-build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(xmltest "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2-build/Debug/xmltest.exe")
  set_tests_properties(xmltest PROPERTIES  PASS_REGULAR_EXPRESSION ", Fail 0" WORKING_DIRECTORY "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2" _BACKTRACE_TRIPLES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2/CMakeLists.txt;55;add_test;C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(xmltest "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2-build/Release/xmltest.exe")
  set_tests_properties(xmltest PROPERTIES  PASS_REGULAR_EXPRESSION ", Fail 0" WORKING_DIRECTORY "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2" _BACKTRACE_TRIPLES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2/CMakeLists.txt;55;add_test;C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(xmltest "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2-build/MinSizeRel/xmltest.exe")
  set_tests_properties(xmltest PROPERTIES  PASS_REGULAR_EXPRESSION ", Fail 0" WORKING_DIRECTORY "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2" _BACKTRACE_TRIPLES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2/CMakeLists.txt;55;add_test;C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(xmltest "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2-build/RelWithDebInfo/xmltest.exe")
  set_tests_properties(xmltest PROPERTIES  PASS_REGULAR_EXPRESSION ", Fail 0" WORKING_DIRECTORY "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2" _BACKTRACE_TRIPLES "C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2/CMakeLists.txt;55;add_test;C:/Users/2006l/OneDrive/Desktop/SUAV/VCSi-SUAVPLUGIN/build/sw/mavsdk/third_party/tinyxml2/tinyxml2/src/tinyxml2/CMakeLists.txt;0;")
else()
  add_test(xmltest NOT_AVAILABLE)
endif()
