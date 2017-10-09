cmake_minimum_required(VERSION 2.8)

project(uva)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")

set(COMPILER_FLAG_ENABLE_CPP11  "--std=c++11")
set(COMPILER_FLAG_DEBUG         "-g")
set(COMPILER_FLAG_WARNINGS      "-Wall")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILER_FLAG_ENABLE_CPP11} ${COMPILER_FLAG_DEBUG} ${COMPILER_FLAG_WARNINGS}" )

FILE(GLOB solutions RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

foreach(solution ${solutions})
    message(STATUS "Processing file: '${solution}'")

    # Generate solution exe name
    string(REGEX REPLACE ".cpp\$" "" solutionExe "${solution}")

    MESSAGE(STATUS "Generating target for solution: ${solutionExe}")
    add_executable(${solutionExe} ${solution})

endforeach(solution)