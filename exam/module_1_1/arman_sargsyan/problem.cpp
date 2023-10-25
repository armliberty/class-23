#include <iostream>
#include <cmath>
using TimeSig = std::pair<int, int>;
int computeOverlap(TimeSig, TimeSig);

int computeOverlap(TimeSig one, TimeSig two){
    if ( one.second == two.second ) {
        TimeSig max;
        if ( one.first > two.first ) {
            max = two;
        } else {
            max = one;
        }
        int deleta = abs( one.first - two.first );
        for (int i = 1; i < 100; i++) {
            if ( (deleta * i) % max.first == 0) {
                return i;
            }
        }
    }
    return 0;
}
