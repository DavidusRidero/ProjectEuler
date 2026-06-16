cmake_minimum_required(VERSION 4.0)
project(ProjectEuler)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bfde-f8ed-47f2-aa78-d2afef7d6655")
set(CMAKE_CXX_MODULE_STD ON)

add_executable(ProjectEuler
        P0.cpp
        P1.cpp
        P2.cpp
        P3.cpp
        P4.cpp
        P5.cpp
        P6.cpp
        P7.cpp
        P8.cpp
        P9.cpp
        P10.cpp
        Helpers/primes.h
        Helpers/primes.cpp
        P11.cpp
        P12.cpp
        P13.cpp
        #        Helpers/primes.cppm
)
