cmake_minimum_required(VERSION 2.6)
project(hackerank)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "--std=c++11 -g")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# RELATIVE may makes it easier to extract an executable name.
file(GLOB PROBLEM_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/src/ src/*.cpp)

message(STATUS "List of problem files ${PROBLEM_SOURCES}")

foreach(problem_source_file ${PROBLEM_SOURCES})
   string(REPLACE ".cpp" "" problem_exec_name ${problem_source_file})
   message(STATUS "exec_name for '${problem_source_file}' = ${problem_exec_name}")
   add_executable(${problem_exec_name} src/${problem_source_file})
endforeach(problem_source_file ${PROBLEM_SOURCES})