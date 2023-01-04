#include "Animal.h"

Animal::Animal(int m_id,int m_row, int m_col)
{
    this->type = 'D';           this->iniHealth = 0;
    this->id = m_id;            this->weight = 0;
    this->row = m_row;          this->vitality = 0;
    this->col = m_col;          this->hunger = 0;
    this->preferedSmell = "ANY"; this->species = "ANY";
    this->perception = 0;
    this->oldHistory = nullptr;
    this->newHistory = nullptr;

    this->nEntries = 0;
}

void Animal::setHealth(){iniHealth = this->iniHealth;}
void Animal::setVitality() {this->vitality -= 1;}
void Animal::setHunger() {this->hunger += 1;}
void Animal::setWeight(int new_weight) {this->weight = new_weight;}

ostringstream Animal::printInfo() const {

    ostringstream buf;

    buf << "ID:" << this->getId() <<endl;
    buf << "SPECIES:" << this->getSpecies() <<endl;
    buf << "COL:" << this->getPosX()+1 << "| ROW: " << this->getPosY()+1 << endl;
    buf << "WEIGHT:" << this->getWeight() <<endl;
    buf << "HEALTH:" << this->getIniHealth() << endl;
    buf << "VITALITY:" << this->getVitality() << endl;

    return buf;

}

ostringstream  Animal::informations() const {

    ostringstream buf;

    buf << "{ID:" << this->getId() << " | " ;
    buf << "COL:" << this->getPosX()+1 << "| ROW: " << this->getPosY()+1 << endl;
    buf << "SPECIES:" << this->getSpecies() << " | ";
    //buf << "HUNGER:" << this->getHunger() << " | ";
    buf << "HEALTH:" << this->getIniHealth() << "}" <<endl;

    return buf;
}

int Animal::move(int maxX, int maxY, vector<Animal*>&_animal  ,vector<Food*> &_food) { col = this->col; row = this->row; return 0;}

pair <int,int> Animal::sonSpawnLocation(pair<int,int> input) {

    pair <int,int> location (input.first,input.second);

    return location;

}

pair <bool,bool> Animal::die() {

    pair <bool,bool> output (false,false);

    return output;

;}
void Animal::removeHistory() {
    oldHistory = nullptr;
    newHistory = nullptr;
}

void Animal::setHistory(string food, int tox, int nutr) {
    ostringstream buf;
    if(nEntries == 0){
        oldHistory = new string;//[nEntries];
    }else if(nEntries > 0){
        newHistory = new string[nEntries];
        for (int i = 0; i < nEntries; ++i) {
            newHistory[i] = oldHistory[i];
        }
        if(nEntries==1){
            delete oldHistory;
        }else{
            delete [] oldHistory;
        }

        oldHistory = new string[nEntries+1];
        for (int i = 0; i < nEntries; ++i) {
            oldHistory[i] = newHistory[i];
        }
        delete [] newHistory;
    }

    buf << "-> " << food << ", tox: " << tox << " , nutr: " << nutr << endl;

    oldHistory[nEntries] = buf.str();
    nEntries++;

}

string Animal::printHistory() const {

    ostringstream buf;
    string response;

    for(int i = 0; i < nEntries; i++){
        buf << oldHistory[i] << endl;
    }

    response = buf.str();

    return response;

}