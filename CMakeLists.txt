# Minimum CMake required
cmake_minimum_required(VERSION 3.5)

# Define the project.
project(Test VERSION 0.0.0 LANGUAGES C CXX)

# Add CMake Modules
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake)

# Option to make CMake output Verbose
set(CMAKE_VERBOSE_MAKEFILE ON)

# Export no symbols by default (if the compiler supports it).
# This makes e.g. GCC's "visibility behavior" consistent with MSVC's. 
# On Windows/MSVC this is a noop.
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

# Get the lowercase version of the project name.
string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWER)

# Bring the headers into the project.
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME_LOWER})

# Glob .cpp files for compilation.
file(GLOB SOURCES "src/*.cpp")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Check and add warning flags
add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/Wall>
                    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -pedantic>
                    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -pedantic>)

#Check and add visibility flags
add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/MT /MTd>
                    $<$<CXX_COMPILER_ID:Clang>:-fvisibility=hidden>
                    $<$<CXX_COMPILER_ID:GNU>:-fvisibility=hidden>)

# Generate the shared library from the sources
add_library(${PROJECT_NAME} SHARED ${SOURCES})
