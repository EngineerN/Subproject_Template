# Minimum CMake required
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# Define the project.
project(Test VERSION 0.0.0 LANGUAGES C CXX)

# Add CMake Modules
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake)
INCLUDE(SafeGuards)
INCLUDE(InstallDirs)

# Options for the CMakeLists.txt
option(BUILD_DOCS "Enables building doxygen docs" ON)

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

# Set Cxx Standard for use.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set visibility flags
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

# Recurse into sub directories
IF(${BUILD_DOCS})
    ADD_SUBDIRECTORY(doc)
ENDIF()

#Check and add warning flags
set(MSVC_WARNING_FLAGS /Wall)
set(CLANG_WARNING_FLAGS -Wall -Wextra -pedantic)
set(GNU_WARNING_FLAGS -Wall -Wextra -pedantic)
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:${MSVC_WARNING_FLAGS}>")
add_compile_options("$<$<CXX_COMPILER_ID:Clang>:${CLANG_WARNING_FLAGS}>")
add_compile_options("$<$<CXX_COMPILER_ID:GNU>:${GNU_WARNING_FLAGS}>")

# Generate the shared library from the sources
add_library(${PROJECT_NAME} SHARED ${SOURCES})
include(GenerateExportHeader)
GENERATE_EXPORT_HEADER(Test)
