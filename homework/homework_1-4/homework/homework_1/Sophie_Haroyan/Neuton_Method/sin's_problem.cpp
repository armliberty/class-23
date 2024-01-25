#include <cmath>
#include <iostream>

double calculateSin(double x, double delta) {
    double guess = x;

    while (true) {
        double nextGuess = guess - ((std::sin(guess) - x) / std::cos(guess));
        
        if (std::abs(nextGuess - guess) <= delta) {
            return nextGuess;
        }

        guess = nextGuess;
    }
}

int main() {
    double x;
    std::cout << "Input the angle in radians: ";
    std::cin >> x;

    double delta;
    std::cout << "Input the accuracy: ";
    std::cin >> delta;

    double sinResult = calculateSin(x, delta);
    std::cout << "sin(" << x << ") is approximately " << sinResult << "\n";

    return 0;
}
