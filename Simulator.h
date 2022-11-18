
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
    string notification_str;
public:
    Simulator(int col,int row);
    void showReserve(Window &window,Reserve &reserve);
    void showSimulatorMenu(Window &window,int col,int row);
    bool readCommand(string &cmd,Window &window);
};

#endif //ANIMALRESERVE_SIMULATOR_H
