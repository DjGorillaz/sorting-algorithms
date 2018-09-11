cmake_minimum_required(VERSION 3.8)

project(sort)

set(CXX_STANDARD 17)
set(CXX_STANDARTD_REQUIRED ON)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/include/)
add_subdirectory(tests)

#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)