cmake_minimum_required(VERSION 3.6) 

project(SEAL-RISCV_Benchmarks)

find_package(SEAL 3.7 REQUIRED)

add_executable(bench)
target_sources(bench PRIVATE benchmarks.cpp)

target_link_libraries(bench SEAL::seal)
