#ifndef ANIMALRESERVE_CARROT_H
#define ANIMALRESERVE_CARROT_H


#pragma once
#include "../utils.h"
#include "../Food.h"

class Carrot: public Food {
public:
    Carrot(int i, int row, int col);

    virtual bool die() override;

};


#endif //ANIMALRESERVE_CARROT_H
