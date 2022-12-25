#ifndef ANIMALRESERVE_RESERVE_H
#define ANIMALRESERVE_RESERVE_H
#include "utils.h"
#include "Animal.h"
#include "Rabbit/Rabbit.h"
#include "Kangaroo/Kangaroo.h"
#include "Mysterio/Mysterio.h"
#include "Sheep/Sheep.h"
#include "Wolf/Wolf.h"

#define RABBIT 'c'
#define SHEEP 'o'
#define WOLF 'l'
#define KANGAROO 'g'
#define MYSTERIO 'm'

class Reserve {
private:
    int n_columns;
    int n_lines;
    int current_id;
    vector <Animal *> animals;
    char **reserve_posx_posy; //apenas uma representacao visual dos tipos de animal (caracteres)
public:
    Reserve(int columns = 16, int lines = 16);
    Reserve(Reserve& aux);
    ~Reserve(){delete[]reserve_posx_posy;}

    //Getters
    int _getTotalAnimals() const;
    int getCollums() const {return n_columns;}
    int getLines() const {return n_lines;}
    char **getReserve() const {return reserve_posx_posy;}

    //Actions for animals ....
    pair<string,string> spawnAnimal(int col,int row, char animalType);
    string _drawAnimalType(int id,int row, int col) const;

    int killAnimal(int row,int col);
    int killAnimal(int id);

    string animalsInReserve() const;
    void _newTurn();
};


#endif //ANIMALRESERVE_RESERVE_H
