#ifndef ANIMALRESERVE_SHEEP_H
#define ANIMALRESERVE_SHEEP_H

#include "../Animal.h"

class Sheep : public Animal {
public:
    Sheep(int mId,int mRow,int mCol);
    virtual int move(int maxX, int maxY, vector<Animal*>&_animals , vector<Food*>&_food);
    virtual void setHunger() override;
    virtual void setHealth() override;
    virtual bool reproduce() override;
    virtual pair <int,int>  sonSpawnLocation(pair<int,int> input) override;
    //virtual int eatFood() override;
    virtual pair <bool,bool> die() override;
private:
    int reproduceTime;
    int random;
    int reproduceRange;
    int inst;
};

#endif //ANIMALRESERVE_SHEEP_H
