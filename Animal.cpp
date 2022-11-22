#include "Animal.h"

int Animal::FileValues() {
    ofstream file;
    file.open ("constantes.txt", ios::out);

    if (file.is_open()) {



    }else{
        return -1;
    }
}

