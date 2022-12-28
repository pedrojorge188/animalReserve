
#include "Simulator.h"
#include "Food.h"
#include "Animal.h"
#include <unistd.h>

Simulator::Simulator(int row,int col) {

    randCol = 0;
    randRow = 0;


    min_range_x = 2;
    min_range_y = 2;
    row_Maxlimit = row;
    col_Maxlimit = col;
    max_range_x = col+2;
    max_range_y = row+2;
    instance[0] = 0; instance[1] = 0;
    window_range_x = max_range_x;
    window_range_y = max_range_y;

    turn_instance = 0;

    notification_str = " ";
    object_str  = " ";
    log_color = COLOR_GREEN;

    if(col > 40 || row > 25){
        max_range_x = 42;
        max_range_y = 22;
        window_range_x = max_range_x;
        window_range_y = max_range_y;
    }

}

void Simulator::SimulationProcess(int row,int col){

    Reserve reserve = Reserve(col, row);
    Terminal &t = Terminal::instance();

    for(int i=1; i<20; i++) {
        t.init_color(i, i, 0);
    }

    {
        do{
            random_device rd;
            mt19937 mt(rd());

            uniform_int_distribution<int> randomCol(0, col_Maxlimit - 1);
            uniform_int_distribution<int> randomRow(0, row_Maxlimit - 1);

            randRow = randomCol(mt);
            randCol = randomRow(mt);

            Window title = Window(15,2,20,1,false);
            Window wReserve = Window(0,3,window_range_x,window_range_y,true);
            Window wMenu = Window(window_range_x+2,6,34,16,false);
            Window notification = Window(2,window_range_y+4,45,4,false);
            Window objectInfo = Window(window_range_x+36,10,35,11,false);

            notification << set_color(log_color) << notification_str ;
            objectInfo << set_color(log_color) << object_str;

            title << set_color(COLOR_YELLOW) << "ANIMAL RESERVE" ;

            showReserve(wReserve,reserve);
            showSimulatorMenu(wMenu,col,row,reserve);

            sleep(instance[1]);

            if(instance[0] > 0) {
                reserve._newTurn();
                turn_instance++;
                instance[0]--;
                if(instance[0] == 0)
                    notification_str = "Simulation completed!";
            }else{

                instance[1]=0;

                if(!keyboard_detection(wMenu)){

                    wMenu << set_color(COLOR_BLUE)<< '\n' << "COMMAND:" ;
                    wMenu >> command;

                    readCommand(wMenu,reserve);
                }

            }

        }while(command != "exit");

    }
}

bool Simulator::keyboard_detection(Window &window) {

    std::string s;
    s.resize(200);
    window >> s;
    int aux_limiter;

    if (s == "KEY_UP") {

        int aux_range1,aux_range2;

        aux_range1 = min_range_y - 1;
        aux_range2 = max_range_y - 1;

        if( aux_range1 <= 1 ){

            log_color = COLOR_RED;
            notification_str = "SLIDE COMMAND (DISTANCE VALUE TO LONG)! ";
            return false;

        }else{

            min_range_y = min_range_y - 1;
            max_range_y = max_range_y - 1;
        }

    }else if (s == "KEY_DOWN") {

        aux_limiter = max_range_y+1;

        if(aux_limiter < row_Maxlimit){

            min_range_y =  min_range_y + 1;
            max_range_y = max_range_y + 1;

        }else{
            log_color = COLOR_RED;
            notification_str = "SLIDE COMMAND (DISTANCE VALUE TO LONG)! ";
            return false;
        }

    }else if (s == "KEY_LEFT") {

        int aux_range1,aux_range2;
        aux_range1 = min_range_x - 1;
        aux_range2 = max_range_x - 1;

        if(aux_range1 <= 1){

            log_color = COLOR_RED;
            notification_str = "SLIDE COMMAND (DISTANCE VALUE TO LONG)! ";
            return false;

        }else{

            min_range_x = min_range_x - 1;
            max_range_x = max_range_x - 1;

        }

    }else if (s == "KEY_RIGHT") {

        aux_limiter = max_range_x+1;

        if(aux_limiter < row_Maxlimit){

            min_range_x =  min_range_x + 1;
            max_range_x = max_range_x + 1;

        }else{
            log_color = COLOR_RED;
            notification_str = "SLIDE COMMAND (DISTANCE VALUE TO LONG)! ";
            return false;
        }

    }else{
        return false;
    }

    return true;
}

