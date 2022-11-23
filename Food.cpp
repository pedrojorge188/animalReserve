#include "Food.h"

#include <utility>

Food::Food(char t, int i, int d, int n, int to, string s1, string s2) {
    type = t;
    id = i;
    duration = d;
    nutriValue = n;
    toxicity = to;
    smell_1 = s1;
    smell_2 = s2;
}
