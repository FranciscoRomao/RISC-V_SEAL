# WARNING - The name of this file CAN'T BE CHANGED.
# WARNING - This file may need changes in order to serve your purpose

# CMAKE VERSION_
cmake_minimum_required(VERSION 3.12) 

# PROJECT NAME [OPTIONAL]:
project(EXAMPLE)

# FIND SEAL VERSION:
find_package(SEAL 3.7 REQUIRED)


# TO SET DIFERENT DIRECTORY (e.g. yourdir) [OPTIONAL, BY DEFAULT: PROJECT DIRECTORY]:
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

# CHOOSE EXECUTABLE NAME (e.g exec)
add_executable(bench)

# ADD ALL SOURCE FILES TO BE COMPILED (e.g. exec.cpp)
target_sources(bench PRIVATE benchmarks.cpp )

# PRIVATE FLAG MAY BE CHANGED FOR PUBLIC OR INTERFACE
# SEE: https://cmake.org/pipermail/cmake/2016-May/063400.html


# LINK SEAL
target_link_libraries(bench SEAL::seal)
