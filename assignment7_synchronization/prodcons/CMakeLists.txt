cmake_minimum_required(VERSION 3.10)
project(prodcons)

set(CMAKE_CXX_STANDARD 11)

add_executable(consumer consumer.cpp)
add_executable(producer producer.cpp prodcons.h)