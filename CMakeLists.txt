cmake_minimum_required(VERSION 3.29.6)
project(Lab2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab2 main.cpp
        Currency.h
        DrachmaCurrency.h
        PesoCurrency.h)
