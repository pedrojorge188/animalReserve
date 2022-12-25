
#include "Sheep.h"


Sheep::Sheep(int mId, int mRow, int mCol) : Animal(mId, mRow, mCol) {

    this->species = "Sheep";
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
