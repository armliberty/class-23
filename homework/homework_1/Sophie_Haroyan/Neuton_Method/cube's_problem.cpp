#include <cmath>
#include <iostream>

double calculateCubeRoot(double x, double delta) {
    if (x < 0) {
        std::cerr << "Error: Input number must be non-negative." << std::endl;
        return -1.0;
    }

    double guess = x / 2.0;

    while (true) {
        double nextGuess = guess - ((guess * guess * guess - x) / (3.0 * guess * guess));
        
        if (std::abs(nextGuess - guess) <= delta) {
            return nextGuess;
        }

        guess = nextGuess;
    }
}

int main() {
    double x;
    std::cout << "Input the number: ";
    std::cin >> x;

    double delta;
    std::cout << "Input the accuracy: ";
    std::cin >> delta;

    double cubeRootResult = calculateCubeRoot(x, delta);
    if (cubeRootResult >= 0) {
        std::cout << "The cube root of " << x << " is " << cubeRootResult << "\n";
    }

    return 0;
}
