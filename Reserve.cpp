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
        for(int i=0;i<n_lines;i++)
            reserve_posx_posy[i] = new char[n_columns];
    }catch (const exception& memory_allocation_error){
        cout << memory_allocation_error.what() << endl;
        throw memory_allocation_error;
    }
}
