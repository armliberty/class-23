#include <cmath>
#include <iostream>

double cubeRoot(double x, double delta);

int main() {
	double x, delta;
	std::cin >> x >> delta;
	std::cout << "cubeRoot: " << cubeRoot(x, delta) << std::endl;
	std::cout << "std::pow: " << std::pow(x, 1/3) << std::endl;
}

double cubeRoot(double x, double delta) {
	return 3.2;
}

