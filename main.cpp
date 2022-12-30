#include <iostream>

#include "utils.h"
#include "Reserve.h"
#include "Animal.h"
#include "Simulator.h"
#include "curses.h"
#include "Terminal.h"
#include <vector>



int main() {

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