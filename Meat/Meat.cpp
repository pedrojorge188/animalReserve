#include "Meat.h"

Meat::Meat(int i, int row, int col) : Food(i, row, col) {
    this->type = 'b';
    this->id = i;   this->row = row;
    this->col = col;  this->toxicity = 2;
    this->nutriValue = 10;
    this->duration = 30;
    this->smell_1 = "carne";
    this->smell_2 = "ketchup";
}

bool Meat::die() {

    if(this->duration == 0) { return true; }

    return false;
}