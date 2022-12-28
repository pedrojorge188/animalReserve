#ifndef TERMINAL_CPP_FOOD_H
#define TERMINAL_CPP_FOOD_H
#include <utility>
#include "utils.h"

class Food{
protected:
    char type;
    int id;
    int row;
    int col;
    int duration;
    int nutriValue;
    int toxicity;
    string smell_1, smell_2;
public:
    Food(int i, int row=0, int col=0);
    virtual ~Food() {cout << "Destroyed Food, id -> " << id << endl;};

    //GET'ERS
    char getType() const {return type;}
    int getId() const {return id;}
    int getDuration() const {return duration;}
    int getPosY() const {return row;}
    int getPosX() const {return col;}
    int getNutriValue() const {return nutriValue;}
    int getToxicity() const {return toxicity;}
    string getSmell1() const {return smell_1;}
    string getSmell2() const {return smell_2;}

    virtual void setDuration(){duration=this->duration-1;};
    void setDuration(int value){duration=value;}
    virtual void setNutriValue(){nutriValue=this->nutriValue;};
    virtual void setToxicity(){toxicity=this->toxicity;};

    virtual bool die() {return false;}

    virtual bool reproduce() {return false;}

    virtual pair<int,int> sonSpawnLocation(pair<int,int> input);

    ostringstream printInfo() const;
    ostringstream informations() const;
};

#endif //TERMINAL_CPP_FOOD_H
