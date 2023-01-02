#include "Kangaroo.h"

//Kangaroo initializing defaults

Kangaroo::Kangaroo(int mId, int mRow, int mCol, int pId) : Animal(mId, mRow, mCol) {

    this->species = "Kangaroo";
    this->type = 'G';
    this->id = mId;
    this->row = mRow;
    this->col = mCol;
    this->reproduceTime = 30;
    this->reproduceRange = 3;
    this->bornPause = 5;
    this->perception = 7;
    this->age = 1;
    this->parentsId = pId;

    random_device rd;
    mt19937 mt(rd());

    string::size_type sz;
    int maxValue=0, minValue=0;

    string data;
    ifstream fileConst;

    fileConst.open("../constants.txt");

    while (fileConst >> data) {

        if (data == "SCanguru") {
            fileConst >> data;
            iniHealth = stoi(data, &sz);
        } else if (data == "VCanguru") {
            fileConst >> data;
            vitality = stoi(data, &sz);
        } else if (data == "WCanguru") {
            fileConst >> data;
            weight = stoi(data, &sz);
        }

    }
}

int Kangaroo::move(int maxX, int maxY, vector<Animal *> &_animals, vector<Food*>&_food) {

    random_device rd;
    mt19937 mt(rd());

    uniform_int_distribution<int> Direction(0, 3);

    int random = Direction(mt);
    int sonRand;
    int animalsToRun = 0;
    int foodToEat = 0;

    int nSteps ;

    if( this->hunger > 15 )
        nSteps = 2;
    else
        nSteps = 1;


    pair <int,int> LimitMax (col + perception, row + perception);
    pair <int,int> LimitMin (col - perception, row - perception);
    pair <int,int> sonMove;
    pair <int,int> _parentPosition ;

    for(auto i = _animals.begin(); i < _animals.end();i++) {
        if ((*i)->getType() == this->getType() && (*i)->getId() == this->parentsId) {
            _parentPosition.first = (*i)->getPosY();
            _parentPosition.second = (*i)->getPosX();
        }
    }


    for(int i = 0 ; i < _animals.size(); i++){
        if(_animals[i]->getPosX() < LimitMax.first && _animals[i]->getPosX() > LimitMin.first) {
            if (_animals[i]->getPosY() < LimitMax.second && _animals[i]->getPosY() > LimitMin.second) {

                if(this->age < 10) {
                    animalsToRun++;

                    if(this->parentsId != 0){
                        if(_parentPosition.first == this->row && _parentPosition.second == this->col){

                            if(bornPause == 0){
                                bornPause += 5;
                                col++; row++;
                            }else{
                                bornPause -= 1;
                                this->row  = _parentPosition.first;
                                this->col = _parentPosition.second;
                            }

                        }else if (_animals[i]->getType() == this->type && _animals[i]->getId() == this->parentsId) {

                            sonMove.first = _animals[i]->getPosX() + 4;
                            sonMove.second = _animals[i]->getPosY() + 4;

                            uniform_int_distribution<int> moveX(_animals[i]->getPosX(), sonMove.first);
                            uniform_int_distribution<int> moveY(_animals[i]->getPosY(), sonMove.second);

                            sonRand = moveX(mt);
                            if (sonRand < this->col) { this->col -= 1; }
                            else { this->col += 1; }

                            sonRand = moveY(mt);
                            if (sonRand < this->row) { this->row -= 1; }
                            else { this->row += 1; }

                        } else if (_animals[i]->getType() != this->type) {

                            if (_parentPosition.second < this->getPosX())
                                col -= 2;
                            else if (_parentPosition.second > this->getPosX())
                                col += 2;

                            if (_parentPosition.first < this->getPosY())
                                row -= 2;
                            else if (_parentPosition.first > this->getPosY())
                                row += 2;

                        }
                    }else{
                        animalsToRun=0;
                    }
                }else if(age > 20){
                    this->weight = 20;
                }

            }


        }

    }


    if(animalsToRun == 0){
        if(random == 0){ col+=nSteps; }
        else if(random == 1){ col-=nSteps; }
        else if(random == 2){ row+=nSteps; }
        else if(random == 3){ row-=nSteps; }
    }

    if(col >= maxX){
        col = maxX-1;
    }else if(row >= maxY){
        row = maxY-1;
    }else if(row <= 0){
        row = 0;
    }else if(col <= 0) {
        col = 0;
    }
    return 1;

}

void Kangaroo::setHealth() { this->age += 1; }

pair <bool,bool> Kangaroo::die(){

    pair <bool,bool> _output (false,false);

    //We also check initial health..
    if( this->iniHealth <= 0 || this->getVitality() == 0){
        _output.first = true;
        _output.second = true;
    }

    return _output;

}

pair <int,int> Kangaroo::sonSpawnLocation(pair<int,int> input) {

    pair <int,int> output;
    int row_coords , col_coords ;

    random_device rd;
    mt19937 mt(rd());

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

bool Kangaroo::reproduce() {

    if( this->reproduceTime == 0 ){
        reproduceTime += 30;
        return true;
    }else
        this->reproduceTime -= 1;


    return false;

}
