#include <cmath>
#include <iostream>

double cubeRoot(double x, double delta);

int main() {
    double x, delta = 0.001;
    std::cout << "x: "; std::cin >> x;
    std::cout << "cuberoot: " << cubeRoot(x,delta) << std::endl;
    std::cout << "pow: " << std::pow(x, 1.0/3) << std::endl;
    return 0;
}

double cubeRoot(double x, double delta) {
    auto currentValue = x;
    double previousValue;

    do {
        previousValue = currentValue;
        currentValue = previousValue + (x / (previousValue * previousValue) - previousValue)/3;
    }while(std::abs(currentValue - previousValue) > delta);
    return currentValue;
}
