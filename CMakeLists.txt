cmake_minimum_required(VERSION 3.21)
project(animalReserve)

set(CMAKE_CXX_STANDARD 23)

add_executable(animalReserve main.cpp Reserve.cpp Reserve.h utils.h Simulator.cpp Simulator.h curses.h Terminal.cpp Terminal.h Food.cpp Food.h Animal.cpp Animal.h Rabbit/Rabbit.cpp Rabbit/Rabbit.h Sheep/Sheep.cpp Sheep/Sheep.h Wolf/Wolf.cpp Wolf/Wolf.h Kangaroo/Kangaroo.cpp Kangaroo/Kangaroo.h Mysterio/Mysterio.cpp Mysterio/Mysterio.h Grass/Grass.cpp Grass/Grass.h misteryFood/misteryFood.cpp misteryFood/misteryFood.h Body/Body.cpp Body/Body.h Carrot/Carrot.cpp Carrot/Carrot.h Meat/Meat.cpp Meat/Meat.h)

target_link_libraries(animalReserve C:/Users/luist/Desktop/POO_TP/PDCurses-3.9/wincon/pdcurses.a)
