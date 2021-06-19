cmake_minimum_required(VERSION 3.16)
project(LenorsUI)

set(CMAKE_CXX_STANDARD 14)

add_executable(LenorsUI main.cpp main.h GLOBALINCLUDE.h UI.cpp UI.h PageManager.cpp PageManager.h)