cmake_minimum_required(VERSION 3.21)
project(clion)

include_directories("/usr/local/mysql-8.0.28-macos11-arm64/include")
include_directories("/usr/local/mysql-8.0.28-macos11-arm64/lib")



set(CMAKE_CXX_STANDARD 14)

add_executable(clion main.cpp DataStruct_Cpp/main_forDynamicArray.cpp DataStruct_Cpp/main_forDynamicArray.h DataStruct_Cpp/DynamicArray1.cpp DataStruct_Cpp/DynamicArray1.h SqlStudy/sql_test.cpp SqlStudy/sql_test.h)

target_link_libraries(clion /usr/local/mysql-8.0.28-macos11-arm64/lib/libmysqlclient.21.dylib)