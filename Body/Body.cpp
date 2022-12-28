#include "Body.h"

Body::Body(int i, int row, int col) : Food(i, row, col) {
    this->type = 'a';
    this->id = i;   this->row = row;
    this->col = col;  this->toxicity = 0;
    this->nutriValue = 0;
    this->duration = 1;     //infinita
    this->smell_1 = "carne";
    this->smell_2 = "nothing";
}

bool Body::die() {

    if(this->duration == 0) { return true; }

    return false;
}