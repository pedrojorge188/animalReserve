
#ifndef ANIMALRESERVE_SIMULATOR_H
#define ANIMALRESERVE_SIMULATOR_H
#include "utils.h"
#include <cctype>
#include "Reserve.h"
#include <vector>

class Simulator {
private:
    int randCol, randRow;
    int max_range_x;
    vector <Reserve *> reserve_lib;
    int min_range_x;
    int min_range_y;
    int col_Maxlimit;
    int row_Maxlimit;
    int max_range_y;
    int window_range_x;
    int window_range_y;
    int log_color;
    int instance[2];
    string _resName;
    string command;
    string notification_str;
    string object_str;

public:
    Simulator(int row,int col);
    void showReserve(Window &window,Reserve &reserve) const;
    void showSimulatorMenu(Window &window,int col,int row,Reserve &r) const;
    bool readCommand(Window &window,Reserve &r);
    bool keyboard_detection(Window &window);
    void SimulationProcess(int row,int col);
};

#endif //ANIMALRESERVE_SIMULATOR_H
