
#include "Reserve.h"


Reserve::Reserve(int columns, int lines) {

    n_columns = columns;
    n_lines = lines;
    current_id_animal = 1;
    current_id_food = 1;

    try{
        reserve_posx_posy = new char*[n_lines];

        for(int i=0;i<n_lines;i++){
            reserve_posx_posy[i] = new char[n_columns];
            for(int k=0;k<n_columns;k++)
                reserve_posx_posy[i][k] = ' ';
        }


        if(n_lines < 16 || n_lines > 500 || n_columns < 16 || n_columns > 500){
            throw 1;
        }
    }catch (int error){
        if(error == 1) {
            cout << "ERROR: Reserve dimensions out of bounds!" << endl;
            exit(0);
        }
        else
            cout << "ERROR: Problem in constructor 'RESERVE'" << endl;
    }

}

Reserve::Reserve(Reserve &aux) {

    n_columns = aux.n_columns;
    n_lines = aux.n_lines;
    copy(aux.animals.begin(), aux.animals.end(), back_inserter(animals));

    reserve_posx_posy = new char *[n_lines];

    for (int i = 0; i < n_lines; i++) {
        for (int k = 0; k < n_columns; k++)
            reserve_posx_posy[i][k] = aux.reserve_posx_posy[i][k];
    }


}

pair<string,string> Reserve::spawnAnimal(int col, int row, char animalType) {

    pair <string,string> response ("Any info","Any Change made!");

    if((col < n_columns &&  row < n_lines) || (col < 1 || row < 1)){
        try{

            if( animalType == RABBIT ) {

                Rabbit * _new;
                _new = new Rabbit(current_id_animal,row,col);
                animals.push_back(_new);

            }else if( animalType == SHEEP ){

                Sheep * _new;
                _new = new Sheep(current_id_animal,row,col, (*i)->getIniHealth());
                animals.push_back(_new);
                
            }else if( animalType == WOLF ){

                Wolf * _new;
                _new = new Wolf(current_id_animal,row,col);
                animals.push_back(_new);

            }else if( animalType == KANGAROO ){

                Kangaroo * _new;
                _new = new Kangaroo(current_id_animal,row,col);
                animals.push_back(_new);

            }else if( animalType == MYSTERIO ){

                Mysterio * _new;
                _new = new Mysterio(current_id_animal,row,col);
                animals.push_back(_new);
            }

        }catch(...){response.second = "Unexpected error storing animal!"; return response;}

        response.first = _drawAnimalType(current_id_animal,row,col);
        response.second = "ANIMAL ADDED TO YOUR SIMULATION!";

        ++current_id_animal;

    }else{
        response.second = "ANIMAL CANT BE ADDED CHECK YOUR INPUT";
    }

    return response;
}

pair<string,string> Reserve::spawnFood(int col, int row, char foodType) {

    pair <string,string> response ("Any info","Any Change made!");

    if((col < n_columns &&  row < n_lines) || (col < 1 || row < 1)){
        try{

            if( foodType == GRASS ) {

                Grass * _new;
                _new = new Grass(current_id_food,row,col);
                foods.push_back(_new);

            }else if( foodType == CARROT ){

                Carrot * _new;
                _new = new Carrot(current_id_food,row,col);
                foods.push_back(_new);

            }else if( foodType == MEAT ){

                Meat * _new;
                _new = new Meat(current_id_food,row,col);
                foods.push_back(_new);

            }else if( foodType == MISTERY_FOOD ){

                misteryFood * _new;
                _new = new misteryFood(current_id_food,row,col);
                foods.push_back(_new);
            }

        }catch(...){response.second = "Unespected error storing food!"; return response;}

        response.first = _drawFoodType(current_id_food,row,col);
        response.second = "FOOD ADDED TO YOUR SIMULATION!";

        ++current_id_food;

    }else{
        response.second = "FOOD CANT BE ADDED CHECK YOUR INPUT";
    }

    return response;
}

