# cmake

cmake_minimum_required(VERSION 3.0.0)

project(vending_machine)

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # not necessary in cmake 3.11 and above 
set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

add_library(MACHINE STATIC ${CMAKE_CURRENT_SOURCE_DIR}/Machine/Machine.cpp)
add_library(LIB STATIC ${CMAKE_CURRENT_SOURCE_DIR}/LIB/Products.cpp)
add_library(GUI STATIC ${CMAKE_CURRENT_SOURCE_DIR}/_GUI/VendingMachineGUI.cpp)
add_executable(vending_machine ${CMAKE_CURRENT_SOURCE_DIR}/SRC/main.cpp)

# include hpp files
target_include_directories(MACHINE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Machine)
target_include_directories(LIB PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/LIB)
target_include_directories(LIB PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/_GUI)

target_link_libraries(vending_machine 
MACHINE 

LIB

GUI
) # link libraries to executable file 
