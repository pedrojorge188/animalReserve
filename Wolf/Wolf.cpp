

#include "Wolf.h"


//Wolf initializing defaults

Wolf::Wolf(int mId, int mRow, int mCol) : Animal(mId, mRow, mCol) {

    this->species = "Wolf";
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