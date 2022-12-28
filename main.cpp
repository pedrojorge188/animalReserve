#include <iostream>

#include "utils.h"
#include "Reserve.h"
#include "Animal.h"
#include "Simulator.h"
#include "curses.h"
#include "Terminal.h"


#include <vector>
#include "Food.h"
#include "Grass\Grass.h"


int main() {
    /*
    vector <Food *> f;

    Food *relva1;
    relva1 = new Grass(1, 1, 1);
    //Food *relva2 = new Grass(2, 10, 1);
    //Food *relva3 = new Food(3, 1, 10);
    //Food *relva4 = new Food(4, 12, 2);

    f.push_back(relva1);

    auto i = f.begin();

    (*i)->











    vector <Animal> animals;
    ostringstream buf;

    Rabbit coelho1(1,0,0);

    Sheep Sheep1(2,5,5);
    Wolf Wolf1(3,7,7);
    Kangaroo k1(4,15,222);
    Mysterio m1(5,12,222);

    animals.push_back(coelho1);
    animals.push_back(Sheep1);
    animals.push_back(Wolf1);
    animals.push_back(k1);
    animals.push_back(m1);

    auto i = animals.begin();

    animals.erase(i);

    while(i != animals.end()){

        buf = i->printInfo();
        cout << buf.str() << endl;

        ++i;
    }

*/
    int rows,cols;

    cout << "INSERT RESERVE AREA!" << endl;
    cout << "ROWS:";
    cin >> rows;
    cout << "COLUMNS:";
    cin >> cols;

    Simulator sim = Simulator(rows,cols);

    sim.SimulationProcess(rows,cols);

    return 0;

}