#ifndef ANIMALRESERVE_BODY_H
#define ANIMALRESERVE_BODY_H


#pragma once
#include "../utils.h"
#include "../Food.h"

class Body: public Food {
public:
    Body(int i, int row, int col);

    virtual bool die() override;

};


#endif //ANIMALRESERVE_BODY_H
