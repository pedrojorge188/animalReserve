

#include "Wolf.h"


//Wolf initializing defaults

Wolf::Wolf(int mId, int mRow, int mCol) : Animal(mId, mRow, mCol) {

    this->species = "Wolf";
    this->type = 'L';
    this->id = mId;
    this->row = mRow;
    this->col = mCol;
    this->preferedSmell = "carne";
    this->perception = 5;
    this->reproduceStatus = false;
    this->reproduceRange = 15;

    random_device rd;
    mt19937 mt(rd());

    string::size_type sz;

    string data;
    ifstream fileConst;

    fileConst.open("../constants.txt");

    while (fileConst >> data) {

        if (data == "SLobo") {

            fileConst >> data;
            iniHealth = stoi(data, &sz);

        } else if (data == "VLobo") {

            fileConst >> data;
            vitality = stoi(data, &sz);

            this->randomSpawnInstance = rand() % vitality;

        } else if (data == "WLobo") {

            fileConst >> data;
            weight = stoi(data, &sz);
        }

    }
}

int Wolf::move(int maxX, int maxY, vector<Animal *> &_animals, vector<Food*>&_food) {

    random_device rd;
    mt19937 mt(rd());

    uniform_int_distribution<int> Direction(0, 3);

    random = Direction(mt);
    int animalsToHunt = 0;
    int foodToEat = 0;

    int nSteps ;

    if( this->hunger > 15 )
        nSteps = 2;
    else
        nSteps = 1;

    pair <int,int> LimitMax (col + perception, row + perception);
    pair <int,int> LimitMin (col - perception, row - perception);

    for(int i = 0 ; i < _animals.size(); i++){
        if(_animals[i]->getType() != 'L'){

            animalsToHunt++;

            if(this->hunger > 15) { nSteps = 3;} else { nSteps = 2; }

            if(_animals[i]->getPosX() < LimitMax.first && _animals[i]->getPosX() > LimitMin.first){
                if(_animals[i]->getPosY() < LimitMax.second && _animals[i]->getPosY() > LimitMin.second){

                        if(_animals[i]->getPosX() < this->getPosX())
                            col -= nSteps;
                        else if(_animals[i]->getPosX() > this->getPosX())
                            col += nSteps;

                        if(_animals[i]->getPosY() < this->getPosY())
                            row  -= nSteps;
                        else if(_animals[i]->getPosY() > this->getPosY())
                            row += nSteps;

                        if((_animals[i]->getPosX() == this->getPosX() && _animals[i]->getPosY() == this->getPosY()) ||
                            (_animals[i]->getPosX()+1 == this->getPosX() && _animals[i]->getPosY()+1 == this->getPosY()) ||
                             (_animals[i]->getPosX()-1 == this->getPosX() && _animals[i]->getPosY()-1 == this->getPosY())
                            ){

                            if(_animals[i]->getWeight() > this->weight){

                                uniform_int_distribution<int> Fighting(0, 100);

                                int fight =  Fighting(mt);

                                if(fight > 50)
                                    _animals[i]->setHealth(0);
                                else
                                    this->iniHealth = 0;

                            }else{
                                _animals[i]->setHealth(0);
                            }
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

    for (int i=0; i < _food.size(); i++){
        if(_food[i]->getPosX() <= LimitMax.first && _food[i]->getPosX() >= LimitMin.first){
            if(_food[i]->getPosY() <= LimitMax.second && _food[i]->getPosY() >= LimitMin.second){
                if(_food[i]->getSmell1() == this->preferedSmell || _food[i]->getSmell2() == this->preferedSmell){

                    foodToEat++;

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

    if(animalsToHunt == 0 && foodToEat == 0){
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

}

void Wolf::setHunger() {
    this->hunger += 2;
}

void Wolf::setHealth() {

    if (this->hunger > 25)
        this->iniHealth -= 2;
    else if(this->hunger > 15)
        this->iniHealth -= 1;

}

pair <bool,bool> Wolf::die(){

    pair <bool,bool> _output (false,false);

    if( this->iniHealth <= 0 || this->getVitality() == 0){
        _output.first = true;
        _output.second = true;
    }

    return _output;

}


pair <int,int> Wolf::sonSpawnLocation(pair<int,int> input) {

    pair <int,int> output;
    int row_coords = 0, col_coords = 0;

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

bool Wolf::reproduce() {

    if( this->randomSpawnInstance == 0 && !reproduceStatus){

        reproduceStatus = true;
        return true;

    }else{
        this->randomSpawnInstance -= 1;
    }

    return false;

}