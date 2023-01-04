
#ifndef ANIMALRESERVE_MYSTERIO_H
#define ANIMALRESERVE_MYSTERIO_H

#include "../Animal.h"

class Mysterio : public Animal {
private:
    int damage;

public:
    Mysterio(int mId, int mRow, int mCol);

    virtual int move(int maxX, int maxY, vector<Animal*>&_animals , vector<Food*>&_food);
    virtual void setHunger() override;
    virtual void setHealth() override;
    virtual pair <bool,bool> die() override;

    virtual Mysterio * const clone() const noexcept override;
};


#endif //ANIMALRESERVE_MYSTERIO_H
