cmake_minimum_required(VERSION 3.14)
project(HelloWorldProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the subdirectory containing your main.cxx
add_subdirectory(sw)
