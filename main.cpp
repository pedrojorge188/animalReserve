#include <iostream>

#include "utils.h"
#include "Reserve.h"
#include "Animal.h"
#include "Simulator.h"
#include "curses.h"
#include "Terminal.h"
#include <vector>



int main() {
    /*
    vector <Reserve *> saves;

    Reserve *reserve;
    reserve = new Reserve(16,16);
    saves.push_back(reserve);

    reserve->spawnAnimal(14,14,'c');
    reserve->spawnAnimal(1,1,'c');
    reserve->spawnAnimal(1,5,'c');

    Reserve *copy;
    copy = new Reserve(*reserve,"teste");
    saves.push_back(copy);

    copy->spawnAnimal(14,14,'l');
    copy->spawnAnimal(1,1,'l');
    copy->spawnAnimal(1,5,'l');

    for( int m = 0; m< saves.size();m++){
            cout << saves[m]->getReserveName() << endl;
            char **showit = saves[m]->getReserve();
            for(int i=0 ;i<15;i++){
                cout << endl;
                for(int k=0;k<15;k++) {
                    cout << "|";
                    cout << showit[i][k];
                }
            }
            cout << "\n" << endl;

    }


    */
    int rows,cols;

    cout << "INSERT RESERVE AREA!" << endl;
    cout << "ROWS:";
    cin >> rows;
    cout << "COLUMNS:";
    cin >> cols;

    Simulator sim = Simulator(rows,cols);

    sim.SimulationProcess(rows,cols);

    return 0;

}