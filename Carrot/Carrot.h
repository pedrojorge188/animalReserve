#ifndef ANIMALRESERVE_CARROT_H
#define ANIMALRESERVE_CARROT_H


#pragma once
#include "../utils.h"
#include "../Food.h"

class Carrot: public Food {
protected:
    int inst;
public:
    Carrot(int i, int row, int col);

    virtual bool die() override;

    virtual void setDuration() override {this->duration=this->duration;};
    virtual void setToxicity() override;

};


#endif //ANIMALRESERVE_CARROT_H
