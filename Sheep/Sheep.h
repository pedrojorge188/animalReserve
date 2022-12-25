//
// Created by pedro on 25/12/2022.
//

#ifndef ANIMALRESERVE_SHEEP_H
#define ANIMALRESERVE_SHEEP_H

#include "../Animal.h"

class Sheep : public Animal {
public:
    Sheep(int mId,int mRow,int mCol);
    //virtual int move(int maxX, int maxY) override ;
    //virtual int eatFood() override;
    //virtual int die() override;
    int reproduceAction();
private:
    int reproduceTime;
    int reproduceLimit;
};

#endif //ANIMALRESERVE_SHEEP_H
