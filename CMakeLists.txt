cmake_minimum_required(VERSION 3.8)

set(CXX_STANDARD 17)
set(CXX_STANDARTD_REQUIRED ON)

project(sort)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories(${PROJECT_SOURCE_DIR}/include/)

#add_subdirectory(benchmarks)
add_subdirectory(tests)