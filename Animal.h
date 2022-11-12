#ifndef ANIMALRESERVE_ANIMAL_H
#define ANIMALRESERVE_ANIMAL_H

#include "utils.h"

#define NUMBER_ANIMALS 5

class Animal {
    char type;
    int id;
protected:
    int IniLife;
    int Senses;
    int Walk[2];
    int Weight;

public:
    Animal(char letter): type(letter){}

    int setIniLife();
    int setSenses();
    int setWalk();
    int setHeight();
    //char getAnimal(string type);
};


#endif
