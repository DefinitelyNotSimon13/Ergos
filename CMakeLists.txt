
cmake_minimum_required(VERSION 3.22)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(LoadEnv)

load_env("${CMAKE_CURRENT_SOURCE_DIR}/.env")

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)

set(PROJECT_NAME Ergos)

project(${PROJECT_NAME} VERSION 0.1.1)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_definitions(-DSOURCE_DIR=\"${PROJECT_SOURCE_DIR}\")
add_definitions(-DCONNECTION_STRING=$ENV{connection_string})
set(SOURCES src/main.cpp
        src/entities/project.cpp
        src/handlers/MenuHandler.cpp
        src/handlers/ProjectHandler.cpp
        src/handlers/CommandHandler.cpp
        src/handlers/DatabaseHandler.cpp
        src/tasks/TemperatureTask.cpp
        src/tasks/ExampleTask.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(include)
add_subdirectory(libs)

find_package(bsoncxx CONFIG REQUIRED)
find_package(mongocxx CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PUBLIC
        MyUtilLib
        MyDateTimeLib
        MyLogLib
        mongo::bsoncxx_shared
        mongo::mongocxx_shared)

target_include_directories(${PROJECT_NAME} PUBLIC
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}/src/tasks"
  "${PROJECT_SOURCE_DIR}/src/handlers"
  "${PROJECT_SOURCE_DIR}/src/entities"
  "${PROJECT_SOURCE_DIR}/include"
  "${PROJECT_SOURCE_DIR}/libs"
  )

