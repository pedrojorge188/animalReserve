#include "Animal.h"


Animal::Animal(char t, int i, int in, int p, int w, int we1, int we2, int v, int h, string ps, int iw, int tb, int db) {

            type = t;
            id = i;
            iniHealth = in;
            perception = p;
            walkDistance = w;
            weightMax = we1;
            weightMin = we2;
            vitality = v;
            hunger = h;
            preferedSmell = ps;
            interactWeight = iw;
            timeBorn = tb;
            deadBodyValue = db;
            
}
