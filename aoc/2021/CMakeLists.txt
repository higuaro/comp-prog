cmake_minimum_required(VERSION 3.21)
project(aoc)

option(USE_CLANG "build application with clang" ON) # OFF is the default

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "--std=c++20")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# RELATIVE may makes it easier to extract an executable name.
file(GLOB PROBLEM_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

message(STATUS "List of problem files ${PROBLEM_SOURCES}")

foreach(problem_source_file ${PROBLEM_SOURCES})
    string(REPLACE ".cpp" "" problem_exec_name ${problem_source_file})
    message(STATUS "exec_name for '${problem_source_file}' = ${problem_exec_name}")
    add_executable(${problem_exec_name} ${problem_source_file})
endforeach(problem_source_file ${PROBLEM_SOURCES})
