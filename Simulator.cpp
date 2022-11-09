//
// Created by pedro on 09/11/2022.
//

#include "Simulator.h"

Simulator::Simulator(int col,int row) {

    //Por enquanto colocamos a 0 mas mais tarde colocamos a funcao para ir buscar o numero de animais
    total_animals = 0;
    total_food = 0;
    range_x = 0;
    range_y = 0;
    turn_instance = 0;
    last_turn = 0;

    Reserve starterReserve = Reserve(col,row);
    Simulator::showReserve(starterReserve,col,row);


    do{

       Simulator::showSimulatorMenu();
       readCommand(command);

       turn_instance++;
    }while(command.compare("exit"));

}

void Simulator::showReserve(Reserve &reserve,int col,int row) {

   char **poSx_poSy = reserve.getReserve();
    cout << "\t RESERVE OF ANIMALS" << endl;

    cout << ' ' ;
    for(int c=0;c<col;c++)
        cout << '_' ;
    for(int i=0;i<row;i++){
        cout << endl << '|';
        for(int k=0;k<col;k++)
            cout << poSx_poSy[i][k];
        cout << "|";
    }
    cout  << ' '  << endl;
    for(int l=0;l<col;l++)
        cout << '_' ;

}

void Simulator::showSimulatorMenu() {
    cout << "\n SIMULATION MENU " << endl;
    cout << "TURN - " << turn_instance << endl;
    cout << "VIEW LIMIT (" << range_x << ',' << range_y << ')' << endl;
    cout << "TOTAL FOOD - " << total_food << endl;
    cout << "TOTAL ANIMALS - " << total_animals << endl;
}

string Simulator::readCommand(string &cmd) {
    cout << "\n COMMAND: ";
    cin >> command ;
}