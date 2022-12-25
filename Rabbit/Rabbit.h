#ifndef ANIMALRESERVE_RABBIT_H
#define ANIMALRESERVE_RABBIT_H
#include "../Animal.h"

class Rabbit : public Animal {
public:

    Rabbit(int mId, int mRow, int mCol);
    int move(int maxX, int maxY);
    void setHunger() override;
    void setHealth() override;
    //virtual int eatFood() override;
    bool die() override;
    int reproduce();

private:
    int random;
    int reproduceTime;
    int reproduceRange;
};


#endif //ANIMALRESERVE_RABBIT_H
