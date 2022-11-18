
#ifndef ANIMALRESERVE_SIMULATOR_H
#define ANIMALRESERVE_SIMULATOR_H
#include "utils.h"
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
    Simulator(int col,int row);
    void showReserve(Window &window,Reserve &reserve,int col,int row);
    void showSimulatorMenu(Window &window,int col,int row);
    string readCommand(string &cmd);
};

#endif //ANIMALRESERVE_SIMULATOR_H
