//
// Created by pedro on 25/12/2022.
//

#ifndef ANIMALRESERVE_WOLF_H
#define ANIMALRESERVE_WOLF_H

#include "../Animal.h"

class Wolf : public Animal {
public:
    Wolf(int mId, int mRow, int mCol);
    //virtual int move(int maxX, int maxY) override ;
    //virtual int eatFood() override;
    //virtual int die() override;

    int reproduce();
private:
    int randomSpawnInstance;
};

#endif //ANIMALRESERVE_WOLF_H
