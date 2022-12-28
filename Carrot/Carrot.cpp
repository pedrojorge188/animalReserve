#include "Carrot.h"

Carrot::Carrot(int i, int row, int col) : Food(i, row, col) {
    this->type = 't';
    this->id = i;   this->row = row;
    this->col = col;  this->toxicity = 0;
    this->nutriValue = 4;
    this->duration = 1;     //infinita
    this->smell_1 = "verdura";
    this->smell_2 = "nothing";
    this->inst=0;
}

bool Carrot::die() {

    if(this->duration == 0) { return true; }

    return false;
}

void Carrot::setToxicity() {
    inst++;
    if(inst%10==0 && this->toxicity < 3){
        this->toxicity += 1;
    }
}
