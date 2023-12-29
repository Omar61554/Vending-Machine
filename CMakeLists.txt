# cmake

cmake_minimum_required(VERSION 3.5.0)

project(vending_machine)

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # not necessary in cmake 3.11 and above 

add_library(MACHINE STATIC ${CMAKE_CURRENT_SOURCE_DIR}/Machine/Machine.cpp)
add_library(LIB STATIC ${CMAKE_CURRENT_SOURCE_DIR}/LIB/Products.cpp)
add_executable(vending_machine ${CMAKE_CURRENT_SOURCE_DIR}/SRC/main.cpp)

# include hpp files
target_include_directories(MACHINE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Machine)
target_include_directories(LIB PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/LIB)

target_link_libraries(vending_machine 
MACHINE 

LIB) # link libraries to executable file 