void Simulator::showReserve(Window &window,Reserve &reserve) const {

    char **poSx_poSy = reserve.getReserve();
    int col,row,col_start,row_start;

    col_start = min_range_x - 2;
    row_start = min_range_y - 2;

    col = max_range_x - 2;
    row = max_range_y - 2;

    for(int i=row_start;i<row;i++){
        for(int k=col_start;k<col;k++)
            window << poSx_poSy[i][k];
    }
}

void Simulator::showSimulatorMenu(Window &window,int col,int row,Reserve &r) const {

    window << set_color(COLOR_YELLOW);
    window << "SIMULATION DETAILS \n\n" << set_color(COLOR_GREEN);
    window << "TURN - " << turn_instance << "\n\n";
    window << "ROW VIEW AREA (" << min_range_y-2 << "->" << max_range_y-2 << ") pixels" << '\n';
    window << "COLUMN VIEW AREA (" << min_range_x-2 << "->" << max_range_x-2 << ") pixels" << "\n\n";
    window << "RESERVE_SIZE (" << row << ',' << col << ")\n";
    window << "TOTAL FOOD - " << r._getTotalFood() << '\n';
    window << "TOTAL ANIMALS - " << r._getTotalAnimals() << '\n';
    window << '\n' <<"(PRESS ENTER TO WRITE COMMAND)" << '\n';

}

