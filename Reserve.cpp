
#include "Reserve.h"


Reserve::Reserve(int columns, int lines) {

    n_columns = columns;
    n_lines = lines;
    current_id = 1;

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

    reserve_posx_posy = new char *[n_lines];

    for (int i = 0; i < n_lines; i++) {
        for (int k = 0; k < n_columns; k++)
            reserve_posx_posy[i][k] = aux.reserve_posx_posy[i][k];
    }

}

pair<string,string> Reserve::spawnAnimal(int col, int row, char animalType) {

    pair <string,string> response ("Any info","Any Change made!");
    auto i = animals.begin();

    try{

        if( animalType == RABBIT ) {

            Rabbit * _new;
            _new = new Rabbit(current_id,row,col);
            animals.push_back(_new);

        }else if( animalType == SHEEP ){

            Sheep * _new;
            _new = new Sheep(current_id,row,col);
            animals.push_back(_new);

        }else if( animalType == WOLF ){

            Wolf * _new;
            _new = new Wolf(current_id,row,col);
            animals.push_back(_new);

        }else if( animalType == KANGAROO ){

            Kangaroo * _new;
            _new = new Kangaroo(current_id,row,col);
            animals.push_back(_new);

        }else if( animalType == MYSTERIO ){

            Mysterio * _new;
            _new = new Mysterio(current_id,row,col);
            animals.push_back(_new);
        }

    }catch(...){response.second = "Unespected error storing animal!"; return response;}

    response.first = _drawAnimalType(current_id,row,col);
    response.second = "ANIMAL ADDED TO YOUR SIMULATION!";

    ++current_id;
    return response;
}

int Reserve::killAnimal(int row, int col) {

    int current_col, current_row;
    auto i = animals.begin();

    for( ; i != animals.end(); i++){

        current_col = (*i)->getPosX();
        current_row = (*i)->getPosY();

        if(((*i)->getPosY() == row) && ((*i)->getPosY() == col)){
            delete *i;
            animals.erase(i);
            reserve_posx_posy[current_row][current_col] = ' ';
            return 1;
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
            delete *i;
            animals.erase(i);
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

string Reserve::animalsInReserve() const {
    ostringstream res;
    string toReturn;

    for(int i = 0;i < animals.size(); i++){
        res = animals[i]->informations();
        toReturn.append(res.str());
    }

    return toReturn;
}

void Reserve::_newTurn() {

    int loc_x;int loc_y;
    auto i = animals.begin();

    for( ; i != animals.end(); i++){
        reserve_posx_posy[(*i)->getPosY()][(*i)->getPosX()] = ' ';
        (*i)->setVitality();
        (*i)->setHunger();
        (*i)->setHealth();
        (*i)->move(n_columns,n_lines);
        reserve_posx_posy[(*i)->getPosY()][(*i)->getPosX()] = (*i)->getType();

    }

}


