# Specify a minimum CMake version of 3.28
cmake_minimum_required(VERSION 3.28)

# Specify a project name LearnCMake, with the version set to 1.0.0
project(LearnCMake VERSION 1.0.0)

# Specify that the value of CXX_STANDARD is mandatory
set(CXX_STANDARD_REQUIRED ON)

# Set the CPP standard to C++23, note, this does not mean the project will compile with this standard!
set(CXX_STANDARD 23)

# Run any CMake interpolations on LearnCMakeConfig.h.in and output to LearnCMakeConfig.h
configure_file("${PROJECT_SOURCE_DIR}/headers/LearnCMakeConfig.h.in" LearnCMakeConfig.h)

# Create a variable names SRC and set it to "main.cpp"
set(SRC 
  main.cpp
)

# Add an executable target to the project, with name "LearnCMake" and using the source files dictated
# by the SRC variable
add_executable(LearnCMake ${SRC})

# Actually compile the project with C++23
set_target_properties(LearnCMake PROPERTIES CXX_STANDARD 23)

# Allow LSPs to use information in this CMakeLists.txt to perform linting
set_target_properties(LearnCMake PROPERTIES EXPORT_COMPILE_COMMANDS ON)

# Add directories to search for sources when building the target LearnCMake
# The binary directory is being added here as that is where LearnCMakeConfig.h will be created
target_include_directories(LearnCMake PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/headers"
                           "${PROJECT_SOURCE_DIR}/src"
                           )
