#include <iostream>
#include <cmath>

// Function to calculate sine in degrees with a given epsilon
double sine(double x, double delta) {
    double theFunct;
    double derivativeOfFunct;
    
    do {
        theFunct = sin(x * M_PI / 180.0); // Convert to radians
        derivativeOfFunct = cos(x * M_PI / 180.0); // Convert to radians
        x = x - (theFunct / derivativeOfFunct);
    } while (fabs(theFunct) >= delta);

    return theFunct;
}

int main() {
    double x;
    double delta;
    
    std::cout << "Input the value in degrees: ";
    std::cin >> x;
    
    std::cout << "Input the delta: ";
    std::cin >> delta;

    std::cout << "sin(" << x << " degrees) = " << sine(x, delta) << std::endl;

    return 0;
}