#include <iostream>
#include <cmath>

double cubeRoot(double x, double delta) {
    if (x == 0.0) {
        return 0.0;
    }
    double result = x;
    while (std::abs(result * result * result - x) > delta) {
        result = (2 * result + x / (result * result)) / 3;
    }
    return result;
}
int main() {
    double cube;
    std::cin >> cube;
    std::cout << cubeRoot(cube, 0.0001);
}