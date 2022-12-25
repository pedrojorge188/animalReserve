
#include "Mysterio.h"


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