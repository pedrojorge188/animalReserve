#ifndef ANIMALRESERVE_RESERVE_H
#define ANIMALRESERVE_RESERVE_H
#include "utils.h"

class Reserve {
private:;
    int n_columns;
    int n_lines;
    char **reserve_posx_posy;
public:
    Reserve(int columns = 16, int lines = 16);
    Reserve(Reserve& aux);
    ~Reserve(){delete[]reserve_posx_posy;}
    char **getReserve() const {return reserve_posx_posy;}

    //bool moveAnimal(int id,int next_line,int next_column);
    //int spawn_food(int type_food);
};

#endif //ANIMALRESERVE_RESERVE_H
