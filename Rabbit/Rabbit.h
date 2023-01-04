#ifndef ANIMALRESERVE_RABBIT_H
#define ANIMALRESERVE_RABBIT_H
#include "../Animal.h"

class Rabbit : public Animal {
public:

    Rabbit(int mId, int mRow, int mCol);
    virtual int move(int maxX, int maxY, vector<Animal*>&_heavyAnimal,  vector<Food*> &_food);
    virtual void setHunger() override;
    virtual void setHealth() override;
    virtual bool reproduce() override;
    virtual pair <int,int>  sonSpawnLocation(pair<int,int> input) override;
    //virtual int eatFood() override;
    virtual pair <bool,bool> die() override;

    virtual Rabbit * const clone() const noexcept override;
private:
    int random;
    int reproduceTime;
    int reproduceRange;
};


#endif //ANIMALRESERVE_RABBIT_H
