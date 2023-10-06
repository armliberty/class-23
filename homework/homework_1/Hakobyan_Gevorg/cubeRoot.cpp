#include <cmath>
#include <iostream>
#include <vector>

double cubeRoot(double, double);
double initialGUES(double);

int main() {
    double num;
    std::cout << "Input the number: ";
    std::cin >> num;

    double delta;
    std::cout << "Input the accuracy: ";
    std::cin >> delta;

    std::cout << "The cube root of " << num << " is " << cubeRoot(num,delta) << "\n";
    return 0;
}

double cubeRoot(double num, double delta) {
    double initialGues = initialGUES(num);
    double nextIteration{initialGues};
    while (true) {
        initialGues = nextIteration;
        nextIteration = initialGues - ((pow(initialGues,3) - num) / (pow(initialGues, 2) * num));
        if(fabs(nextIteration - initialGues) <= delta) {
            break;
        }
    }
    return initialGues;
}

double initialGUES(double num) {
    int intPart = num;
    std::vector<int> cubeTurnPoints {8,27,64,125,216,343, 512, 729, 1000};
    std::vector<double> cubes {2,3,4,5,6,7,8,9,10};

    for (int i{0}; i < cubeTurnPoints.size(); ++i) {
        if (num >= cubeTurnPoints[i] && num <= cubeTurnPoints[i + 1]) {
            return cubes[i];
        }
    }
    return 10;
}
