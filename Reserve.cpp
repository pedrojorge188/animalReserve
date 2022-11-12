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

int Reserve::CreateAnimal(char type, int columns , int lines ){
    Animal type;
    reserve_posx_posy[columns][lines]=a;

}
