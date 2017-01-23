# Minimum CMake required
cmake_minimum_required(VERSION 3.5)

# Define the project.
project(Test VERSION 0.0.0 LANGUAGES C CXX)

# Add CMake Modules
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake)

# Option to make CMake output Verbose
set(CMAKE_VERBOSE_MAKEFILE OFF)


include 


# Get the lowercase version of the project name.
string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWER)

# Bring the headers into the project.
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME_LOWER})

# Glob .cpp files for compilation.
file(GLOB SOURCES "src/*.cpp")

set(CMAKE_CXX_STANDARD 14)

# Set CXX_FLAGS
set(CXX_FLAGS -Wall -pedantic -Wextra -std=c++11)
set(CXX_FLAGS_RELWITHDEBINFO -O2 -g)
set(CXX_FLAGS_RELEASE -O2)
set(CXX_FLAGS_DEBUG -O0 -g)

# Check and add flags

foreach(CXX_FLAGS_ITEM ${CXX_FLAGS})
  CHECK_CXX_COMPILER_FLAG(CXX_FLAGS_ITEM ${CMAKE_CXX_FLAGS})
endforeach()

# Set CXX_FLAGS_RELWITHDEBINFO


foreach(CXX_FLAGS_RELWITHDEBINFO_ITEM ${CXX_FLAGS})
  CHECK_CXX_COMPILER_FLAG(CXX_FLAGS_RELWITHDEBINFO_ITEM ${CMAKE_CXX_FLAGS_RELWITHDEBINFO})
endforeach()

# Set CXX_FLAGS_RELEASE
set(CXX_FLAGS_RELEASE -O2)

foreach(CXX_FLAGS_RELEASE_ITEM ${CXX_FLAGS_RELEASE})
  CHECK_CXX_COMPILER_FLAG(CXX_FLAGS_RELEASE_ITEM ${CMAKE_CXX_FLAGS_RELEASE})
endforeach()

# Set CXX_FLAGS_DEBUG
set(CXX_FLAGS_DEBUG -O0 -g)

foreach(CXX_FLAGS_DEBUG_ITEM ${CXX_FLAGS_DEBUG})
  CHECK_CXX_COMPILER_FLAG(CXX_FLAGS_ITEM ${CMAKE_CXX_FLAGS_DEBUG})
endforeach()

# Generate the shared library from the sources
add_library(${PROJECT_NAME} SHARED ${SOURCES})
