add_library(MyTemperature temperature.cpp)
add_library(MyUtils utils.cpp)
add_library(MyProject project.cpp)
add_library(MyDateTime dateTime.cpp)
add_library(MyDatabaseHandler databaseHandler.cpp)
add_library(MyProjectHandler projectHandler.cpp)

target_include_directories(MyDatabaseHandler PUBLIC 
  "${PROJECT_SOURCE_DIR}/libraries")

target_include_directories(MyProjectHandler PUBLIC 
  "${PROJECT_SOURCE_DIR}/include")
