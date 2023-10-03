#include <iostream>
#include <cmath>


double cubeRoot(double x, double delta) {
    double theFunct;
    double derivativeOfFunct;
    
    do {
        theFunct = pow(x,3);
        derivativeOfFunct = 3*pow(x,2); 
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

    std::cout << " x  = " << cubeRoot(x, delta) << std::endl;

    return 0;
}
