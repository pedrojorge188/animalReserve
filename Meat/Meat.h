#ifndef ANIMALRESERVE_MEAT_H
#define ANIMALRESERVE_MEAT_H


#pragma once
#include "../utils.h"
#include "../Food.h"

class Meat: public Food {
public:
    Meat(int i, int row, int col);

    virtual bool die() override;

};


#endif //ANIMALRESERVE_MEAT_H
