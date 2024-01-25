#include <iostream>
#include <cmath>

double cubeRoot(double x, double delta) {
    double n= x / 3; 

    while (std::abs(x - n * n* n) > delta) {
        n = (2 * n + x / (n * n)) / 3; 
    }

    return n;
}

int main() {
    double x;
    std::cout << "Enter a x: ";
    std::cin >> x;
    
    double delta;
    std::cout << "Enter a delta: ";
    std::cin >> delta;
    
    
    double result = cubeRoot(x,delta);
    std::cout << "Cube root of " << x << " is: " << result << std::endl;
    
    return 0;
}