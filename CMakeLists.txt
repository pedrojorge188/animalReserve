cmake_minimum_required(VERSION 3.21)
project(animalReserve)

set(CMAKE_CXX_STANDARD 23)

add_executable(animalReserve main.cpp Reserve.cpp Reserve.h utils.h Simulator.cpp Simulator.h curses.h Terminal.cpp Terminal.h Animal.cpp Animal.h Food.cpp Food.h)

target_link_libraries(animalReserve C:/Users/luist/Desktop/POO_TP/PDCurses-3.9/wincon/pdcurses.a)