bool Simulator::readCommand(Window &window, Reserve &r) {

    char **pos = r.getReserve();
    stringstream cmd;
    string command_start,c2,c3,c4,c5;
    int words = 0,d3,d4,d5,d6;
    pair <string ,string> req;

    cmd << command;
    cmd >> command_start;

    for(char i : command){
        if(i == ' ')
            words ++;
    }

    if(command_start.compare("animal") != 0 || command_start.compare("food") != 0)
        object_str = " ";

    if(command_start.compare("animal") == 0){

        if(words == 3){

            cmd >> c2; //species
            cmd >> d3; //row
            cmd >> d4; //col

            c3 = to_string(d3);
            c4 = to_string(d4);

            if( c3 != "0" || c4 != "0"){
                if(d3 == 0 || d4 == 0){

                    log_color = COLOR_RED;
                    notification_str = "ANIMAL ROW/LINE INVALID!";
                    object_str = " ";
                    return false;

                }
            }

            if(c2 != "c" && c2 != "o" && c2 != "l" && c2 != "g" && c2 != "m"){

                log_color = COLOR_RED;
                notification_str = "ANIMAL SPECIES INVALID!";
                object_str = " ";
                return false;

            }

            req = r.spawnAnimal(d4-1,d3-1,c2[0]);

            object_str = req.first;
            notification_str = req.second;



        }else if(words == 1){

            cmd >> c2; //species;

            if(c2 != "c" && c2 != "o" && c2 != "l" && c2 != "g" && c2 != "m"){

                log_color = COLOR_RED;
                notification_str = "ANIMAL SPECIES INVALID!";
                object_str = " ";
                return false;
            }

            req = r.spawnAnimal(randCol,randRow,c2[0]);

            object_str = req.first;
            notification_str = req.second;

        }else{

            log_color = COLOR_RED;
            notification_str = "ANIMAL COMMAND INVALID!";
            object_str = " ";
            return false;

        }


        return true;
    }

    else if(command_start.compare("kill") == 0 || command_start.compare("killid") == 0){

        if(words == 2){

            cmd >> d3; //row
            cmd >> d4; //col

            c2 = to_string(d3);
            c3 = to_string(d4);

            if( c2 != "0" || c3 != "0"){

                if(d3 == 0 || d4 == 0){
                    log_color = COLOR_RED;
                    notification_str = "KILL COMMAND INVALID!";
                    return false;
                }

            }

            if(r.killAnimal(d3-1,d4-1) == 1){
                log_color = COLOR_GREEN;
                notification_str = "KILL ANIMAL (row-"+c2+"|col-"+c3+")";
            }


        }else if(words == 1 && command_start == "killid"){

            cmd >> d3; //id
            c2 = to_string(d3);

            if(c2 == "0"){
                if(d3 == 0){
                    log_color = COLOR_RED;
                    notification_str = "KILL WITH ID COMMAND INVALID!";
                    return false;
                }
            }

            if( r.killAnimal(d3)){
                log_color = COLOR_GREEN;
                notification_str = "KILL ANIMAL (id-"+c2+")";
            }else{
                log_color = COLOR_RED;
                notification_str = "YOU DONT KILL ANIMAL (id-"+c2+")";
            }

        }else{

            log_color = COLOR_RED;
            notification_str = "KILL COMMAND INVALID";
            return false;
        }

        return true;

    }
    else if(command_start.compare("food") == 0){

        if(words == 3){

            cmd >> c2; //type
            cmd >> d3; //row
            cmd >> d4; //col

            c3 = to_string(d3);
            c4 = to_string(d4);

            if( c3 != "0" || c4 != "0"){

                if(d3 == 0 || d4 == 0){
                    log_color = COLOR_RED;
                    notification_str = "FOOD ROW/COL COMMAND INVALID!";
                    object_str = " ";
                    return false;
                }

            }

            if(c2 != "r" && c2 != "t" && c2 != "b" && c2 != "a" ){

                log_color = COLOR_RED;
                notification_str = "FOOD TYPE INVALID!";
                object_str = " ";
                return false;

            }

            req = r.spawnFood(d4-1,d3-1,c2[0]);

            object_str = req.first;
            notification_str = req.second;



        }else if(words == 1){

            cmd >> c2; //type

            if(c2 != "r" && c2 != "t" && c2 != "b" && c2 != "a"){

                log_color = COLOR_RED;
                notification_str = "FOOD TYPE INVALID!";
                object_str = " ";
                return false;

            }

            req = r.spawnFood(randCol,randRow,c2[0]);

            object_str = req.first;
            notification_str = req.second;


        }else{

            log_color = COLOR_RED;
            notification_str = "FOOD COMMAND INVALID";
            object_str = " ";
            return false;
        }

        return true;

    }
    else if(command_start.compare("feed") == 0 || command_start.compare("feedid") == 0){

        if(command_start == "feed"){

            if(words == 4){

                cmd >> d3; //row
                cmd >> d4; //col
                cmd >> d5; //n.points
                cmd >> d6; // tox.points

                c2 = to_string(d3);
                c3 = to_string(d4);
                c4 = to_string(d5);
                c5 = to_string(d6);

                if( c2 != "0" || c3 != "0" || c4 != "0" || c5 != "0"){
                    if(d3 == 0 || d4 == 0 || d5 == 0 || d6 == 0){

                        log_color = COLOR_RED;
                        notification_str = "FEED INVALID!";
                        return false;

                    }
                }

                log_color = COLOR_GREEN;
                notification_str = r._feedAnimals(d3-1,d4-1,d5,d6);

            }else {

                log_color = COLOR_RED;
                notification_str = "FEED COMMAND INVALID";
                return false;

            }

        }else if(command_start == "feedid"){

            if (words == 3){

                cmd >> d3; //id
                cmd >> d4; //n.points
                cmd >> d5; //tox.points

                c2 = to_string(d3);
                c3 = to_string(d4);
                c4 = to_string(d5);

                if( c2 != "0" || c3 != "0" || c4 != "0"){
                    if(d3 == 0 || d4 == 0 || d5 == 0){

                        log_color = COLOR_RED;
                        notification_str = "FEED INVALID!";
                        return false;

                    }
                }

                log_color = COLOR_GREEN;
                notification_str = r._feedAnimals(d3,d4,d5);

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

    }
    else if(command_start.compare("nofood") == 0){

        if(words == 2){

            cmd >> d3; //row
            cmd >> d4; //col

            c2 = to_string(d3);
            c3 = to_string(d4);

            if( c2 != "0" || c3 != "0"){

                if(d3 == 0 || d4 == 0){
                    log_color = COLOR_RED;
                    notification_str = "NOFOOD COMMAND (ROW/COL) INVALID!";
                    return false;
                }

            }

            if(r.killFood(d3-1,d4-1) == 1){
                log_color = COLOR_GREEN;
                notification_str = "FOOD REMOVED (row-"+c2+"|col-"+c3+")";
            }


        }else if(words == 1){

            cmd >> d3; //id
            c2 = to_string(d3);

            if(c2 == "0"){
                if(d3 == 0){
                    log_color = COLOR_RED;
                    notification_str = "NOFOOD WITH ID COMMAND INVALID!";
                    return false;
                }
            }

            if( r.killFood(d3)){
                log_color = COLOR_GREEN;
                notification_str = "FOOD REMOVED (id-"+c2+")";
            }else{
                log_color = COLOR_RED;
                notification_str = "YOU DONT REMOVE FOOD (id-"+c2+")";
            }

        }else{

            log_color = COLOR_RED;
            notification_str = "NOFOOD COMMAND INVALID";
            return false;
        }

    }
    else if(command_start.compare("empty") == 0){

        if(words == 2){

            cmd >> d3; //row
            cmd >> d4; //col

            c2 = to_string(d3);
            c3 = to_string(d4);

            if( c2 != "0" || c3 != "0"){

                if(d3 == 0 || d4 == 0){
                    log_color = COLOR_RED;
                    notification_str = "EMPTY COMMAND INVALID!";
                    return false;
                }

            }

            log_color = COLOR_GREEN;
            notification_str = "CLEAN POSITION (row-"+c2+"|col-"+c3+")";


        }else{

            log_color = COLOR_RED;
            notification_str = "EMPTY COMMAND INVALID";
            return false;
        }

    }
    else if(command_start.compare("see") == 0){

        if(words == 2){

            cmd >> d3; //row
            cmd >> d4; //col

            c2 = to_string(d3);
            c3 = to_string(d4);

            if( c2 != "0" || c3 != "0"){

                if(d3 == 0 || d4 == 0){
                    log_color = COLOR_RED;
                    notification_str = "SEE (COL/ROW) COMMAND INVALID!";
                    return false;
                }

            }

            log_color = COLOR_GREEN;
            notification_str = "SEE POSITION (row-"+c2+"|col-"+c3+")";


        }else{

            log_color = COLOR_RED;
            notification_str = "SEE COMMAND INVALID";
            return false;
        }

    }
    else if(command_start.compare("info") == 0){

        if(words == 1){

            cmd >> d3; //id
            c2 = to_string(d3);

            if( c2 != " " && c2 != "0" ){

                if(d3 == 0){
                    log_color = COLOR_RED;
                    notification_str = "INFO COMMAND INVALID!";
                    return false;
                }

            }


        }else{
            log_color = COLOR_RED;
            notification_str = "INFO COMMAND INVALID!";
            return false;
        }

    }
    else if(command_start.compare("n") == 0){

        if(words == 2){

            cmd >> d3; //instants
            cmd >> d4; //pauses

            c3 = to_string(d3);
            c4 = to_string(d4);

            if( c3 != "0" || c4 != "0"){

                if(d3 == 0 || d4 == 0){

                    log_color = COLOR_RED;
                    notification_str = "Next Turn (N) COMMAND INVALID!";

                    return false;
                }

            }

            log_color = COLOR_GREEN;

            instance[0] = d3;
            instance[1] = d4;

            notification_str = "ADVANCING..";

        }else if(words == 1){

            cmd >> d3; //turns
            c2 = to_string(d3);

            for(int i=0;i<d3;i++){
                r._newTurn();
            }

            log_color = COLOR_GREEN;
            notification_str = "ADVANCE'"+c2+"'TURNS";
            turn_instance+=d3;

        }else if (words == 0){

            log_color = COLOR_GREEN;
            notification_str = "ADVANCE TURN";

            r._newTurn();
            turn_instance++;

        }else{

            log_color = COLOR_RED;
            notification_str = "N COMMAND INVALID";
            turn_instance++;

            return false;
        }

    }
    else if(command_start.compare("anim") == 0){

        //object_str = r.animalsInReserve();
        object_str = r.foodInReserve();

    }
    else if(command_start.compare("visanim") == 0){

        pair <int,int> _range_x (min_range_x, max_range_x);
        pair <int,int> _range_y (min_range_y, max_range_y);

        object_str = r.animalsInReserve(_range_y,_range_x);

    }
    else if(command_start.compare("store") == 0){

        cmd >> c2;
        log_color = COLOR_GREEN;
        notification_str = "SAVE RESERVE IN FILE ("+c2+")";

    }
    else if(command_start.compare("restore") == 0){

        cmd >> c2;
        log_color = COLOR_GREEN;
        notification_str = "RESTORE RESERVE IN FILE ("+c2+")";

    }
    else if(command_start.compare("load") == 0){

        cmd >> c2;

        string data;
        fstream commandFile;
        commandFile.open("../"+c2);

        if(commandFile.is_open()){
            while(getline(commandFile,command)){
                readCommand(window,r);
                log_color  = COLOR_GREEN;
            }
        }else{
            log_color = COLOR_RED;
            notification_str = "ERROR OPENING ("+c2+")FILE";
            return false;
        }

    }
    else if(command_start.compare("slide") == 0){

        if (words == 2){

            cmd >> c2; //direction
            cmd >> d4; //pixels

            c3 = to_string(d4);

            if(c3 != "0"){

                if(d4 == 0){

                    log_color = COLOR_RED;
                    notification_str = "SLIDE COMMAND (ROWS/COLS) INVALID!";
                    return false;
                }

            }

            if(c2 != "up" && c2 != "right" && c2 != "left" && c2 != "down"){

                log_color = COLOR_RED;
                notification_str = "SLIDE COMMAND (DIRECTION) INVALID!";
                return false;
            }

            //for future scope function

            int aux_limiter = 0;

            if(c2 == "right"){

                aux_limiter = max_range_x+d4;

                if(aux_limiter < row_Maxlimit){

                    min_range_x =  min_range_x + d4;
                    max_range_x = max_range_x + d4;

                }else{
                    log_color = COLOR_RED;
                    notification_str = "SLIDE COMMAND (DISTANCE VALUE TO LONG)! ";
                    return false;
                }

            }else if(c2 == "left"){

                int aux_range1,aux_range2;

                if(d4 > 0){

                    aux_range1 = min_range_x - d4;
                    aux_range2 = max_range_x - d4;

                    if(aux_range1 < 0){

                        log_color = COLOR_RED;
                        notification_str = "SLIDE COMMAND (DISTANCE VALUE TO LONG)! ";
                        return false;

                    }else{

                        min_range_x = min_range_x - d4;
                        max_range_x = max_range_x - d4;

                    }
                }

            }else if(c2 == "down"){

                aux_limiter = max_range_y+d4;

                if(aux_limiter < row_Maxlimit){

                    min_range_y =  min_range_y + d4;
                    max_range_y = max_range_y + d4;

                }else{
                    log_color = COLOR_RED;
                    notification_str = "SLIDE COMMAND (DISTANCE VALUE TO LONG)! ";
                    return false;
                }

            }else if(c2 == "up"){

                int aux_range1,aux_range2;

                if(d4 > 0){

                    aux_range1 = min_range_y - d4;
                    aux_range2 = max_range_y - d4;

                    if(aux_range1 < 0){

                        log_color = COLOR_RED;
                        notification_str = "SLIDE COMMAND (DISTANCE VALUE TO LONG)! ";
                        return false;

                    }else{

                        min_range_y = min_range_y - d4;
                        max_range_y = max_range_y - d4;

                    }
                }

            }

            log_color = COLOR_GREEN;
            notification_str = "SLIDE (STATUS SUCCESS)! ";

        }
        else{
            log_color = COLOR_RED;
            notification_str = "SLIDE COMMAND INVALID";
            return false;
        }

    }else{

        notification_str = "COMMAND NOT FOUND";
        log_color = COLOR_RED ;
        return false;

    }

    log_color = COLOR_GREEN;
    return true;
}

