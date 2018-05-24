cmake_minimum_required(VERSION 3.10)
project(prodconsThread)

set(CMAKE_CXX_STANDARD 11)

add_executable(prodconsThread main.cpp prodcons.h)

TARGET_LINK_LIBRARIES( prodconsThread
        pthread
        )