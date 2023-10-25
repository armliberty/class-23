#include <iostream>
#include <map>
#include <string>

int computeGCD(int a, int b);
int computeLCM(int a, int b);

using TimeSig = std::pair<int, int>;
int computeOverlap(TimeSig, TimeSig);

int input(std::string msg);


int main(){
    int a1 = input("Insert hamarich"); 
    int a2 = input("Insert haytarar"); 
    int b1 = input("Insert hamarich");
    int b2 = input("Insert haytarar");

    TimeSig kotorak1;
    kotorak1.first = a1;
    kotorak1.second = a2;
    
    TimeSig kotorak2;
    kotorak2.first = b1;
    kotorak2.second = b2;

    std::cout << computeOverlap(kotorak1, kotorak2) << std::endl;
}


int input(std::string msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    double value;
    do
    {
        std::cin >> value;
        if(value < 0)  std::cout <<  "Please insert a positive number: "; 
    } while (value < 0);
    
    return value;
}


int computeOverlap(TimeSig kotorak1, TimeSig kotorak2){
    TimeSig new_kotorak1;
    new_kotorak1.second = computeLCM(kotorak1.second, kotorak2.second);
    new_kotorak1.first = new_kotorak1.second/kotorak1.second*kotorak1.first;
   
    TimeSig new_kotorak2;
    new_kotorak2.second = new_kotorak1.second;
    new_kotorak2.first = new_kotorak2.second/kotorak2.second*kotorak2.first;

    int result = computeLCM(new_kotorak1.first, new_kotorak2.first)/new_kotorak1.first;
    return result;

}


int computeGCD(int a, int b){
    int c;
    if (a < b)
    {
        c = a;
        a = b;
        b = c;
    }
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    
    return a;
}


int computeLCM(int a, int b){
    return (a*b)/computeGCD(a,b);
}


