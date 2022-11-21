#ifndef TERMINAL_CPP_FOOD_H
#define TERMINAL_CPP_FOOD_H
#include "utils.h"

class Food{
    char type;
    int id;
protected:
    int duration;
    int nutriValue;
    int toxicity;
    string smell_1, smell_2;
public:
    Food(char t, int i, int d=0, int n=0, int to=0, string s1="nothing", string s2="nothing" ): type(t), id(i), duration(d), nutriValue(n), toxicity(to), smell_1(s1), smell_2(s2){}
    virtual ~Food() = default;

    char getType() const {return type;}
    int getId() const {return id;}
    int getDuration() const {return duration;}
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
    Relva(char type, int id): Food(type, id, 20, 3, 0, "erva", "verdura"){};
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


#endif //TERMINAL_CPP_FOOD_H
