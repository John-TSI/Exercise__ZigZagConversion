cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(ZigZagConversion_6 VERSION 1.0.0)

set(SRC_FILES src/solution.cpp)
add_executable(ZigZagConversion_6 src/main.cpp ${SRC_FILES})

target_include_directories(ZigZagConversion_6 PUBLIC inc)

