
#include "Rabbit.h"

Rabbit::Rabbit(int mId, int mRow, int mCol) : Animal(mId, mRow, mCol) {

    this->species = "Rabbit";
    this->type = 'C';
    this->id = mId;
    this->row = mRow;
    this->col = mCol;
    this->preferedSmell = "verdura";
    this->reproduceTime = 8;
    this->reproduceRange = 10;
    this->perception = 4;

    random_device rd;
    mt19937 mt(rd());

    string::size_type sz;
    int maxValue=0, minValue=0;

    string data;
    ifstream fileConst;

    fileConst.open("../constants.txt");

    while (fileConst >> data) {

        if (data == "SCoelho") {

            fileConst >> data;
            iniHealth = stoi(data, &sz);

        } else if (data == "VCoelho") {

            fileConst >> data;
            vitality = stoi(data, &sz);

        } else if (data == "WCoelho") {

            fileConst >> data;
            minValue = stoi(data, &sz);
            fileConst >> data;
            maxValue = stoi(data, &sz);

            uniform_int_distribution<int> randomN(minValue, maxValue);
            weight = randomN(mt);
        }

    }
}

int Rabbit::move(int maxX, int maxY, vector<Animal*>&_rabbit) {

    int _start_col = this->col;
    int _start_row = this->row;

    random_device rd;
    mt19937 mt(rd());

    uniform_int_distribution<int> randomN(0, 3);

    random = randomN(mt);

    int nSteps;

    if(hunger > 20){
        uniform_int_distribution<int> randomS(1, 4);
        nSteps = randomS(mt);
    }else if(hunger > 10){
        uniform_int_distribution<int> randomS(1, 3);
        nSteps = randomS(mt);
    }else{
        uniform_int_distribution<int> randomS(1, 2);
        nSteps = randomS(mt);
    }

    if(random == 0){ col+=nSteps; }
    else if(random == 1){ col-=nSteps; }
    else if(random == 2){ row+=nSteps; }
    else if(random == 3){ row-=nSteps; }


    if(col >= maxX){
        col = 1;
    }else if(row >= maxY){
        row = 1;
    }else if(row <= 1){
        row = maxY-1;
    }else if(col <= 1){
        col = maxX-1;
    }


    return 1;
}

void Rabbit::setHunger() {this->hunger += 1;}

void Rabbit::setHealth() {

    if(this->hunger > 10)
        this->iniHealth -= 1;
    else if(this->hunger > 20)
        this->iniHealth -= 2;

}

bool Rabbit::die() {

    if(this->vitality == 0) { return true; }
    else if(this->iniHealth == 0) { return true; }

    return false;
}

pair <int,int> Rabbit::sonSpawnLocation(pair<int,int> input) {

    pair <int,int> output;
    int row_coords = 0, col_coords = 0;

    random_device rd;
    mt19937 mt(rd());

    uniform_int_distribution<int> _spawn(0,100);

    do{
        uniform_int_distribution<int> _row(this->row, (this->row + this->reproduceRange));
        uniform_int_distribution<int> _col(this->col, (this->col + this->reproduceRange));

        row_coords =  _row(mt);
        col_coords =  _col(mt);

    }while(row_coords >= input.second || col_coords >= input.first);

    output.first = row_coords;
    output.second = col_coords;

    return output;
}

bool Rabbit::reproduce() {

    int _spawn_;

    random_device rd;
    mt19937 mt(rd());

    uniform_int_distribution<int> _spawn(0,100);
    _spawn_ = _spawn(mt);

    if(this->reproduceTime == 0){
        reproduceTime += 8;
        if(_spawn_ >= 50)
            return true;
    }
    else
        reproduceTime--;

    return false;

}



