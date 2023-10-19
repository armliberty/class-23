#include <iostream>
#include <cmath>
#include <limits>

double cubeRoot(double, double);

int main() {
    double del, x;
    std::cout << "Input x: ";
    std::cin >> x;
    std::cout << "Input Delta: ";
    std::cin >> del;

    double result = cubeRoot(x, del);

    std::cout << "Approximate Cube Root: " << result << std::endl;
    return 0;
}

double cubeRoot(double x, double del) {
    double x0 = x;
    int maxIterations = 1000; 
    int iterations = 0;

    while (iterations < maxIterations) {
        double n = x0 - ((pow(x0, 3) - x) / (3 * pow(x0, 2)));
        if (std::abs(x0 - n) <= del ) {
            return n;
        }
        x0 = n;
        iterations++;
    }
    return x0;
}
