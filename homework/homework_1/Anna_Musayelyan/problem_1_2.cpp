#include <iostream>
#include <cmath>

double function(double x) {
    return sin(x);
}

double derivative(double x) {
    return cos(x);
}

double sine(double x, double delta) {
    double guess = x; 
    double df;

    while (fabs(function(guess)) > delta) {
        df = derivative(guess);
        guess = guess - function(guess) / df;
    }
    return guess;
}

int main() {
    double x;
    double delta = 1e-6;

    std::cout << "Enter a value to find its sine root (in radians): ";
    std::cin >> x;
    
    double result = sine(x, delta);
    std::cout << "Approximate Sine Root: " << result << std::endl;

    return 0;
}
