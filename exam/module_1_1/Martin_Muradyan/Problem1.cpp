#include <iostream>
#include <vector>

using TimeSig = std::pair<int, int>;

int computeOverlap(TimeSig, TimeSig);
int computeGCD(int a, int b);
int computeLCM(int a, int b);
TimeSig input(){
    TimeSig in;
    std::cout<<"insert the nominator: ";
    std::cin>>in.first;
    std::cout<<"insert the dinominator: ";
    std::cin>>in.second;
    return in;
}

int main(void){
    const auto a = input();
    const auto b = input();
    std::cout<<computeOverlap(a,b)<<"\n";
}

int computeOverlap(TimeSig a, TimeSig b){
    int lcmofden = computeLCM(a.second, b.second);
    a.first *= lcmofden/a.second;
    b.first *= lcmofden/b.second;
    int lcmofnom = computeLCM(a.first,b.first);
    return lcmofnom/a.first;
}

int computeGCD(int a, int b){
    int t;
    while(b != 0){
    t = b;
    b = a%b;
    a=t;
  }
  return a;
}

int computeLCM(int a, int b){
    return a*b/computeGCD(a,b);
}
