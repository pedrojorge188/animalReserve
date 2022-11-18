//
// Created by pedro on 09/11/2022.
//

#include "Simulator.h"

Simulator::Simulator(int col,int row) {

    total_animals = 0;
    range_x = col+2;
    range_y = row+2;
    total_food = 0;
    turn_instance = 0;
    last_turn = 0;

    Reserve reserve = Reserve(range_x, range_y);

    Terminal &t = Terminal::instance();

    for(int i=1; i<20; i++) {
        t.init_color(i, i, 0);
    }

    {
        Window title = Window(15,2,20,1,false);
        Window wReserve = Window(0,4,range_x,range_y,true);
        Window wMenu = Window(range_x+2,6,20,8,false);

        title << "ANIMAL RESERVE" ;
        char **poSx_poSy = reserve.getReserve();
        poSx_poSy[0][0] = 'A';
        showReserve(wReserve,reserve,col,row);
        showSimulatorMenu(wMenu,col,row);
        readCommand(command);

        t.getchar();
    }
}

void Simulator::showReserve(Window &window,Reserve &reserve,int col,int row) {

    char **poSx_poSy = reserve.getReserve();

    for(int i=0;i<col;i++){
        for(int k=0;k<row;k++)
            window << poSx_poSy[k][i];
    }
}

void Simulator::showSimulatorMenu(Window &window,int col,int row) {
    window << set_color(6);
    window << "SIMULATION MENU \n\n" << set_color(10);
    window << "TURN - " << turn_instance << '\n';
    window << "VIEW LIMIT (" << range_x-2<< ',' << range_y-2 << ')' << '\n';
    window << "RESERVE_SIZE (" << col << ',' << row << ')';
    window << "TOTAL FOOD - " << total_food << '\n';
    window << "TOTAL ANIMALS - " << total_animals << '\n';
}

string Simulator::readCommand(string &cmd) {
    cout << "\n COMMAND: ";
    cin >> command ;
}