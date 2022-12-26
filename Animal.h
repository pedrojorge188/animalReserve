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
    int perception;
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
    int getPerception() const {return perception;}
    int getHunger() const {return hunger;}
    string getPreferedSmell() const {return preferedSmell;}


    void setVitality();

    ostringstream printInfo() const;

    ostringstream informations() const;

    void setWeight(int new_weight);

    virtual void setHealth();

    void setHealth(int value){this->iniHealth = value;}

    virtual void setHunger();

    virtual int move(int maxX, int maxY, vector<Animal*> &_animal);

    virtual int eatFood() {return 0;}

    virtual pair <bool,bool> die() ;

    virtual bool reproduce() {return false;}

    virtual pair<int,int> sonSpawnLocation(pair<int,int> input);

};



#endif //TERMINAL_CPP_ANIMAL_H