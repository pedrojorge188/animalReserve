//
// Created by pedro on 09/11/2022.
//

#include "Reserve.h"


Reserve::Reserve(int columns, int lines) {

    n_columns = columns;
    n_lines = lines;
    count_animal = 0;
    count_food = 0;

    try{
        reserve_posx_posy = new char*[n_lines];
        for(int i=0;i<n_lines;i++){
            reserve_posx_posy[i] = new char[n_columns];
            for(int k=0;k<n_columns;k++)
                reserve_posx_posy[i][k] = ' ';
        }
    }catch (const exception& memory_allocation_error){
        cout << memory_allocation_error.what() << endl;
        throw memory_allocation_error;
    }

    reserve_posx_posy[2][3] = 'A';
    cout << " !!! Reserva !!!" << endl;

    cout << ' ' ;
    for(int c=0;c<n_columns;c++)
        cout << '_' ;
    for(int i=0;i<n_lines;i++){
        cout << endl << '|';
        for(int k=0;k<n_columns;k++)
            cout << reserve_posx_posy[i][k];
        cout << "|";
    }
    cout  << ' '  << endl;
    for(int l=0;l<n_columns;l++)
        cout << '_' ;





}
