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

public:
    Animal(int m_id, int m_row, int m_col);

    virtual ~Animal() = default;

    //Getters

    char getType() const {return type;}
    int getId() const {return id;}
    int getIniHealth() const {return iniHealth;}
    int getPosX() const {return col;}
    int getPosY() const {return row;}
    int getWeight() const {return weight;}
    int getVitality() const {return vitality;}
    int getHunger() const {return hunger;}
    string getPreferedSmell() const {return preferedSmell;}

    //Setters

    void setHealth(int new_health_value);
    void setWeight(int new_weight);
    void setHunger(int new_hunger_value);

    //Actions

    virtual int move(int col, int row) {return 0;}

    virtual int eatFood() {return 0;}

    virtual int checkDie() {return 0;}

    ostringstream printInfo() const;
};

class Rabbit : public Animal {
public:

    Rabbit(int mId, int mRow, int mCol);
    //virtual int move(int col, int row) override ;
    //virtual int eatFood() override;
    //virtual int die() override;
    int reproduce();

private:
    int reproduceTime;
    int reproduceRange;
};

class Sheep : public Animal {
public:
    Sheep(int mId,int mRow,int mCol);
    //virtual int move(int col,int row) override;
    //virtual int eatFood() override;
    //virtual int die() override;
    int reproduceAction();
private:
    int reproduceTime;
    int reproduceLimit;
};

class Wolf : public Animal {
public:
    Wolf(int mId, int mRow, int mCol);
    //virtual int move(int col,int row) override;
    //virtual int eatFood() override;
    //virtual int die() override;

    int reproduce();
private:
    int randomSpawnInstance;
};

class Kangaroo : public Animal {
public:
    Kangaroo(int mId, int mRow, int mCol);

    //virtual int move(int col,int row) override;
    //virtual int eatFood() override;
    //virtual int die() override;
    int getBornPause() const {return bornPause;}
    int getAge() const {return age;}

    int reproduce();
    int incAge(); // increments age after turns

private:
    int reproduceTime;
    int reproduceRange;
    int bornPause;
    int age;
};

class Mysterio : public Animal {
public:
    Mysterio(int mId, int mRow, int mCol);

    //virtual int move(int col,int row) override;
    //virtual int eatFood() override;
    //virtual int die() override;
};





#endif //TERMINAL_CPP_ANIMAL_H