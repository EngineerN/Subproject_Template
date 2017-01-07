# Project Setup
This file is a detailed description of the necessary changes to use this template.

## Project Structure
Assuming Subproject is named Test.

Test
  src
  include/test

## CPP Files
Place all cpp files in the src folder. Note that CMake will glob all of the sources.

## Header Files
The header files should be placed include/projectname. (Note that the project name is lowercase for the folder.)

## CMakeLists
The only necessary change is to change the project name. This is used in the folder structure and in the main project. To avoid issues make the name unique...
