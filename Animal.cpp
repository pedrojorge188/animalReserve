#include "Animal.h"

Animal::Animal(int m_id,int m_row, int m_col)
{
    this->type = 'D';       this->iniHealth = 0;
    this->id = m_id;        this->weight = 0;
    this->row = m_row;      this->vitality = 0;
    this->col = m_col;      this->hunger = 0;
    this->preferedSmell = "ANY";

}

void Animal::setHealth(int new_health_value){this->iniHealth = new_health_value;}
void Animal::setHunger(int new_hunger_value) {this->hunger = new_hunger_value;}
void Animal::setWeight(int new_weight) {this->weight = new_weight;}

ostringstream Animal::printInfo() const {

    ostringstream buf;

    buf << "ID:" << this->getId() <<endl;
    buf << "TYPE:" << this->getType() <<endl;
    buf << "COL:" << this->getPosX() << "| ROW: " << this->getPosY() << endl;
    buf << "WEIGHT:" << this->getWeight() <<endl;
    buf << "HEALTH:" << this->getIniHealth() << endl;
    buf << "VITALITY:" << this->getVitality() << endl;

    return buf;

}

//Rabbit initializing defaults

Rabbit::Rabbit(int mId, int mRow, int mCol) : Animal(mId, mRow, mCol) {

    this->type = 'C';
    this->id = mId;
    this->row = mRow;
    this->col = mCol;
    this->preferedSmell = "verdura";
    this->reproduceTime = 8;
    this->reproduceRange = 10;

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

//Sheep initializing defaults

Sheep::Sheep(int mId, int mRow, int mCol) : Animal(mId, mRow, mCol) {

    this->type = 'O';
    this->id = mId;
    this->row = mRow;
    this->col = mCol;
    this->preferedSmell = "erva";
    this->reproduceTime = 15;
    this->reproduceLimit = 12;

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

//Wolf initializing defaults

Wolf::Wolf(int mId, int mRow, int mCol) : Animal(mId, mRow, mCol) {

    this->type = 'L';
    this->id = mId;
    this->row = mRow;
    this->col = mCol;
    this->preferedSmell = "carne";
    random_device rd;
    mt19937 mt(rd());

    string::size_type sz;
    int maxValue=0, minValue=0;

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


//Kangaroo initializing defaults
Kangaroo::Kangaroo(int mId, int mRow, int mCol) : Animal(mId, mRow, mCol) {

    this->type = 'G';
    this->id = mId;
    this->row = mRow;
    this->col = mCol;
    this->reproduceTime = 30;
    this->reproduceRange = 3;
    this->bornPause = 5;
    this->age = 0;

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

//Kangaroo initializing defaults
Mysterio::Mysterio(int mId, int mRow, int mCol) : Animal(mId, mRow, mCol) {

    this->type = 'M';
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
