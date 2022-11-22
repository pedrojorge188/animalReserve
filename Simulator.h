
#ifndef ANIMALRESERVE_SIMULATOR_H
#define ANIMALRESERVE_SIMULATOR_H
#include "utils.h"
#include <cctype>
#include "Reserve.h"
#include "Animal.h"

class Simulator {

private:
    int randCol, randRow;
    Animal *animal;
    int total_animals;
    int total_food;
    int max_range_x;
    int min_range_x;
    int min_range_y;
    int col_Maxlimit;
    int row_Maxlimit;
    int max_range_y;
    int window_range_x;
    int window_range_y;
    int turn_instance;
    int log_color;
    string command;
    string notification_str;

public:
    Simulator(int row,int col);
    void showReserve(Window &window,Reserve &reserve) const;
    void showSimulatorMenu(Window &window,int col,int row) const;
    bool readCommand(Window &window,Reserve &r);
    bool keyboard_detection(Window &window);
    bool AnimalSpawner(Reserve &r, char type, int col, int row);
};

#endif //ANIMALRESERVE_SIMULATOR_H