int Reserve::killAnimal(int row, int col) {

    int current_col, current_row;
    auto i = animals.begin();

    for( ; i != animals.end() ; i++){

        current_col = (*i)->getPosX();
        current_row = (*i)->getPosY();

        if(current_row == row){
            if(current_col == col){

                reserve_posx_posy[current_row][current_col] = ' ';

                if((*i)->getType() == toupper(WOLF)){
                    Body * _new;
                    int new_pos = (*i)->getPosX()+1;

                    if((*i)->getPosY()+1 >= this->n_lines || (*i)->getPosX()+1 >= this->n_columns){
                        new_pos = (*i)->getPosX()-1;
                    }

                    _new = new Body(current_id_food,(*i)->getPosY(),new_pos, 0, 10);
                    foods.push_back(_new);
                    _drawFoodType(current_id_food,(*i)->getPosY()+1,new_pos);
                    ++current_id_food;
                }

                delete *i;
                animals.erase(i);
                return 1;
            }
        }
    }


    return 0;
}


int Reserve::killAnimal(int id) {

    int current_col, current_row;
    auto i = animals.begin();

    for( ; i != animals.end(); i++){

        current_col = (*i)->getPosX();
        current_row = (*i)->getPosY();

        if((*i)->getId() == id){

            if((*i)->getType() == toupper(WOLF)){
                Body * _new;
                int new_pos = (*i)->getPosX()+1;

                if((*i)->getPosY()+1 >= this->n_lines || (*i)->getPosX()+1 >= this->n_columns){
                    new_pos = (*i)->getPosX()-1;
                }

                _new = new Body(current_id_food,(*i)->getPosY(),new_pos, 0, 10);
                foods.push_back(_new);

                _drawFoodType(current_id_food,(*i)->getPosY()+1,new_pos);
                ++current_id_food;
            }

            delete *i;
            animals.erase(i);
            reserve_posx_posy[current_row][current_col] = ' ';
            return 1;
        }
    }

    return 0;
}

int Reserve::killFood(int row, int col) {

    int current_col, current_row;
    auto i = foods.begin();

    for( ; i != foods.end(); i++){

        current_col = (*i)->getPosX();
        current_row = (*i)->getPosY();

        if(current_row == row){
            if(current_col == col){

                reserve_posx_posy[current_row][current_col] = ' ';

                delete *i;
                foods.erase(i);
                return 1;
            }
        }
    }


    return 0;
}

bool Reserve::cleanPositions(int row, int col) {

    if(killAnimal(row,col) == 0)
        if(killFood(row,col) == 0)
            return false;

    return true;

}

string Reserve::watchPositionsInfo(int row, int col) {

    ostringstream res;
    string toReturn = " ";

    for(int i = 0;i < animals.size(); i++){
        if(animals[i]->getPosY() == row && animals[i]->getPosX() == col){
            res = animals[i]->informations();
            toReturn.append(res.str());
        }
    }

    for(int i = 0;i < foods.size(); i++){
        if(foods[i]->getPosY() == row && foods[i]->getPosX() == col){
            res = foods[i]->informations();
            toReturn.append(res.str());
        }
    }

    return toReturn;

}

int Reserve::killFood(int id) {

    int current_col, current_row;
    auto i = foods.begin();

    for( ; i != foods.end(); i++){

        current_col = (*i)->getPosX();
        current_row = (*i)->getPosY();

        if((*i)->getId() == id){
            delete *i;
            foods.erase(i);
            reserve_posx_posy[current_row][current_col] = ' ';
            return 1;
        }
    }

    return 0;
}

int Reserve::_getTotalAnimals() const {

    int _animals = 0;

    auto i = animals.begin();
    for(;i != animals.end();i++)
        ++_animals;

    return _animals;

}

int Reserve::_getTotalFood() const {

    int _food = 0;

    auto i = foods.begin();
    for(;i != foods.end();i++)
        ++_food;

    return _food;

}

string Reserve::_drawAnimalType(int id,int row,int col) const {
    ostringstream res;
    auto i = animals.begin();

    for(;i != animals.end(); i++){

        if((*i)->getId() == id){
            res = (*i)->printInfo();
            reserve_posx_posy[row][col] = (*i)->getType();
        }
    }


    return res.str();
}

string Reserve::_drawFoodType(int id,int row,int col) const {
    ostringstream res;
    auto i = foods.begin();

    for(;i != foods.end(); i++){

        if((*i)->getId() == id){
            res = (*i)->printInfo();
            reserve_posx_posy[row][col] = (*i)->getType();
        }
    }


    return res.str();
}

