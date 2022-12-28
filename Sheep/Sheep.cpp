
#include "Sheep.h"


Sheep::Sheep(int mId, int mRow, int mCol) : Animal(mId, mRow, mCol) {

    this->species = "Sheep";
    this->type = 'O';
    this->id = mId;
    this->row = mRow;
    this->col = mCol;
    this->preferedSmell = "erva";
    this->reproduceTime = 15;
    this->reproduceLimit = 12;
    this->perception = 3;

    random_device rd;
    mt19937 mt(rd());

    string::size_type sz;
    int maxValue=0, minValue=0;

    string data;
    ifstream fileConst;

    fileConst.open("../constants.txt");

    while (fileConst >> data) {

        if (data == "SOvelha") {

            fileConst >> data;
            iniHealth = stoi(data, &sz);

        } else if (data == "VOvelha") {

            fileConst >> data;
            vitality = stoi(data, &sz);

        } else if (data == "WOvelha") {

            fileConst >> data;
            minValue = stoi(data, &sz);
            fileConst >> data;
            maxValue = stoi(data, &sz);

            uniform_int_distribution<int> randomN(minValue, maxValue);
            weight = randomN(mt);
        }

    }
}

int Sheep::move(int maxX, int maxY, vector<Animal *> &_animals, vector<Food *> &_food) {


    int _start_col = this->col;
    int _start_row = this->row;

    random_device rd;
    mt19937 mt(rd());

    uniform_int_distribution<int> randomN(0, 3);

    int random = randomN(mt);

    int nSteps;

    if(hunger > 15){
        uniform_int_distribution<int> randomS(1, 2);
        nSteps = randomS(mt);
    }else{
        nSteps = 1;
    }

    pair <int,int> LimitMax (
            this->col + this->perception,
            this->row + this->perception
    );

    pair <int,int> LimitMin (
            this->col - this->perception,
            this->row - this->perception
    );


    if(random == 0){ col+=nSteps; }
    else if(random == 1){ col-=nSteps; }
    else if(random == 2){ row+=nSteps; }
    else if(random == 3){ row-=nSteps; }


    for (int i=0; i < _food.size(); i++){
        if(_food[i]->getPosX() <= LimitMax.first && _food[i]->getPosX() >= LimitMin.first){
            if(_food[i]->getPosY() <= LimitMax.second && _food[i]->getPosY() >= LimitMin.second){
                if(_food[i]->getSmell1() == this->preferedSmell || _food[i]->getSmell2() == this->preferedSmell){

                    if(_food[i]->getPosX() < this->getPosX())
                        col -= 1;
                    else if(_food[i]->getPosX() > this->getPosX())
                        col += 1;

                    if(_food[i]->getPosY() < this->getPosY())
                        row  -= 1;
                    else if(_food[i]->getPosY() > this->getPosY())
                        row += 1;

                    if(_food[i]->getPosX() == this->getPosX() && _food[i]->getPosY() == this->getPosY()){
                        this->iniHealth += _food[i]->getNutriValue();
                        this->iniHealth -= _food[i]->getToxicity();
                        _food[i]->setDuration(0);
                    }

                }
            }
        }
    }


    for (int i = 0 ; i < _animals.size() ; i++){
        if(_animals[i]->getPosX() <= LimitMax.first && _animals[i]->getPosX() >= LimitMin.first){
            if(_animals[i]->getPosY() <= LimitMax.second && _animals[i]->getPosY() >= LimitMin.second){
                if(_animals[i]->getWeight() >= 15){


                    if(_animals[i]->getPosX() < this->getPosX())
                        col = _start_col + 1;
                    else if(_animals[i]->getPosX() > this->getPosX())
                        col = _start_col - 1;
                    else if(_animals[i]->getPosY() < this->getPosY())
                        row = _start_row + 1;
                    else if(_animals[i]->getPosY() > this->getPosY())
                        row = _start_row - 1;

                }

            }
        }
    }

    if(col >= maxX){
        col = 0;
    }else if(row >= maxY){
        row = 0;
    }else if(row <= 0){
        row = maxY-1;
    }else if(col <= 0){
        col = maxX-1;
    }


    return 1;

}


void Sheep::setHunger() {
    this->hunger += 1;
}

void Sheep::setHealth() {

    if (this->hunger > 15)
        this->iniHealth -= 1;
    else if(this->hunger > 20)
        this->iniHealth -= 2;

}

pair <bool,bool> Sheep::die(){

    pair <bool,bool> _output (false,false);

    if( this->iniHealth == 0 || this->getVitality() == 0){
        _output.first = true;
        _output.second = true;
    }

    return _output;

}

pair <int,int> Sheep::sonSpawnLocation(pair<int,int> input) {

    pair <int,int> output;
    int row_coords = 0, col_coords = 0;

    random_device rd;
    mt19937 mt(rd());

    do{
        uniform_int_distribution<int> _row(this->row, (this->row + this->reproduceLimit));
        uniform_int_distribution<int> _col(this->col, (this->col + this->reproduceLimit));

        row_coords =  _row(mt);
        col_coords =  _col(mt);

    }while(row_coords >= input.second || col_coords >= input.first);

    output.first = row_coords;
    output.second = col_coords;

    return output;
}

bool Sheep::reproduce() {

    if( this->reproduceTime == 0 ){
        reproduceTime += 15;
        return true;

    }else{
        this->reproduceTime -= 1;
    }

    return false;

}
