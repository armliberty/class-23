#include <iostream>
#include <math.h>

double sine(double, double);

int main()
{
	double x, delta;
	std::cout << "Input delta: ";
	std::cin >> delta;
	std::cout << "Input x0: ";
	std::cin >> x;
	std::cout << sine(x, delta) << " is output  ";
}

double sine(double x, double delta)
{
	double xn;
	xn = x - (sin(x) - x) / (cos(x) - 1);
	while (fabs(xn - x) > delta)
	{
		x = xn;
		xn = x - (sin(x) - x) / (cos(x) - 1);
	}
	return xn;
}
