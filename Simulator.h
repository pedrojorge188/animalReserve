
#ifndef ANIMALRESERVE_SIMULATOR_H
#define ANIMALRESERVE_SIMULATOR_H
#include "utils.h"
#include <cctype>
#include "Reserve.h"


class Simulator {

private:
    int total_animals;
    int total_food;
    int range_x;
    int col_MinLimit;
    int row_MinLimit;
    int col_Maxlimit;
    int row_Maxlimit;
    int range_y;
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
};

#endif //ANIMALRESERVE_SIMULATOR_H
