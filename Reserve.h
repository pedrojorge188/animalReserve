#ifndef ANIMALRESERVE_RESERVE_H
#define ANIMALRESERVE_RESERVE_H
#include "utils.h"

class Reserve {
private:;
    int n_columns;
    int n_lines;
    char **reserve_posx_posy; //apenas uma representacao visual dos tipos de animal (caracteres)
public:
    Reserve(int columns = 16, int lines = 16);
    Reserve(Reserve& aux);
    ~Reserve(){delete[]reserve_posx_posy;}
    char **getReserve() const {return reserve_posx_posy;}
    int getCollums() const {return n_columns;}
    int getLines() const {return n_lines;}

};


#endif //ANIMALRESERVE_RESERVE_H
