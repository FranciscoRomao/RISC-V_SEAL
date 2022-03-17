cmake_minimum_required(VERSION 3.6) 

project(SEAL-RISCV_Profiling)

find_package(SEAL 3.7 REQUIRED)

add_executable(prof)
target_sources(prof PRIVATE profiling.cpp)

target_link_libraries(prof SEAL::seal)
