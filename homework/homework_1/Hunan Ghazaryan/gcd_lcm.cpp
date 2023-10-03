#include <iostream>
#include <string>

int euclide(int, int);
int compute_lcm(int, int, int);

int main(){
    int x,y;
    std::cout<<"Input x :";
    std::cin>>x;
    std::cout<<"Input y :";
    std::cin>>y;
    int gcd = euclide(x, y);
    int lcm = compute_lcm(x, y, gcd);
    std::cout << "GCD = " << gcd << std::endl;
    std::cout << "LCM = " << lcm << std::endl;

    return 0;
}

int compute_lcm(int a, int b, int gcd){
    return a * b / gcd;
    }

int euclide(int a, int b){
    int c;

    while(a % b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return b;
}
