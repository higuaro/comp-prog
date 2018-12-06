cmake_minimum_required(VERSION 2.6)
project(code_forces)

option(USE_CLANG "build application with clang" ON) # OFF is the default

if(USE_CLANG)
    SET (CMAKE_CXX_FLAGS_INIT                "-Wall")
    SET (CMAKE_CXX_FLAGS_DEBUG_INIT          "-g")
    SET (CMAKE_CXX_FLAGS_MINSIZEREL_INIT     "-Os -DNDEBUG")
    SET (CMAKE_CXX_FLAGS_RELEASE_INIT        "-O4 -DNDEBUG")
    SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT "-O2 -g")
endif(USE_CLANG)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "--std=c++14 -g")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# RELATIVE may makes it easier to extract an executable name.
file(GLOB PROBLEM_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/ *.cpp)

message(STATUS "List of problem files ${PROBLEM_SOURCES}")

foreach(problem_source_file ${PROBLEM_SOURCES})
    string(REPLACE ".cpp" "" problem_exec_name ${problem_source_file})
    message(STATUS "exec_name for '${problem_source_file}' = ${problem_exec_name}")
    add_executable(${problem_exec_name} ${problem_source_file})
endforeach(problem_source_file ${PROBLEM_SOURCES})
