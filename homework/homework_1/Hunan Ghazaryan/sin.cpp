#include <iostream>
#include <cmath>

double SIN(double, double);

int main() {

    double del, x;
    std::cout << "Input x: ";
    std::cin >> x;
    std::cout << "Input Delta: ";
    std::cin >> del;
    std::cout << "Answer: " << SIN(x, del) << std::endl;
    return 0;
}

double SIN(double x, double del) {
    double x0 = x;
    while (true) {
        if (std::abs(sin(x) - x0) <= del) {
            break;  
        }
        x = x0 - (sin(x) - x0 / cos(x0) - 1);
        x0 = x;
    }
    return x;
}
