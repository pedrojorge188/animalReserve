#include "Animal.h"
#include "utils.h"

/*char Animal::getAnimal(string type) {
    string Animaltypes[] = {"Coelho", "Ovelha", "Lobo", "Canguru", "Iguana"};
    int idx=-1;
    char var;

    for (int i = 0; i < NUMBER_ANIMALS; ++i) {
        if(type == Animaltypes[i])
            idx=i;
    }
    try{
        switch (idx) {
            case -1:
                throw 1;
                break;
            case 0:
                var = 'C';
                break;
            case 1:
                var = 'O';
                break;
            case 2:
                var = 'L';
                break;
            case 3:
                var = 'G';
                break;
            case 4:
                var = 'I';
                break;

        }
    } catch (int error) {
        if(error == 1) {
            cout << "ERROR: " << type << " is not a animal in our list!" << endl;
            exit(0);
        }
        else
            cout << "ERROR: Problem in constructor 'GETANIMAL'" << endl;
    }
    return var;
};*/

