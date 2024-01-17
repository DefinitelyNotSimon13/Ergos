
cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME Uni-Aufgaben)

project(${PROJECT_NAME} VERSION 0.1.1)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--demangle")

set(SOURCES src/main.cpp
        src/entities/project.cpp
        src/handlers/projectHandler.cpp
        src/handlers/commandHandler.cpp
        src/handlers/databaseHandler.cpp
        src/tasks/temperature.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(include)
add_subdirectory(libraries)

target_link_libraries(${PROJECT_NAME} PUBLIC MyUtilLib MyDateTimeLib Sqlite3Lib)

target_include_directories(${PROJECT_NAME} PUBLIC
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}/classes"
  "${PROJECT_SOURCE_DIR}/include"
  "${PROJECT_SOURCE_DIR}/libraries"
  )



