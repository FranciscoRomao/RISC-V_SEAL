cmake_minimum_required(VERSION 3.6) 

project(riscv-generic)

find_package(SEAL 3.7 REQUIRED)

add_executable(main)
target_sources(main PRIVATE main.cpp)

target_link_libraries(main SEAL::seal)
