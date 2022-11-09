#ifndef ANIMALRESERVE_RESERVE_H
#define ANIMALRESERVE_RESERVE_H
#include "utils.h"

class Reserve {
private:;
    int n_columns;
    int n_lines;
    int count_food;
    int count_animal;
    char **reserve_posx_posy;
public:
    Reserve(int columns = 0, int lines = 0);
    ~Reserve();
    int moveAnimal(int id,int next_line,int next_column);
    int spawn_food(int type_food);
};

#endif //ANIMALRESERVE_RESERVE_H
