#include "includes.hpp"

double sine(double x, double delta)
{
	double prevxn;

	while(1)
	{
		prevxn = x;
		x = x - tan(x);
		if (std::abs(x - prevxn) < delta)
			return (x);
	}
	return (x);
}

int main()
{
	double	x;
	double	delta;

	delta = 0.1;
	std::cout << "Enter x to approximate the sine for: ";
	std::cin >> x;
	while (delta >= 0.1)
	{
		std::cout << "Enter small delta for precision: ";
		std::cin >> delta;
	}
	printf("result is %f\n", sin(x));
	printf("result is %f\n", sine(x, delta));
}
