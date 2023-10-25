#include <iostream>

using TimeSig = std::pair<int, int>;
int computeOverlap(TimeSig, TimeSig);

int main(){
    int a1, a2, b1, b2;
    std::cout<<"cin a1 and b1:"<<std::endl;
    std::cin>>a1>>b1;
    std::cout<<"cin a2 and b2:"<<std::endl;
    std::cin>>a2>>b2;
    TimeSig first(a1, b1);
    TimeSig second(a2, b2);
    std::cout << "Overlap:" << computeOverlap(first, second) << std::endl;
}

int computeOverlap(TimeSig, TimeSig){
    


}
