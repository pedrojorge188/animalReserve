#ifndef ANIMALRESERVE_BODY_H
#define ANIMALRESERVE_BODY_H


#pragma once
#include "../utils.h"
#include "../Food.h"

class Body: public Food {
private:
    int inst;
    int nutrIni;
public:
    Body(int i, int row, int col, int tox, int nutr);

    virtual bool die() override;
    virtual void setDuration() override {this->duration=this->duration;}
    virtual void setNutriValue() override;
    virtual void setToxicity() override;

};


#endif //ANIMALRESERVE_BODY_H