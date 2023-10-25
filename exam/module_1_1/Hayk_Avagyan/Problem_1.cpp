#include <iostream>
#include <numeric>

using TimeSig = std::pair<int, int>;
int computeOverlap(TimeSig, TimeSig);

int computeOverlap(TimeSig time1, TimeSig time2){
    int lcm_result = std::lcm(time1.second, time2.second);
    time1.first = (lcm_result / time1.second) * time1.first;
    time2.first = (lcm_result / time2.second) * time2.first;
    int result = std::lcm(time1.first, time2.first);
    if (time1.first < time2.first){
         result =  result / time1.first;
    } else {
        result =  result / time2.first;
    }
    return result;
}

int main(){
    TimeSig time1 = {3, 4};
    TimeSig time2 = {5, 5};
    std::cout << computeOverlap(time1, time2)<<std::endl;
}



