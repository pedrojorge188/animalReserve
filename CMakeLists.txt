cmake_minimum_required(VERSION 3.21)
project(animalReserve)

set(CMAKE_CXX_STANDARD 23)

add_executable(animalReserve main.cpp Reserve.cpp Reserve.h utils.h Animal.cpp Animal.h)
