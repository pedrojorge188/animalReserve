#ifndef TERMINAL_CPP_ANIMAL_H
#define TERMINAL_CPP_ANIMAL_H
#include <utility>

#include "utils.h"

class Animal{
    char type;
    const int id ;
protected:
    int row;
    int col;
    int iniHealth;
    int perception;
    int walkDistance;
    int weightMax;
    int weightMin;
    int vitality;
    int hunger;
    string preferedSmell;
    int interactWeight;
    int timeBorn;
    int deadBodyValue;

public:
    Animal(char t, int i,int row=0, int col=0, int in=0, int p=0, int w=0, int we1=0, int we2=0, int v=0, int h=0, string ps="nothing", int iw=0, int tb=0, int db=0);
    virtual ~Animal() = default;

    char getType() const {return type;}
    int getId() const {return id;}
    int getIniHealth() const {return iniHealth;}
    int getPosX() const {return col;}
    int getPosY() const {return row;}
    int getPerception() const {return perception;}
    int getWalkDistance() const {return walkDistance;}  //em alguns casos é 1 ou 2, n está implementado
    int getWeightMax() const {return weightMax;}
    int getWeightMin() const {return weightMin;}
    int getVitality() const {return vitality;}
    int getHunger() const {return hunger;}  //Implicaçoes ainda n implementadas
    string getPreferedSmell() const {return preferedSmell;}
    int getInteractWeight() const {return interactWeight;}
    int getTimeBorn() const {return timeBorn;}
    int getDeadBodyValue() const {return deadBodyValue;}
};

class Coelho: public Animal{
public:
    Coelho(int id, int r, int c): Animal('c',id, r, c){};
    //void chanceWalk();
    //void decrNutri();
};



#endif //TERMINAL_CPP_ANIMAL_H
