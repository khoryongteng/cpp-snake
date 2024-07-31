cmake_minimum_required(VERSION 3.14) # Updated to a more recent version

# Set project name and version
project(cppSnake VERSION 0.1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch Raylib Dependency
include(FetchContent)
FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG 5.0
)
FetchContent_MakeAvailable(raylib)

# Add executable target
add_executable(${PROJECT_NAME})

# Add source files to the target
target_sources(${PROJECT_NAME}
  PRIVATE
    src/main.cpp
)

# Specify include directories
target_include_directories(${PROJECT_NAME}
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

# Link with Raylib library
target_link_libraries(${PROJECT_NAME}
  PRIVATE
    raylib
)

# Optional: Set C++ standard for targets
set_target_properties(${PROJECT_NAME} PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
)
