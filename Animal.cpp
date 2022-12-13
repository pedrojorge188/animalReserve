#include "Animal.h"


Animal::Animal(char t, int i ,int r, int c, int in, int p, int w, int we, int v, int h, string ps, int iw, int tb, int db):id(i) {

    string::size_type sz;   // alias of size_t
    int maxValue=0, minValue=0;

    string data;
    ifstream fileConst;

    fileConst.open("../constants.txt");

    type = toupper(t);
    row = r;
    col = c;
    iniHealth = in;
    perception = p;
    walkDistance = w;
    weight = we;
    vitality = v;
    hunger = h;
    preferedSmell = ps;
    interactWeight = iw;
    timeBorn = tb;
    deadBodyValue = db;


    while (fileConst >> data) {
        if (type == 'C') {
            if (data == "SCoelho") {
                fileConst >> data;
                iniHealth = stoi(data, &sz);
            } else if (data == "VCoelho") {
                fileConst >> data;
                vitality = stoi(data, &sz);
            } else if (data == "WDCoelho") {
                fileConst >> data;
                maxValue = stoi(data, &sz);
                fileConst >> data;
                minValue = stoi(data, &sz);

                srand (time(NULL));
                walkDistance = rand()%maxValue + minValue;
            } else if (data == "WCoelho") {
                fileConst >> data;
                maxValue = stoi(data, &sz);
                fileConst >> data;
                minValue = stoi(data, &sz);

                srand (time(NULL));
                weight = rand()%maxValue + minValue;
            }
        } else if (type == 'O') {
            if (data == "SOvelha") {
                fileConst >> data;
                iniHealth = stoi(data, &sz);
            } else if (data == "VOvelha") {
                fileConst >> data;
                vitality = stoi(data, &sz);
            } else if (data == "WDOvelha") {
                fileConst >> data;
                walkDistance = stoi(data, &sz);
            } else if (data == "WOvelha") {
                fileConst >> data;
                maxValue = stoi(data, &sz);
                fileConst >> data;
                minValue = stoi(data, &sz);

                srand (time(NULL));
                weight = rand()%maxValue + minValue;
            }
        } else if (type == 'L') {
            if (data == "SLobo") {
                fileConst >> data;
                iniHealth = stoi(data, &sz);
            } else if (data == "VLobo") {
                fileConst >> data;
                vitality = stoi(data, &sz);
            } else if (data == "WDLobo") {
                fileConst >> data;
                walkDistance = stoi(data, &sz);
            } else if (data == "WLobo") {
                fileConst >> data;
                weight = stoi(data, &sz);
            }
        } else if (type == 'G') {
            if (data == "SCanguru") {
                fileConst >> data;
                iniHealth = stoi(data, &sz);
            } else if (data == "VCanguru") {
                fileConst >> data;
                vitality = stoi(data, &sz);
            } else if (data == "WDCanguru") {
                fileConst >> data;
                walkDistance = stoi(data, &sz);
            } else if (data == "WCanguru") {
                fileConst >> data;
                weight = stoi(data, &sz);
            }
        } else if (type == 'M') {
            if (data == "SMisterio") {
                fileConst >> data;
                iniHealth = stoi(data, &sz);
            } else if (data == "VMisterio") {
                fileConst >> data;
                vitality = stoi(data, &sz);
            } else if (data == "WDMisterio") {
                fileConst >> data;
                walkDistance = stoi(data, &sz);
            } else if (data == "WMisterio") {
                fileConst >> data;
                weight = stoi(data, &sz);
            }
        }
    }
}

void Animal::moveAnimal(int maxX, int maxY) {
    random_device rd;
    mt19937 mt(rd());

    uniform_int_distribution<int> randomN(0, 3);
    uniform_int_distribution<int> randomS(1, 2);

    random = randomN(mt);
    int nSteps = 1;

    if (type == 'C') {
        nSteps = randomS(mt);
    }

    //Right
    if(random == 0){
        col+=nSteps;
    }//Left
    else if(random == 1){
        col-=nSteps;
    }//Up
    else if(random == 2){
        row+=nSteps;
    }//Down
    else if(random == 3){
        row-=nSteps;
    }//error
    else{
        cout << "erro, lol";
    }

    if(col >= maxX+1){
        col = 1;
    }else if(row >= maxY+1){
        row = 1;
    }else if(row <= 0){
        row = maxY;
    }else if(col <= 0){
        col = maxX;
    }
}
