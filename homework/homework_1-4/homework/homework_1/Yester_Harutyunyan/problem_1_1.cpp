#include <cmath>
#include <iostream>

double cubeRoot(double x, double delta);
template <typename T>
T input(std::string msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    T value;
    std::cin >> value;
    return value;
}

int main() {
    const auto x = input<double>("Please input x");
    double delta = 0.00001;
    std::cout << "cubeRoot: " << cubeRoot(x, delta) <<std::endl;
    std::cout << "pow: " <<pow(x,1.0/3) << std::endl;
}

double cubeRoot(double x, double delta){
    double approximationOfX;
    double initialX = x;
    approximationOfX = initialX - ((pow(initialX,3) - x) / (3*pow(initialX,2)));
    while (fabs(initialX - approximationOfX) > delta){
        initialX = approximationOfX;
        approximationOfX = initialX - ((pow(initialX,3) - x) / (3 * pow(initialX,2)));
    }
    return approximationOfX;
}

