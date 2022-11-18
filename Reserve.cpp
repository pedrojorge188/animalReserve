
// Created by pedro on 09/11/2022.
//

#include "Reserve.h"


Reserve::Reserve(int columns, int lines) {

    n_columns = columns;
    n_lines = lines;

    try{
        reserve_posx_posy = new char*[n_lines];

        for(int i=0;i<n_lines;i++){
            reserve_posx_posy[i] = new char[n_columns];
            for(int k=0;k<n_columns;k++)
                reserve_posx_posy[i][k] = 'T';
        }

        if(n_lines < 16 || n_lines > 500 || n_columns < 16 || n_columns > 500){
           throw 1;
        }
    }catch (int error){
        if(error == 1) {
            cout << "ERROR: Reserve dimensions out of bounds!" << endl;
            exit(0);
        }
        else
            cout << "ERROR: Problem in constructor 'RESERVE'" << endl;
    }

}

Reserve::Reserve(Reserve &aux) {

    n_columns = aux.n_columns;
    n_lines = aux.n_lines;

    reserve_posx_posy = new char *[n_lines];

    for (int i = 0; i < n_lines; i++) {
        for (int k = 0; k < n_columns; k++)
            reserve_posx_posy[i][k] = aux.reserve_posx_posy[i][k];
    }

}



