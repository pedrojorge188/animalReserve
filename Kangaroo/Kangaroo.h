#ifndef ANIMALRESERVE_KANGAROO_H
#define ANIMALRESERVE_KANGAROO_H

#include "../Animal.h"

class Kangaroo : public Animal {
public:
    Kangaroo(int mId, int mRow, int mCol, int pId);

    virtual int move(int maxX, int maxY, vector<Animal*>&_animals , vector<Food*>&_food);
    virtual void setHealth() override;
    virtual bool reproduce() override;
    virtual pair <int,int>  sonSpawnLocation(pair<int,int> input) override;
    virtual pair <bool,bool> die() override;
    int getBornPause() const {return bornPause;}
    void setParentsId(int value) {this->parentsId = value;};
    int getAge() const {return age;}

    virtual Kangaroo * const clone() const noexcept override;

private:
    int reproduceTime;
    int reproduceRange;
    int parentsId;
    int bornPause;
    int age;
};


#endif //ANIMALRESERVE_KANGAROO_H
