
#include "Simulator.h"
#include "Food.h"
#include "Animal.h"
#include <unistd.h>

Simulator::Simulator(int row,int col) {

    randCol = 0;
    randRow = 0;

    total_animals = 1;
    total_food = 1;

    min_range_x = 2;
    min_range_y = 2;
    row_Maxlimit = row;
    col_Maxlimit = col;
    max_range_x = col+2;
    max_range_y = row+2;

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
            Window objectInfo = Window(window_range_x+36,10,20,11,false);

            notification << set_color(log_color) << notification_str ;
            objectInfo << set_color(log_color) << object_str;

            title << set_color(COLOR_YELLOW) << "ANIMAL RESERVE" ;

            showReserve(wReserve,reserve);
            showSimulatorMenu(wMenu,col,row);

            if(!keyboard_detection(wMenu)){

                wMenu << set_color(COLOR_BLUE)<< '\n' << "COMMAND:" ;
                wMenu >> command;

                readCommand(wMenu,reserve);
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

void Simulator::showSimulatorMenu(Window &window,int col,int row) const {

    window << set_color(COLOR_YELLOW);
    window << "SIMULATION DETAILS \n\n" << set_color(COLOR_GREEN);
    window << "TURN - " << turn_instance << "\n\n";
    window << "ROW VIEW AREA (" << min_range_y-2 << "->" << max_range_y-2 << ") pixels" << '\n';
    window << "COLUMN VIEW AREA (" << min_range_x-2 << "->" << max_range_x-2 << ") pixels" << "\n\n";
    window << "RESERVE_SIZE (" << row << ',' << col << ")\n";
    window << "TOTAL FOOD - " << total_food << '\n';
    window << "TOTAL ANIMALS - " << total_animals-1 << '\n';
    window << '\n' <<"(PRESS ENTER TO WRITE COMMAND)" << '\n';

}

bool Simulator::readCommand(Window &window, Reserve &r) {

    char **pos = r.getReserve();
    stringstream cmd;
    string command_start,c2,c3,c4,c5;
    int words = 0,d3,d4,d5,d6;

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

            if(AnimalSpawner(r,c2[0],d4,d3)){

                log_color = COLOR_BLUE;
                showAnimalInfo(total_animals);
                notification_str = "ANIMAL SPAWNED";
                total_animals++;

            }else{

                log_color = COLOR_RED;
                notification_str = "ANIMAL SPAWNER FAILED";
                object_str = " ";

            }

        }else if(words == 1){

            cmd >> c2; //species;

            if(c2 != "c" && c2 != "o" && c2 != "l" && c2 != "g" && c2 != "m"){

                log_color = COLOR_RED;
                notification_str = "ANIMAL SPECIES INVALID!";
                object_str = " ";
                return false;

            }

            if(AnimalSpawner(r,c2[0],randCol,randRow)){

                log_color = COLOR_BLUE;
                showAnimalInfo(total_animals);
                notification_str = "ANIMAL SPAWNED";
                total_animals++;

            }else{

                log_color = COLOR_RED;
                notification_str = "ANIMAL SPAWNER FAILED";
                object_str = " ";

            }

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

            log_color = COLOR_GREEN;
            notification_str = "KILL ANIMAL (row-"+c2+"|col-"+c3+")";


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

            log_color = COLOR_GREEN;
            notification_str = "KILL ANIMAL (id-"+c2+")";

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

            if(c2 != "r" && c2 != "t" && c2 != "b" && c2 != "a" && c2 != "p"){

                log_color = COLOR_RED;
                notification_str = "FOOD TYPE INVALID!";
                object_str = " ";
                return false;

            }


            if(FoodSpawner(r,c2[0],d4,d3)){

                log_color = COLOR_BLUE;
                showFoodInfo(total_food);
                notification_str = "FOOD SPAWNED";
                total_food++;

            }else{

                log_color = COLOR_RED;
                notification_str = "FOOD SPAWNER FAILED";
                object_str = " ";

            }



        }else if(words == 1){

            cmd >> c2; //type

            if(c2 != "r" && c2 != "t" && c2 != "b" && c2 != "a" && c2 != "p"){

                log_color = COLOR_RED;
                notification_str = "FOOD TYPE INVALID!";
                object_str = " ";
                return false;

            }

            if(FoodSpawner(r,c2[0],randCol,randRow)){

                log_color = COLOR_BLUE;
                showFoodInfo(total_food);
                notification_str = "FOOD SPAWNED";
                total_food++;

            }else{

                log_color = COLOR_RED;
                notification_str = "FOOD SPAWNER FAILED";
                object_str = " ";

            }

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
                notification_str = "ANIMAL FEEDED (row-"+c2+"|col-"+c3+"|nutritiveP-"+c4+"|toxicP-"+c5+")";

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

            log_color = COLOR_GREEN;
            notification_str = "FOOD REMOVED (row-"+c2+"|col-"+c3+")";


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

            log_color = COLOR_GREEN;
            notification_str = "FOOD REMOVED (id-"+c2+")";

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

            showAnimalInfo(d3);

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

            notification_str = "ADVANCING..";

        }else if(words == 1){

            cmd >> d3; //turns
            c2 = to_string(d3);

            for(int i=0;i<d3;i++){
                move_animal(r);
            }

            log_color = COLOR_GREEN;
            notification_str = "ADVANCE'"+c2+"'TURNS";
            turn_instance+=d3;

        }else if (words == 0){

            log_color = COLOR_GREEN;
            notification_str = "ADVANCE TURN";

            move_animal(r);
            turn_instance++;

        }else{

            log_color = COLOR_RED;
            notification_str = "N COMMAND INVALID";
            turn_instance++;

            return false;
        }

    }
    else if(command_start.compare("anim") == 0){

        notification_str = "List animals id";

    }
    else if(command_start.compare("visanim") == 0){

        notification_str = "List animals idd";

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

bool Simulator::AnimalSpawner(Reserve &r,char type, int col, int row) {

    char **pos = r.getReserve();

    if(col <= 0 || col > col_Maxlimit || row <= 0 || row > row_Maxlimit)
        return false;

    if(type == 'c'){

        Animal animal = Coelho(total_animals, row, col);
        vector_animals.push_back(animal);

        auto animal_info =  vector_animals.begin();

        while (animal_info != this->vector_animals.end()) {

            if (animal_info->getId() == total_animals) {

                pos[row-1][col-1] = animal_info->getType();
                break;

            } else
                ++animal_info;
        }


    }
    else if(type == 'l') {

        Animal animal = Lobo(total_animals, row, col);
        vector_animals.push_back(animal);

        auto animal_info = vector_animals.begin();

        while (animal_info != this->vector_animals.end()) {

            if (animal_info->getId() == total_animals) {

                pos[row - 1][col - 1] = animal_info->getType();
                break;

            } else
                ++animal_info;
        }
    }else{
        return false;
    }

    return  true;
}

bool Simulator::FoodSpawner(Reserve &r, char type, int col, int row){

    char **pos = r.getReserve();

    if(col <= 0 || col > col_Maxlimit || row <= 0 || row > row_Maxlimit)
        return false;

    if(type == 'r'){

        Food food = Relva(total_food, row, col);
        vector_food.push_back(food);

        auto food_info = vector_food.begin();

        while (food_info != this->vector_food.end()) {

            if (food_info->getId() == total_food) {

                pos[row-1][col-1] = food_info->getType();
                break;

            } else
                ++food_info;
        }


    }else if(type == 't'){

        Food food = Cenoura(total_food, row, col);
        vector_food.push_back(food);

        auto food_info = vector_food.begin();

        while (food_info != this->vector_food.end()) {

            if (food_info->getId() == total_food) {

                pos[row-1][col-1] = food_info->getType();
                break;

            } else
                ++food_info;
        }

    }else if(type == 'p'){

        Food food = Corpo(total_food, row, col);
        vector_food.push_back(food);

        auto food_info = vector_food.begin();

        while (food_info != this->vector_food.end()) {

            if (food_info->getId() == total_food) {

                pos[row-1][col-1] = food_info->getType();
                break;

            } else
                ++food_info;
        }

    }else if(type == 'b'){

        Food food = Bife(total_food, row, col);
        vector_food.push_back(food);

        auto food_info = vector_food.begin();

        while (food_info != this->vector_food.end()) {

            if (food_info->getId() == total_food) {

                pos[row-1][col-1] = food_info->getType();
                break;

            } else
                ++food_info;
        }

    }else{
        return false;
    }

    return  true;

}

void Simulator::showAnimalInfo(int id) {

    auto animal_info = vector_animals.begin();

    ostringstream buf;

    while (animal_info != this->vector_animals.end()) {

        if (animal_info->getId() == id) {

            buf << "ANIMAL INFORMATION" << endl;
            buf << "ID:" << animal_info->getId() << endl;
            buf << "Type:" << animal_info->getType() << endl;
            buf << "Vitality: " << animal_info->getVitality() << endl;
            buf << "Hunger:" << animal_info->getHunger() << endl;
            buf << "Position(" <<animal_info->getPosY()<<','<<animal_info->getPosX()<< ')' << endl;

            object_str = buf.str();

            break;

        } else
            ++animal_info;

    }

}

void Simulator::showFoodInfo(int id){

    auto food_info =  vector_food.begin();

    ostringstream buf;

    while (food_info != this->vector_food.end()) {

        if (food_info->getId() == id) {

            buf << "FOOD INFORMATION" << endl;
            buf << "ID:" << food_info->getId() << endl;
            buf << "Type:" << food_info->getType() << endl;
            buf << "Duration" << food_info->getDuration() << endl;
            buf << "Position(" <<food_info->getPosY()<<','<<food_info->getPosX()<< ')' << endl;

            object_str = buf.str();
            break;

        } else
            ++food_info;

    }
}

void Simulator::move_animal(Reserve &r) {

    int rowHere=0;
    int colHere=0;
    char **pos = r.getReserve();

    auto animal_info =  vector_animals.begin();

    while (animal_info != this->vector_animals.end()) {

        int current_row = animal_info->getPosY();
        int current_col = animal_info->getPosX();

        pos[current_row-1][current_col-1] = ' ';

        animal_info->moveAnimal(r.getCollums(), r.getLines());

        int new_row = animal_info->getPosY();
        int new_col = animal_info->getPosX();

        pos[new_row-1][new_col-1] = animal_info->getType();

        ++animal_info;
    }

}
