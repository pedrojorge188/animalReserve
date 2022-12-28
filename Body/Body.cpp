#include "Body.h"

Body::Body(int i, int row, int col, int tox, int nutr) : Food(i, row, col) {
    this->type = 'p';
    this->id = i;   this->row = row;
    this->col = col;  this->toxicity = tox;
    this->nutriValue = nutr;
    this->duration = 1;     //infinita
    this->smell_1 = "carne";
    this->smell_2 = "nothing";
    this->inst = 0;
    this->nutrIni = nutr;
}

bool Body::die() {

    if(this->duration == 0) { return true; }

    return false;
}

void Body::setNutriValue() {
    if(this->nutriValue > 0){
        this->nutriValue -= 1;
    }
}

void Body::setToxicity() {
    inst++;
    if(this->inst <= 2*nutrIni){
        this->toxicity += 1;
    }
}