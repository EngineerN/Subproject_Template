cmake_minimum_required(VERSION 3.5)

project(Test)

string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWER)

# Bring the headers into the project
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME_LOWER})

# Glob .cpp files for compilation.
file(GLOB SOURCES "src/*.cpp")

# Generate the shared library from the sources
add_library(${PROJECT_NAME} ${SOURCES})
