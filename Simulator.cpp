//
// Created by pedro on 09/11/2022.
//

#include "Simulator.h"
#include <cstdlib>

Simulator::Simulator(int col,int row) {

    total_animals = 0;
    range_x = col+2;
    range_y = row+2;
    total_food = 0;
    turn_instance = 0;
    notification_str = " ";
    log_color = COLOR_GREEN;

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
            Window wMenu = Window(range_x+2,6,60,8,false);
            Window notification = Window(2,range_y+5,45,3,false);

            notification << set_color(log_color) << notification_str ;
            title << set_color(COLOR_YELLOW) << "ANIMAL RESERVE" ;

            showReserve(wReserve,reserve);
            showSimulatorMenu(wMenu,col,row);

            readCommand(wMenu);


        }while(command != "exit");

    }
}

void Simulator::showReserve(Window &window,Reserve &reserve) const {

    char **poSx_poSy = reserve.getReserve();
    int col,row;

    col = range_x - 2;
    row = range_y - 2;

    for(int i=0;i<col;i++){
        for(int k=0;k<row;k++)
            window << poSx_poSy[k][i];
    }
}

void Simulator::showSimulatorMenu(Window &window,int col,int row) const {

    window << set_color(COLOR_YELLOW);
    window << "SIMULATION DETAILS \n\n" << set_color(COLOR_GREEN);
    window << "TURN - " << turn_instance << '\n';
    window << "VIEW LIMIT (" << range_x-2<< ',' << range_y-2 << ')' << '\n';
    window << "RESERVE_SIZE (" << col << ',' << row << ")\n";
    window << "TOTAL FOOD - " << total_food << '\n';
    window << "TOTAL ANIMALS - " << total_animals << '\n';

}

bool Simulator::readCommand(Window &window) {

    stringstream cmd;
    string command_start,c2,c3,c4,c5;
    int words = 0;

    window << set_color(COLOR_BLUE)<< '\n' << "COMMAND:" ;
    window >> command;

    cmd << command;
    cmd >> command_start;

    for(char i : command){
        if(i == ' ')
            words ++;
    }

    if(command_start.compare("animal") == 0){

        if(words == 3){

            cmd >> c2; //species
            cmd >> c3; //row
            cmd >> c4; //col

            log_color = COLOR_GREEN;
            notification_str = "ANIMAL SPAWNER (species-"+c2+"|row-"+c3+"|col-"+c4+")";


        }else if(words == 1){

            cmd >> c2; //species;
            log_color = COLOR_GREEN;
            notification_str = "ANIMAL SPAWNER (species-"+c2+")";

        }else{

            log_color = COLOR_RED;
            notification_str = "ANIMAL COMMAND INVALID!";
            return false;

        }

        return true;


    }else if(command_start.compare("kill") == 0 || command_start.compare("killid") == 0){

        if(words == 2){

            cmd >> c2; //row
            cmd >> c3; //col
            log_color = COLOR_GREEN;
            notification_str = "KILL ANIMAL (row-"+c2+"|col-"+c3+")";


        }else if(words == 1){

            cmd >> c2; //id
            log_color = COLOR_GREEN;
            notification_str = "KILL ANIMAL (id-"+c2+")";

        }else{

            log_color = COLOR_RED;
            notification_str = "KILL COMMAND INVALID";
            return false;
        }

        return true;

    }else if(command_start.compare("food") == 0){

        if(words == 3){

            cmd >> c2; //type
            cmd >> c3; //row
            cmd >> c4; //col
            log_color = COLOR_GREEN;
            notification_str = "SPAWN FOOD (type-"+c2+"|row-"+c3+"|col-"+c4+")";


        }else if(words == 1){

            cmd >> c2; //id
            log_color = COLOR_GREEN;
            notification_str = "SPAWN FOOD (type-"+c2+")";

        }else{

            log_color = COLOR_RED;
            notification_str = "FOOD COMMAND INVALID";
            return false;
        }

        return true;

    }else if(command_start.compare("feed") == 0 || command_start.compare("feedid") == 0){

        if(command_start == "feed"){

                if(words == 4){
                    cmd >> c2; //row
                    cmd >> c3; //col
                    cmd >> c4; //n.points
                    cmd >> c5; // tox.points

                    log_color = COLOR_GREEN;
                    notification_str = "ANIMAL FEEDED (row-"+c2+"|col-"+c3+"|nutritiveP-"+c4+"|toxicP-"+c5+")";
                }else {

                    log_color = COLOR_RED;
                    notification_str = "FEED COMMAND INVALID";
                    return false;

                }

        }else if(command_start == "feedid"){

                if (words == 3){
                    cmd >> c2; //id
                    cmd >> c3; //n.points
                    cmd >> c4; //tox.points

                    log_color = COLOR_GREEN;
                    notification_str = "ANIMAL FEEDED (id-"+c2+"|nutritiveP-"+c3+"|toxicP-"+c4+")";
                }else{
                    log_color = COLOR_RED;
                    notification_str = "FEEDID COMMAND INVALID";
                    return false;
                }

        }else{

            log_color = COLOR_RED;
            notification_str = "COMMAND INVALID";
            return false;

        }

        return false;

    }else if(command_start.compare("nofood") == 0){

        notification_str = "remove food";

    }else if(command_start.compare("empty") == 0){

        notification_str = "clean reserve position";

    }else if(command_start.compare("see") == 0){

        notification_str = "see position stuff";

    }else if(command_start.compare("info") == 0){

        notification_str = "show info";

    }else if(command_start.compare("n") == 0){

        notification_str = "advance simulation";

    }else if(command_start.compare("anim") == 0){

        notification_str = "List animals id";

    }else if(command_start.compare("visanim") == 0){

        notification_str = "List animals idd";

    }else if(command_start.compare("store") == 0){

        notification_str = "save reserve in memory";

    }else if(command_start.compare("restore") == 0){

        notification_str = "reload saved reserve";

    }else if(command_start.compare("load") == 0){

        notification_str = "load command from file";

    }else if(command_start.compare("slide") == 0){

        notification_str = "slide reserve area";

    }else{
        notification_str = "COMMAND NOT FOUND";
        log_color = COLOR_RED ;
        return false;
    }

    log_color = COLOR_GREEN;
    return true;
}