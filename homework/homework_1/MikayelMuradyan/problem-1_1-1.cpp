#include <cmath>
#include <iostream>

double cubeRoot(double x, double delta);

int main() {
    double n, delta = 0.001;
    std::cout << "n: "; std::cin >> n;
    std::cout << "cuberoot: " << cubeRoot(n,delta) << std::endl;
    std::cout << "pow: " << std::pow(n, 1.0/3) << std::endl;
    return 0;
}

double cubeRoot(double x, double delta) {
    auto currentValue = x;
    double previousValue;

    do {
        previousValue = currentValue;
        currentValue = (2 * previousValue + x / (previousValue * previousValue))/3;
    }while(std::abs(currentValue - previousValue) > delta);
    return currentValue;
}
