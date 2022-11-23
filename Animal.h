#ifndef TERMINAL_CPP_ANIMAL_H
#define TERMINAL_CPP_ANIMAL_H
#include <utility>

#include "utils.h"

class Animal{
    char type;
    const int id ;
protected:
    int iniHealth;
    int perception;
    int walkDistance;
    int weight;
    int vitality;
    int hunger;
    string preferedSmell;
    int interactWeight;
    int timeBorn;
    int deadBodyValue;

public:
    Animal(char t, int i, int in=0, int p=0, int w=0, int we=0, int v=0, int h=0, string ps="nothing", int iw=0, int tb=0, int db=0);
    virtual ~Animal() = default;

    char getType() const {return type;}
    int getId() const {return id;}
    int getIniHealth() const {return iniHealth;}
    int getPerception() const {return perception;}
    int getWalkDistance() const {return walkDistance;}  //em alguns casos é 1 ou 2, n está implementado
    int getWeight() const {return weight;}
    int getVitality() const {return vitality;}
    int getHunger() const {return hunger;}  //Implicaçoes ainda n implementadas
    string getPreferedSmell() const {return preferedSmell;}
    int getInteractWeight() const {return interactWeight;}
    int getTimeBorn() const {return timeBorn;}
    int getDeadBodyValue() const {return deadBodyValue;}
};

/*
class Coelho: public Animal{
public:
    Coelho(int id, int health, int vitality): Animal('C', id, health, 4, 1, 1, 4, vitality, 1, "verdura"){};
    //void chanceWalk();
    //void decrNutri();
};


class Cenoura: public Food{
public:
    Cenoura(char type, int id): Food(type, id, 999, 4, 1, "verdura", "nothing"){};
    //void incrToxy();
    //durationInfinity();
};

class Corpo: public Food{
public:
    Corpo(char type, int id): Food(type, id, 999, 0, 0, "carne", "nothing"){};
    //void decrNutri();
    //void incrToxy();
    //durationInfinity();
};

class Bife: public Food{
public:
    Bife(char type, int id): Food(type, id, 30, 10, 2, "carne", "ketchup"){};
    //void decrNutri();
};

/*class Alimento_misterio: public Food{
public:
    Alimento_misterio(char type, int id): Food(type, id, 20, 3, 0, "erva", "verdura"){};
    //void decrNutri();
};*/

#endif //TERMINAL_CPP_ANIMAL_H
