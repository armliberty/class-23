#include <iostream>
#include <cmath>

double sine(double x, double delta) {
    double latest = x;
    double previus;

    while (true) {
        previus = latest;
        latest = previus - (sin(previus) - x) / (cos(previus)-1);

        if (abs(latest - previus) <= delta) {
            break;
        }
    }

    return latest;
}

int main() {
    double angle;
    std::cout << "Enter the size of the angle: ";
    std::cin >> angle;

    double delta;
    std::cout << "Enter the delta: ";
    std::cin >> delta;

    std::cout << "Newton method:: " << "Sine(" << angle << ") = " << sine(angle, delta) <<"\n";
    std::cout << "sin(" << angle << ") = " << sin(angle) <<"\n";

    return 0;
}