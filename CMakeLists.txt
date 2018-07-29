cmake_minimum_required(VERSION 3.5)
project(leet_code_tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-O0 -g -ggdb -fdiagnostics-color -pedantic")

find_package(Eigen3 REQUIRED NO_MODULE)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/catch2/)
enable_testing()

include_directories(SYSTEM ${CMAKE_SOURCE_DIR})
file(GLOB TESTS ./*/test.cpp)

add_executable(${PROJECT_NAME} test.cc ${TESTS})

include(ParseAndAddCatchTests)
ParseAndAddCatchTests(${PROJECT_NAME})
