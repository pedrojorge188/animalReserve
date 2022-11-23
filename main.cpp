#include <iostream>
#include "utils.h"
#include "Reserve.h"
#include "Simulator.h"
#include "curses.h"
#include "Terminal.h"


int main() {

    int rows,cols;

    cout << "INSERT RESERVE AREA!" << endl;
    cout << "ROWS:";
    cin >> rows;
    cout << "COLUMNS:";
    cin >> cols;

    Simulator(rows,cols);
    return 0;
}