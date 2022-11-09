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
    ~Reserve(){delete[]reserve_posx_posy;};

    char**getReserve() const {return reserve_posx_posy;}
    int getLines() const {return n_lines;};
    int getColumns() const {return n_columns;};

    //int moveAnimal(int id,int next_line,int next_column);
    //int spawn_food(int type_food);
};

#endif //ANIMALRESERVE_RESERVE_H
