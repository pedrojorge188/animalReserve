#ifndef ANIMALRESERVE_MISTERYFOOD_H
#define ANIMALRESERVE_MISTERYFOOD_H

#pragma once
#include "../utils.h"
#include "../Food.h"

class misteryFood: public Food {
public:
    misteryFood(int i, int row, int col);

    virtual bool die() override;

};


#endif //ANIMALRESERVE_MISTERYFOOD_H
