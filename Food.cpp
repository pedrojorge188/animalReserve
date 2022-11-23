#include "Food.h"

#include <utility>

Food::Food(char t, int i,int r,int c, int d, int n, int to, string s1, string s2):id(i) {
    type = t;
    row = r;
    col = c;
    duration = d;
    nutriValue = n;
    toxicity = to;
    smell_1 = s1;
    smell_2 = s2;
}
