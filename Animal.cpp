#include "Animal.h"

Animal::Animal(int m_id,int m_row, int m_col)
{
    this->type = 'D';           this->iniHealth = 0;
    this->id = m_id;            this->weight = 0;
    this->row = m_row;          this->vitality = 0;
    this->col = m_col;          this->hunger = 0;
    this->preferedSmell = "ANY"; this->species = "ANY";
    this->perception = 0;

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
    buf << "SPECIES:" << this->getSpecies() << " | ";
    buf << "HEALTH:" << this->getIniHealth() << "}" <<endl;

    return buf;
}

int Animal::move(int maxX, int maxY, vector<Animal*>&_animal ) { col = this->col; row = this->row;}

pair <int,int> Animal::sonSpawnLocation(pair<int,int> input) {

    pair <int,int> location (input.first,input.second);

    return location;

}
