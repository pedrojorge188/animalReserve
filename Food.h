#ifndef TERMINAL_CPP_FOOD_H
#define TERMINAL_CPP_FOOD_H
#include "utils.h"

class Food{
    char type;
    const int id;
protected:
    int row;
    int col;
    int duration;
    int nutriValue;
    int toxicity;
    string smell_1, smell_2;
public:
    Food(char t, int i,int row=0, int col=0, int d=0, int n=0, int to=0, string s1="nothing", string s2="nothing" );
    virtual ~Food() = default;

    char getType() const {return type;}
    int getId() const {return id;}
    int getDuration() const {return duration;}
    int getPosY() const {return row;}
    int getPosX() const {return col;}
    int getNutriValue() const {return nutriValue;}
    int getToxicity() const {return toxicity;}
    string getSmell1()  {return smell_1;}
    string getSmell2() const {return smell_2;}


    /*    void durationInfinity();
        void decrNutri();
        void incrToxy();
        void spawnMore();
    */
};

class Relva: public Food{
public:
    Relva(int id, int r, int c): Food('r', id, r, c){};
    //void decrNutri();
};

class Cenoura: public Food{
public:
    Cenoura(int id, int r, int c): Food('t', id, r, c){};
    //void incrToxy();
    //durationInfinity();
};

class Corpo: public Food{
public:
    Corpo(int id, int r, int c): Food('p', id, r, c){};
    //void decrNutri();
    //void incrToxy();
    //durationInfinity();
};

class Bife: public Food{
public:
    Bife(int id, int r, int c): Food('b', id, r, c){};
    //void decrNutri();
};

class MisteryFood: public Food{
public:
    MisteryFood(int id, int r, int c): Food('a', id, r, c){};
    //void decrNutri();
};


#endif //TERMINAL_CPP_FOOD_H
