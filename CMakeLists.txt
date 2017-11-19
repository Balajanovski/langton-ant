cmake_minimum_required(VERSION 3.5)
project(langton)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake-modules")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

find_package(SDL2 REQUIRED)

set(SOURCE_FILES main.cpp Util/Coords.cpp Util/Cleanup.h Util/RandomNumberGen.cpp Ant.cpp AntManager.cpp Application.cpp Drawer.cpp Field.cpp )
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(${CMAKE_PROJECT_NAME} ${SDL2_LIBRARY})
