
#ifndef ANIMALRESERVE_MYSTERIO_H
#define ANIMALRESERVE_MYSTERIO_H

#include "../Animal.h"

class Mysterio : public Animal {
public:
    Mysterio(int mId, int mRow, int mCol);

    //virtual int move(int maxX, int maxY) override ;
    //virtual int eatFood() override;
    //virtual int die() override;
};


#endif //ANIMALRESERVE_MYSTERIO_H
