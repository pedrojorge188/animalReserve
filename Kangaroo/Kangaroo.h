//
// Created by pedro on 25/12/2022.
//

#ifndef ANIMALRESERVE_KANGAROO_H
#define ANIMALRESERVE_KANGAROO_H

#include "../Animal.h"

class Kangaroo : public Animal {
public:
    Kangaroo(int mId, int mRow, int mCol);

    //virtual void move(int maxX, int maxY) override ;
    //virtual int eatFood() override;
    //virtual int die() override;
    int getBornPause() const {return bornPause;}
    int getAge() const {return age;}

    int incAge(); // increments age after turns

private:
    int reproduceTime;
    int reproduceRange;
    int bornPause;
    int age;
};


#endif //ANIMALRESERVE_KANGAROO_H
