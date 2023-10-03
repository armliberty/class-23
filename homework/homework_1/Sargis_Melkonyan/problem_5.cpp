/*
5. Implement Euclid's algorithm for GCD and LCM and compare the 
 complexity with <code>primeFactorize</code>-based version.
 */

#include <iostream>
#include <string>

int input(std::string);
int euclide(int, int);
inline int compute_lcm(int a, int b, int gcd){return a * b / gcd;}

int main(){
    const auto x = input("x = ");
    const auto y = input("y = ");
    const auto gcd = euclide(x, y);
    const int lcm = compute_lcm(x, y, gcd);

    std::cout << "GCD = " << gcd << std::endl;
    std::cout << "LCM = " << lcm << std::endl;

    return 0;
}



int input(std::string msg) {
    int value;
    std::cout << msg ;
    std::cin >> value;

    return value;    
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
