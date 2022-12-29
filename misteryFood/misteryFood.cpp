#include "misteryFood.h"
//Erva venenosa

misteryFood::misteryFood(int i, int row, int col) : Food(i, row, col) {
    this->type = 'a';
    this->name = "comidaMisterio";
    this->id = i;   this->row = row;
    this->col = col;  this->toxicity = 10;
    this->nutriValue = 0;
    this->duration = 30;
    this->smell_1 = "erva";
    this->smell_2 = "verdura";
}

bool misteryFood::die() {

    if(this->duration == 0) { return true; }

    return false;
}
