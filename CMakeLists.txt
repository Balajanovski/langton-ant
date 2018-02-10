cmake_minimum_required(VERSION 3.5)
project(langton)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake-modules")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

find_package(SDL2 REQUIRED)
find_package(YamlCpp REQUIRED)

file(GLOB SOURCE_FILES
        "${PROJECT_SOURCE_DIR}/*.h"
        "${PROJECT_SOURCE_DIR}/*.hpp"
        "${PROJECT_SOURCE_DIR}/*.cpp"
        "${PROJECT_SOURCE_DIR}/Util/*.h"
        "${PROJECT_SOURCE_DIR}/Util/*.hpp"
        "${PROJECT_SOURCE_DIR}/Util/*.cpp"
        )

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

include_directories(${SDL2_INCLUDE_DIR})
link_directories("${YAMLCPP_INCLUDE_DIR}")

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC
        ${YAMLCPP_LIBRARY}
        ${SDL2_LIBRARY})
