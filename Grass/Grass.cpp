#include "Grass.h"

Grass::Grass(int i, int row, int col) : Food(i, row, col) {
    this->name = "relva";
    this->tried = false;
    this->reproMin = 4;
    this->reproMax = 8;
    this->reproTime = 5;
    this->type = 'r';
    this->id = i;   this->row = row;
    this->col = col;  this->toxicity = 0;
    this->nutriValue = 3;
    this->duration = 20;
    this->smell_1 = "erva";
    this->smell_2 = "verdura";
}

bool Grass::reproduce() {

    if(this->duration == this->reproTime){
        return true;
    }else{
        return false;
    }
}

pair<int, int> Grass::sonSpawnLocation(pair<int, int> input) {

    pair <int,int> output;
    int row_coords = 0, col_coords = 0;

    random_device rd;
    mt19937 mt(rd());

    //uniform_int_distribution<int> _spawn(0,100);

    do{
        do{
            uniform_int_distribution<int> _rowMax((this->row - this->reproMax), (this->row + this->reproMax));
            uniform_int_distribution<int> _colMax((this->col - this->reproMax), (this->col + this->reproMax));

            row_coords =  _rowMax(mt);
            col_coords =  _colMax(mt);
        }while(row_coords <= ((this->row + this->reproMin) && row_coords >= (this->row - this->reproMin)) || (col_coords <= (this->col + this->reproMin) && col_coords >= (this->col - this->reproMin)));
    }while(row_coords >= input.second || col_coords >= input.first || row_coords <= 0 || col_coords <= 0);

    output.first = row_coords;
    output.second = col_coords;

    return output;

}

bool Grass::die() {

    if(this->duration == 0) { return true; }

    return false;
}

Grass *const Grass::clone() const noexcept {
    return new (std::nothrow) Grass(*this);
}