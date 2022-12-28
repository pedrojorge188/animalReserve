#include "misteryFood.h"

misteryFood::misteryFood(int i, int row, int col) : Food(i, row, col) {
    this->type = 'a';
    this->id = i;   this->row = row;
    this->col = col;  this->toxicity = 0;
    this->nutriValue = 0;
    this->duration = 0;
    this->smell_1 = "nothing";
    this->smell_2 = "nothing";
}

bool misteryFood::die() {

    if(this->duration == 0) { return true; }

    return false;
}
