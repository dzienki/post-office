cmake_minimum_required(VERSION 3.12)
project(poczta)

set(CMAKE_CXX_STANDARD 14)

add_executable(poczta main.cpp client.cpp postoffice.cpp)