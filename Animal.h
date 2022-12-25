#ifndef TERMINAL_CPP_ANIMAL_H
#define TERMINAL_CPP_ANIMAL_H
#include <utility>
#include "utils.h"

class Animal{

protected:
    char type;
    int id ;
    int row;
    int col;
    int iniHealth;
    int weight;
    int vitality;
    int hunger;
    string preferedSmell;
    string species;
public:
    Animal(int m_id, int m_row, int m_col);

    virtual ~Animal() = default;

    //Getters

    char getType() const {return type;}
    string getSpecies() const {return species;}
    int getId() const {return id;}
    int getIniHealth() const {return iniHealth;}
    int getPosX() const {return col;}
    int getPosY() const {return row;}
    int getWeight() const {return weight;}
    int getVitality() const {return vitality;}
    int getHunger() const {return hunger;}
    string getPreferedSmell() const {return preferedSmell;}

    //Setters

    void setVitality();

    void setWeight(int new_weight);

    virtual void setHealth();

    virtual void setHunger();

    //Actions

    virtual int move(int maxX, int maxY);

    virtual int eatFood() {return 0;}

    virtual int checkDie() {return 0;}

    ostringstream printInfo() const;
    ostringstream informations() const;
};



#endif //TERMINAL_CPP_ANIMAL_H