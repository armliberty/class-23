#include <iostream>
#include <cmath>

double cubeRoot(double x, double delta) {
    double latest = x;
    double previous;

    while (true) {
        previous = latest;
        latest = (2 * latest + x / (previous * previous)) / 3;
        if (std::abs(latest - previous) <= delta) {
            break;
        }
    }
    return latest;
}

int main() {
    double num;
    double delta;

    std::cout << "Enter the number: ";
    std::cin >> num;
    std::cout << "Enter the delta: ";
    std::cin >> delta;

    std::cout << "The cube root of number " << num << " is " << cubeRoot(num, delta) << "\n";
    std::cout << "Cubed result: " << pow(cubeRoot(num, delta), 3) << "\n";
    return 0;
}

