
#ifndef ANIMALRESERVE_SIMULATOR_H
#define ANIMALRESERVE_SIMULATOR_H
#include "Reserve.h"

class Simulator {

private:
    int total_animals;
    int total_food;
    int range_x;
    int range_y;
    int turn_instance;
    string command;
    int last_turn;
public:
    Simulator(int col = 16, int row = 16);
    void showReserve(Reserve &reserve,int col,int row);
    void showSimulatorMenu();
    string readCommand(string &cmd);
};

#endif //ANIMALRESERVE_SIMULATOR_H
