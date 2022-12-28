
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

int Rabbit::move(int maxX, int maxY, vector<Animal*>&_heavyAnimal,  vector<Food*> &_food) {

    int _start_col = this->col;
    int _start_row = this->row;
    random_device rd;
    mt19937 mt(rd());

    uniform_int_distribution<int> randomN(0, 3);

    random = randomN(mt);

    int animalToRun = 0;
    int foodToEat = 0;

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


    pair <int,int> LimitMax (
            this->col + this->perception,
            this->row + this->perception
    );

    pair <int,int> LimitMin (
            this->col - this->perception,
            this->row - this->perception
    );





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


    for (int i = 0 ; i < _heavyAnimal.size() ; i++){
        if(_heavyAnimal[i]->getPosX() <= LimitMax.first && _heavyAnimal[i]->getPosX() >= LimitMin.first){
            if(_heavyAnimal[i]->getPosY() <= LimitMax.second && _heavyAnimal[i]->getPosY() >= LimitMin.second){
                if(_heavyAnimal[i]->getWeight() > 10){
                    animalToRun++;

                    if(_heavyAnimal[i]->getPosX() < this->getPosX())
                        col = _start_col + 1;
                    else if(_heavyAnimal[i]->getPosX() > this->getPosX())
                        col = _start_col - 1;
                    else if(_heavyAnimal[i]->getPosY() < this->getPosY())
                        row = _start_row + 1;
                    else if(_heavyAnimal[i]->getPosY() > this->getPosY())
                        row = _start_row - 1;

                }
            }
        }
    }

    if(animalToRun==0 && foodToEat==0){
        if(random == 0){ col+=nSteps; }
        else if(random == 1){ col-=nSteps; }
        else if(random == 2){ row+=nSteps; }
        else if(random == 3){ row-=nSteps; }
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

void Rabbit::setHunger() {this->hunger += 1;}

void Rabbit::setHealth() {

    if(this->hunger > 10)
        this->iniHealth -= 1;
    else if(this->hunger > 20)
        this->iniHealth -= 2;

}

pair <bool,bool> Rabbit::die() {

    pair <bool,bool> output (false,false);

    if(this->vitality == 0 ) {
        output.first = true;
    }
    else if(this->iniHealth == 0 ) {
        output.first = true;;
    }

    return output;


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



