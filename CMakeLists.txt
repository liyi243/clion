cmake_minimum_required(VERSION 3.21)
project(clion)

set(CMAKE_CXX_STANDARD 14)

add_executable(clion main.cpp DataStruct_Cpp/main_forDynamicArray.cpp DataStruct_Cpp/main_forDynamicArray.h DataStruct_Cpp/DynamicArray1.cpp DataStruct_Cpp/DynamicArray1.h)
