
#include "Kangaroo.h"


//Kangaroo initializing defaults

Kangaroo::Kangaroo(int mId, int mRow, int mCol) : Animal(mId, mRow, mCol) {

    this->species = "Kangaroo";
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

