#include <cmath>
#include <iostream>

double sine(double x, double delta);
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
    const auto delta = input<double>("Please input delta");
    std::cout << "sine: " << sine(x, delta) <<std::endl;
    std::cout<<sin(x)<<std::endl;
}

double sine(double x, double delta){
    double approximationOfX;
    int i=0;
    approximationOfX = x - ((sin(x) - x) / (cos(x) - 1));
    while ((x - approximationOfX) > delta){
        x = approximationOfX;
        approximationOfX = x - ((sin(x) - x) / (cos(x) - 1));
    }
    return approximationOfX;
}