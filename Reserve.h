#ifndef ANIMALRESERVE_RESERVE_H
#define ANIMALRESERVE_RESERVE_H
#include "utils.h"
#include "Animal.h"
#include "Rabbit/Rabbit.h"
#include "Kangaroo/Kangaroo.h"
#include "Mysterio/Mysterio.h"
#include "Sheep/Sheep.h"
#include "Wolf/Wolf.h"

#include "Food.h"
#include "Grass/Grass.h"
#include "Meat/Meat.h"
#include "Body/Body.h"
#include "Carrot/Carrot.h"
#include "misteryFood/misteryFood.h"

#define RABBIT 'c'
#define SHEEP 'o'
#define WOLF 'l'
#define KANGAROO 'g'
#define MYSTERIO 'm'

#define GRASS 'r'
#define CARROT 't'
#define BODY 'p'
#define MEAT 'b'
#define MISTERY_FOOD 'a'

class Reserve {
private:
    string r_name;
    int n_columns;
    int n_lines;
    int current_id_animal;
    int current_id_food;
    vector <Animal *> animals;
    vector <Food *> foods;
    char **reserve_posx_posy; //apenas uma representacao visual dos tipos de animal (caracteres)
public:
    Reserve(int columns = 16, int lines = 16);
    Reserve(Reserve& aux, string name);
    ~Reserve(){delete[]reserve_posx_posy;}

    //Getters
    int _getTotalAnimals() const;
    int _getTotalFood() const;
    int getCollums() const {return n_columns;}
    int getLines() const {return n_lines;}
    char **getReserve() const {return reserve_posx_posy;}
    string getReserveName() const {return r_name;}
    void setReserveName(string _new){this->r_name = _new;}


    //Global Actions ...

    bool cleanPositions(int row,int col);
    string watchPositionsInfo(int row, int col);


    //Actions for animals ....
    pair<string,string> spawnAnimal(int col,int row, char animalType);
    string _drawAnimalType(int id,int row, int col) const;

    int killAnimal(int row,int col);
    int killAnimal(int id);

    string animalsInReserve() const;
    string animalsInReserve(pair<int,int> range_y,pair<int,int> range_x) const;

    //Overload sintaxe ----
    string _feedAnimals(int row,int col,int nut_points,int tox_points);
    string _feedAnimals(int id,int nut_points,int tox_points);

    //Actions for food .....
    pair<string,string> spawnFood(int col,int row, char foodType);
    string _drawFoodType(int id,int row, int col) const;

    int killFood(int row,int col);
    int killFood(int id);

    string foodInReserve() const;

    string animalHistory(int id) const;


    void _newTurn();
};


#endif //ANIMALRESERVE_RESERVE_H
