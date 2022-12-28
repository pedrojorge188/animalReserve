
#include "Sheep.h"


Sheep::Sheep(int mId, int mRow, int mCol) : Animal(mId, mRow, mCol) {

    this->species = "Sheep";
    this->type = 'O';
    this->id = mId;
    this->row = mRow;
    this->col = mCol;
    this->hunger=0;
    this->preferedSmell = "erva";
    this->reproduceTime = 15;
    this->perception = 3;

    this->reproduceRange = 12;
    this->inst = 0;

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
        uniform_int_distribution<int> _row((this->row - this->reproduceRange), (this->row + this->reproduceRange));
        uniform_int_distribution<int> _col((this->row - this->reproduceRange), (this->col + this->reproduceRange));

        row_coords =  _row(mt);
        col_coords =  _col(mt);

    }while(row_coords >= input.second || col_coords >= input.first || row_coords <= 0 || col_coords <= 0);

    output.first = row_coords;
    output.second = col_coords;

    return output;
}

bool Sheep::reproduce() {
    inst++;
    if( inst%reproduceTime==0) {
        return true;
    }
    return false;
}

int Sheep::move(int maxX, int maxY, vector<Animal *> &_animals, vector<Food*>&_food) {

    random_device rd;
    mt19937 mt(rd());

    
    uniform_int_distribution<int> Direction(0, 3);
    uniform_int_distribution<int> hungerSteps(1, 2);

    random = Direction(mt);
    int animalsToRun = 0;
    int foodToEat = 0;

    int nSteps ;

    if( this->hunger > 15 ){
        nSteps = hungerSteps(mt);
    }else{
        nSteps = 1;
    }

    pair <int,int> LimitMax (col + perception, row + perception);
    pair <int,int> LimitMin (col - perception, row - perception);

    for (int i=0; i < _food.size(); i++){
        if(_food[i]->getPosX() <= LimitMax.first && _food[i]->getPosX() >= LimitMin.first){
            if(_food[i]->getPosY() <= LimitMax.second && _food[i]->getPosY() >= LimitMin.second){
                if(_food[i]->getSmell1() == this->preferedSmell || _food[i]->getSmell2() == this->preferedSmell){
                    foodToEat++;

                    if(_food[i]->getPosX() < this->getPosX()){
                        col -= 1;
                    }else if(_food[i]->getPosX() > this->getPosX()){
                        col += 1;
                    }

                    if(_food[i]->getPosY() < this->getPosY()){
                        row  -= 1;
                    }else if(_food[i]->getPosY() > this->getPosY()){
                        row += 1;
                    }

                    if(_food[i]->getPosX() == this->getPosX() && _food[i]->getPosY() == this->getPosY()){
                        this->iniHealth += _food[i]->getNutriValue();
                        this->iniHealth -= _food[i]->getToxicity();
                        _food[i]->setDuration(0);
                    }

                }
            }
        }
    }

    for(int i = 0 ; i < _animals.size(); i++){
        if(_animals[i]->getType() != 'O'){
            if(_animals[i]->getPosX() < LimitMax.first && _animals[i]->getPosX() > LimitMin.first){
                if(_animals[i]->getPosY() < LimitMax.second && _animals[i]->getPosY() > LimitMin.second){
                    if(_animals[i]->getWeight() >= 15){

                        animalsToRun++;

                        if(_animals[i]->getPosX() < this->getPosX())
                            col += 1;
                        else if(_animals[i]->getPosX() > this->getPosX())
                            col -= 1;

                        if(_animals[i]->getPosY() < this->getPosY())
                            row  += 1;
                        else if(_animals[i]->getPosY() > this->getPosY())
                            row -= 1;
                    }
                }
            }
        }
    }

    if(animalsToRun == 0 && foodToEat == 0){
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
