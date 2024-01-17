
cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME Uni-Aufgaben)

project(${PROJECT_NAME} VERSION 0.1.1)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)
add_subdirectory(classes)
add_subdirectory(include)
add_subdirectory(libraries)

target_include_directories(${PROJECT_NAME} PUBLIC
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}/classes"
  "${PROJECT_SOURCE_DIR}/include"
  "${PROJECT_SOURCE_DIR}/libraries"
  )



