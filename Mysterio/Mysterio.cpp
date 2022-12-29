
#include "Mysterio.h"


Mysterio::Mysterio(int mId, int mRow, int mCol) : Animal(mId, mRow, mCol) {

    this->type = 'M';
    this->species = "Mysterio";
    this->perception = 3;
    this->damage = 10;
    this->id = mId;
    this->row = mRow;
    this->col = mCol;

    random_device rd;
    mt19937 mt(rd());

    string::size_type sz;
    int maxValue=0, minValue=0;

    string data;
    ifstream fileConst;

    fileConst.open("../constants.txt");

    while (fileConst >> data) {

        if (data == "SMisterio") {
            fileConst >> data;
            iniHealth = stoi(data, &sz);
        } else if (data == "VMisterio") {
            fileConst >> data;
            vitality = stoi(data, &sz);
        } else if (data == "WMisterio") {
            fileConst >> data;
            weight = stoi(data, &sz);
        }

    }
}


int Mysterio::move(int maxX, int maxY, vector<Animal *> &_animals, vector<Food*>&_food) {

    random_device rd;
    mt19937 mt(rd());

    uniform_int_distribution<int> Direction(0, 3);

    int random = Direction(mt);
    int animalsToHunt = 0;

    int nSteps = 1;

    pair <int,int> LimitMax (col + perception, row + perception);
    pair <int,int> LimitMin (col - perception, row - perception);

    for(int i = 0 ; i < _animals.size(); i++){
        if(_animals[i]->getType() != this->type){

            animalsToHunt++;

            if(_animals[i]->getPosX() < LimitMax.first && _animals[i]->getPosX() > LimitMin.first){
                if(_animals[i]->getPosY() < LimitMax.second && _animals[i]->getPosY() > LimitMin.second){

                    if(_animals[i]->getPosX() < this->getPosX())
                        col -= 1;
                    else if(_animals[i]->getPosX() > this->getPosX())
                        col += 1;

                    if(_animals[i]->getPosY() < this->getPosY())
                        row  -= 1;
                    else if(_animals[i]->getPosY() > this->getPosY())
                        row += 1;

                    if(_animals[i]->getPosX() == this->getPosX()+1 || _animals[i]->getPosY() == this->getPosY()+1
                    ||_animals[i]->getPosX() == this->getPosX()-1 || _animals[i]->getPosY() == this->getPosX()-1){

                        int _lifeSteal = _animals[i]->getIniHealth()-damage;

                        if(_lifeSteal < 0){
                            _lifeSteal = 0;
                            this->iniHealth -= 2;
                        }

                        _animals[i]->setHealth(_lifeSteal);

                    }
                }

            }else{

                if(random == 0){ col+=nSteps; }
                else if(random == 1){ col-=nSteps; }
                else if(random == 2){ row+=nSteps; }
                else if(random == 3){ row-=nSteps; }

            }
        }

    }



    if(animalsToHunt == 0 ){
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
    }else if(col <= 0){
        col = 0;
    }
    return 1;
}

void Mysterio::setHunger() {
    this->hunger = this->hunger;
}

void Mysterio::setHealth() {this->iniHealth -= 1;}

pair <bool,bool> Mysterio::die(){

    pair <bool,bool> _output (false,false);

    if( this->iniHealth <= 0 || this->getVitality() == 0){
        _output.first = true;
    }

    return _output;

}

