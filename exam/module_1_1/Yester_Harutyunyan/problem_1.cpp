#include <iostream>

using TimeSig = std::pair<int, int>;

int input(const std::string& msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    int value;
    std::cin >> value;
    return value;
}

int computeOverlap(TimeSig ts1, TimeSig ts2);
int main() {

    int a1 = input("Input first bit");
    int b1 = input("Input first duration");
    int a2 = input("Input first bit");
    int b2 = input("Input first duration");

    TimeSig timeSig1 = std::make_pair(a1, b1);
    TimeSig timeSig2 = std::make_pair(a2, b2);

    int overlap = computeOverlap(timeSig1, timeSig2);

    std::cout << "Time signatures overlap every " << overlap << std::endl;

    return 0;
}


int euclideanGCD(int a, int b){
    int GCD = 1;
    while (a != 0 && b !=0 ){
        if(a > b){
            a = a % b;
        } else {
            b = b % a;
        }
    }
    GCD = a + b;
    return GCD;
}

int euclideanLCM(int a, int b){
    int GCD = euclideanGCD(a,b);
    int LCM;
    LCM = (a * b) / GCD;
    return LCM;
}

int computeOverlap(TimeSig ts1, TimeSig ts2) {
    int LCM = euclideanLCM(ts1.second, ts2.second);
    
    int overlap = LCM / ts1.second;

    return overlap;
}