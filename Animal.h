#ifndef TERMINAL_CPP_ANIMAL_H
#define TERMINAL_CPP_ANIMAL_H
#include <utility>

#include "utils.h"

class Animal{
    char type;
    const int id ;
protected:
    int random;
    int row;
    int col;
    int iniHealth;
    int perception;
    int weight;
    int vitality;
    int hunger;
    string preferedSmell;
    int interactWeight;
    int timeBorn;
    int deadBodyValue;

public:
    Animal(char t, int i,int row=0, int col=0, int in=0, int p=0, int we=0, int v=0, int h=0, string ps="nothing", int iw=0, int tb=0, int db=0);
    virtual ~Animal() = default;

    char getType() const {return type;}
    int getId() const {return id;}
    int getIniHealth() const {return iniHealth;}
    int getPosX() const {return col;}
    int getPosY() const {return row;}
    int getPerception() const {return perception;}
    int getWeight() const {return weight;}
    int getVitality() const {return vitality;}
    int getHunger() const {return hunger;}  //Implicaçoes ainda n implementadas
    string getPreferedSmell() const {return preferedSmell;}
    int getInteractWeight() const {return interactWeight;}
    int getTimeBorn() const {return timeBorn;}
    int getDeadBodyValue() const {return deadBodyValue;}

    void moveAnimal(int maxX, int maxY);
};


class Coelho: public Animal{
public:
    Coelho(int id, int r, int c): Animal('c',id, r, c, 4, 0, 0, 0, 1, "verdura", 10, 8, 1){};
    //void chanceWalk();
    //void decrNutri();
};

class Ovelha: public Animal{
public:
    Ovelha(int id, int r, int c): Animal('o',id, r, c, 3, 0, 0, 0, 1, "erva", 15, 15, 4){};
    //void chanceWalk();
    //void decrNutri();
};

class Lobo: public Animal{
public:
    Lobo(int id, int r, int c): Animal('l',id, r, c, 5, 0, 0, 0, 2, "carne", 15, 5, 10){};
    //void chanceWalk();
    //void decrNutri();
};

class Canguru: public Animal{
public:
    Canguru(int id, int r, int c): Animal('g',id, r, c, 7, 0, 0, 0, 1, "nothing", 0, 30, 15){};
    //void chanceWalk();
    //void decrNutri();
};

class MisteryAnimal: public Animal{
public:
    MisteryAnimal(int id, int r, int c): Animal('m',id, r, c, 4, 0, 0, 0, 1, "verdura", 10, 8, 1){};
    //void chanceWalk();
    //void decrNutri();
};



#endif //TERMINAL_CPP_ANIMAL_H
