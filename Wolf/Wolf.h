
#ifndef ANIMALRESERVE_WOLF_H
#define ANIMALRESERVE_WOLF_H

#include "../Animal.h"

class Wolf : public Animal {
public:

    Wolf(int mId, int mRow, int mCol);
    bool getReproduceStatus() {return  reproduceStatus;}
    virtual int move(int maxX, int maxY, vector<Animal*>&_animals , vector<Food*>&_food);
    virtual void setHunger() override;
    virtual void setHealth() override;
    virtual bool reproduce() override;
    virtual pair <int,int>  sonSpawnLocation(pair<int,int> input) override;
    virtual pair <bool,bool> die() override;

private:
    int random;
    int reproduceRange;
    bool reproduceStatus;
    int randomSpawnInstance;
};

#endif //ANIMALRESERVE_WOLF_H
