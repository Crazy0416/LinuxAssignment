cmake_minimum_required(VERSION 3.10)
project(semprodcons)

set(CMAKE_CXX_STANDARD 11)

set(semlib_files semlib.cpp semlib.h)
add_library(semlib ${semlib_files})

add_executable(producer_s producer_s.cpp semlib)
add_executable(consumer_s consumer_s.cpp semlib)