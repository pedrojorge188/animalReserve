#include "Food.h"

Food::Food(int i,int r,int c){
    this->name = "comida";
    this->type = '?';
    this->id = i;   this->row = r;
    this->col = c;  this->toxicity = 0;
    this->nutriValue = 0;
    this->duration = 0;
    this->smell_1 = "nothing";
    this->smell_2 = "nothing";
}

pair <int,int> Food::sonSpawnLocation(pair<int,int> input) {


    pair <int,int> location (input.first,input.second);

    return location;

}

ostringstream Food::printInfo() const {

    ostringstream buf;

    buf << "ID:" << this->getId() <<endl;
    buf << "TYPE:" << this->getType() <<endl;
    buf << "COL:" << this->getPosX()+1 << "| ROW: " << this->getPosY()+1 << endl;
    buf << "DURATION:" << this->getDuration() <<endl;
    buf << "NUTRIVALUE:" << this->getNutriValue() << endl;
    buf << "TOXICITY:" << this->getToxicity() << endl;
    buf << "SMELL_1:" << this->getSmell1() << "| SMELL_2: " << this->getSmell2() << endl;

    return buf;

}

ostringstream  Food::informations() const {

    ostringstream buf;
    buf << "{ID:" << this->getId() << " | " ;
    buf << "SPECIES:" << this->getType() << " | ";
    buf << "X: " << this->getPosX() << " Y: " << this->getPosY() << " | " << endl;
    buf << "DUR:" << this->getDuration() << " | ";
    buf << "TOX:" << this->getToxicity() << " | ";
    buf << "NUTR:" << this->getNutriValue() << "}" <<endl;

    return buf;
}