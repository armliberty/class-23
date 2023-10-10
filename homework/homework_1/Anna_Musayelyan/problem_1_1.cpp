#include<iostream>
#include<cmath>

double function(double x) {
	return x * x * x;
}

double derivate(double x) {
	return 3 * x * x;
}

double cubeRoot(double x, double delta) {
	double df;
	double initialguess = x / 2;
	while(fabs(function(initialguess) - x ) > delta) {
		df = derivate(initialguess);
		initialguess = initialguess - (function(initialguess) -fabs(x)) / df;
	}
	return initialguess;
}

int main() {
    double x; 
    double delta = 1e-6;  

    std::cout << "Enter a number to find its cube root: ";
    std::cin >> x;
    double result = cubeRoot(x, delta);
    std::cout << "Approximate Cube Root: " << result << std::endl;

    return 0;
}
