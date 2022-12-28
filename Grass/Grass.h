#ifndef ANIMALRESERVE_GRASS_H
#define ANIMALRESERVE_GRASS_H

#pragma once
#include "../utils.h"
#include "../Food.h"


class Grass: public Food{
protected:
    bool tried;
    int reproTime;
    int reproMin, reproMax;
public:
    Grass(int i, int row, int col);

    virtual bool reproduce() override;
    virtual pair <int,int>  sonSpawnLocation(pair<int,int> input) override;

    void setTried(){tried==true;}

    virtual bool die() override;
};


#endif //ANIMALRESERVE_GRASS_H