string Reserve::animalsInReserve() const {
    ostringstream res;
    string toReturn;

    for(int i = 0;i < animals.size(); i++){
        res = animals[i]->informations();
        toReturn.append(res.str());
    }

    return toReturn;
}

string Reserve::animalsInReserve(pair<int,int>range_y,pair<int,int> range_x) const {
    ostringstream res;
    string toReturn;

    for(int i = 0;i < animals.size(); i++){

        if((animals[i]->getPosY() < range_y.second  && animals[i]->getPosY() > range_y.first) &&
           (animals[i]->getPosY() < range_x.second  && animals[i]->getPosY() > range_x.first))
        {
            res = animals[i]->informations();
            toReturn.append(res.str());
        }
    }

    return toReturn;
}

string Reserve::foodInReserve() const {
    ostringstream res;
    string toReturn;

    for(int i = 0;i < foods.size(); i++){
        res = foods[i]->informations();
        toReturn.append(res.str());
    }

    return toReturn;
}

void Reserve::_newTurn() {

    auto i = animals.begin();
    auto j = foods.begin();

    pair <int,int> _result;
    pair <int,int> _input (n_lines,n_columns);
    pair <bool,bool> _dead_values;

    for( ; j != foods.end(); j++ ){
        reserve_posx_posy[(*j)->getPosY()][(*j)->getPosX()] = ' ';

        if((*j)->die()){

            delete *j;
            foods.erase(j);

            return;

        }else if((*j)->reproduce()) {

            (*j)->setDuration();
            (*j)->setNutriValue();
            (*j)->setToxicity();

            reserve_posx_posy[(*j)->getPosY()][(*j)->getPosX()] = (*j)->getType();

            _result = (*j)->sonSpawnLocation(_input);

            spawnFood(_result.second,_result.first,(*j)->getType());

            return;

        }else{

            (*j)->setDuration();
            (*j)->setNutriValue();
            (*j)->setToxicity();
            reserve_posx_posy[(*j)->getPosY()][(*j)->getPosX()] = (*j)->getType();
        }

    }

    for( ; i != animals.end(); i++ ){

        _dead_values = (*i)->die();
        reserve_posx_posy[(*i)->getPosY()][(*i)->getPosX()] = ' ';

        if(_dead_values.first){
            /*
            if(_dead_values.second){

                if((*i)->getType() == toupper(WOLF)){
                    Body * _new;
                    int new_pos = (*i)->getPosX()+1;

                    if((*i)->getPosY()+1 >= this->n_lines || (*i)->getPosX()+1 >= this->n_columns){
                        new_pos = (*i)->getPosX()-1;
                    }

                    _new = new Body(current_id_food,(*i)->getPosY(),new_pos, 0, 10);
                    
                    foods.push_back(_new);
                }

                ++current_id_food;
            }
            */
            delete *i;
            animals.erase(i);

            return;

        }else if((*i)->reproduce()) {

            _result = (*i)->sonSpawnLocation(_input);

            this->spawnAnimal(_result.second,_result.first, tolower((*i)->getType()));

            return;

        }else{

            (*i)->setVitality();
            (*i)->setHunger();
            (*i)->setHealth();
            (*i)->move(n_columns,n_lines,animals,foods);
            reserve_posx_posy[(*i)->getPosY()][(*i)->getPosX()] = (*i)->getType();

        }
    }

}



string Reserve::_feedAnimals(int row, int col, int nut_points, int tox_points) {

    auto i = animals.begin();
    int value;
    string response =  "Animal not found!";

    for( ; i != animals.end() ; i++){

        if((*i)->getPosY() == row){
            if((*i)->getPosX() == col){

                value = (*i)->getIniHealth() + nut_points - tox_points;
                (*i)->setHealth(value);
                response = "Animal feeded by users!";
            }
        }
    }

    return response;

}

string Reserve::_feedAnimals(int id, int nut_points, int tox_points) {

    auto i = animals.begin();
    int value;
    string response =  "Animal id invalid!";

    for( ; i != animals.end() ; i++){
        if((*i)->getId() == id){
            value = (*i)->getIniHealth() + nut_points - tox_points;
            (*i)->setHealth(value);
            response = "Animal feeded by users!";
        }
    }

    return response;

}