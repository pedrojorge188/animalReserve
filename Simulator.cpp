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

    if(col > 40 || row > 20){
        range_x = 22;
        range_y = 22;
    }

    Reserve reserve = Reserve(col, row);

    Terminal &t = Terminal::instance();

    for(int i=1; i<20; i++) {
        t.init_color(i, i, 0);
    }

    {
        do{
            Window title = Window(15,2,20,1,false);
            Window wReserve = Window(0,4,range_x,range_y,true);
            Window wMenu = Window(range_x+2,6,30,8,false);

            title << "ANIMAL RESERVE" << set_color(10);

            showReserve(wReserve,reserve);
            showSimulatorMenu(wMenu,col,row);
            readCommand(command,wMenu);

            turn_instance++;
        }while(command.compare("exit") != 0);

    }
}

void Simulator::showReserve(Window &window,Reserve &reserve) {

    char **poSx_poSy = reserve.getReserve();
    int col,row;

    col = range_x - 2;
    row = range_y - 2;

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
    window << "RESERVE_SIZE (" << col << ',' << row << ")\n";
    window << "TOTAL FOOD - " << total_food << '\n';
    window << "TOTAL ANIMALS - " << total_animals << '\n';
}

string Simulator::readCommand(string &cmd,Window &window) {

    window << "COMMAND: ";
    window >> cmd ;

}