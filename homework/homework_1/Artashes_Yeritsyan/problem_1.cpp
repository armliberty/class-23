#include <cmath>
#include <iostream>

double input(const std::string &msg);
double cubeRoot(double x, double delta);
double sine(double x, double delta);

int main() {
    const double x = input("Input X");
    const double delta = input("Input Delta");

    const auto root = sine(x, delta);

    std::cout << "root = " << root << std::endl;
    return 0;
}

double cubeRoot(double x, double delta) {
    if(x < 1) {
        return -1;
    }
    double x0 = x;

    while (true) {
        double n = x0 - (x0 * x0 * x0 - x) / (3 * x0 * x0 );

        if (std::fabs(x0 - n) <= delta ) {
            return n;
        }
        x0 = n;
    }
    return x0;
}

double sine(double x, double delta)
{
    double x0 = x;
    double y;
    double derivedY;
    while (true) {
        y = std::sin(x0) - x0;
        derivedY = std::cos(x0) - 1;

        if (std::abs(y) < delta) {
            return x0;  
        }

        x0 = x0 - y / derivedY;
    }
    
    return x0;
}

double input(const std::string &msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }

    double value;
    std::cin >> value;

    return value;
}
