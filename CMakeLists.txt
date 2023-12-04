# cmake

cmake_minimum_required(VERSION 3.28.0)

project(vending machine)

set(SRC_Files

                    )  // set variables here 

message("SRC_Files: ${SRC_Files}") // print variables 

add_executable(vending machine ${SRC_Files})

target_include_directories(cmake_test PUBLIC LIB/ )