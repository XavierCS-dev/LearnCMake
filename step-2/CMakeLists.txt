cmake_minimum_required(VERSION 3.28)
project(LearnCMake VERSION 1.0.0)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_STANDARD 23)
configure_file("${PROJECT_SOURCE_DIR}/headers/LearnCMakeConfig.h.in" LearnCMakeConfig.h)
set(SRC 
  main.cpp
)
# Create a variable named libs, this is where all our library targets will be declared
set(LIBS
  DearImGUI
)
add_executable(LearnCMake ${SRC})

# Create an toggleable option called GOODBYE_WORLD
option(GOODBYE_WORLD "Print goodbye world to stdout" ON)


# Add a subdirectory which has a CMakeLists.txt that configures itself
add_subdirectory("deps/imgui")
set_target_properties(LearnCMake PROPERTIES CXX_STANDARD 23)
set_target_properties(LearnCMake PROPERTIES EXPORT_COMPILE_COMMANDS ON)

# Specify the libraries to link against
# The link interface (PRIVATE PUBLIC INTERFACE) is used to determine whether people
# can see what is inside the library (needs checking)
target_link_libraries(LearnCMake PUBLIC ${LIBS})
target_include_directories(LearnCMake PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/headers"
                           "${PROJECT_SOURCE_DIR}/src")

if (GOODBYE_WORLD)
  # Define a preprocessor declaration, can be useful for toggling options
  # eg validation layers for a vulkan program
  target_compile_definitions(LearnCMake PRIVATE "GOODBYE_WORLD")
endif()
