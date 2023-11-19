#include <iostream>
#include <cmath>

double cubeRoot(double x, double delta = 0.0001) {
    double current = x;
    if (x < 0) {
        std::cout << "Error: Cannot calculate negative number." << std::endl;
        return NAN; 
    }

    double preValue;
    do {
        preValue = current;
        current = (2 * preValue + x / (preValue * preValue)) / 3.0;
    } while (std::abs(current - preValue) > delta);

    return current;
}

int main() {
    std::cout <<"Using Newton's method : "<< cubeRoot(50) << std::endl;
    std::cout <<"Using pow() func : " << pow(50, 1.0/3) << std::endl;
}


