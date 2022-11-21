#ifndef TERMINAL_CPP_ANIMAL_H
#define TERMINAL_CPP_ANIMAL_H
#include "utils.h"

class Animal{
    char type;
    int id;
protected:
    int iniHealthMin;
    int iniHealthMax;
    int perception;
    int walkDistance;
    int weight;
    int timeDeath;
    int hunger;
    string preferedSmell;
    int interactWeight;
    int timeBorn;
    int deadBodyValue;

public:
    Animal(char t, int i, int in1=0, int in2=0, int p=0, int w=0, int we=0, int tD=0, int h=0, string ps="nothing", int iw=0, int tb=0, int db=0): type(t), id(i), iniHealthMin(in1), iniHealthMax(in2), perception(p), walkDistance(w), weight(we), timeDeath(tD), hunger(h), preferedSmell(ps), interactWeight(iw), timeBorn(tb), deadBodyValue(db){}
    virtual ~Animal() = default;

    char getType() const{return type;}
    int getId() const{return id;}
    int getIniHealthMin() const{return iniHealthMin;}
    int getIniHealthMax() const{return iniHealthMax;}
    int getPerception() const{return perception;}
    int getWalkDistance() const{return walkDistance;}
    int getWeight() const{return weight;}
    int getTimeDeath() const{return timeDeath;}
    int getHunger() const{return hunger;}
    string getPreferedSmell() const{return preferedSmell;}
    int getInteractWeight() const{return interactWeight;}
    int getTimeBorn() const{return timeBorn;}
    int getDeadBodyValue() const{return deadBodyValue;}
};

class Coelho: public Animal{
public:
    Coelho(char type, int id): Animal(type, id, 20, 4, 1 ){};
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
