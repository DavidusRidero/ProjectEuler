cmake_minimum_required(VERSION 4.0)
project(ProjectEuler)

set(CMAKE_CXX_STANDARD 23)

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
)
