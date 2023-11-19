#include "includes.hpp"

double sinexminusx(double x, double delta)
{
	auto val = x;
	double y;
	double yprime;

	while (1)
	{
		y = std::sin(val) - val;
		yprime = std::cos(val) - 1;
		if (std::abs(y) < delta || yprime == 0)
			return (val);
		val = val - y / yprime;
	}
	return (0);
}

int main()
{
	double x;
	double delta;

	delta = 0.1;
	x = 2;
	while (x > 1 || x < -1)
	{
		std::cout << "Enter x from [-1,1] to approximate the sine for: ";
		std::cin >> x;
	}
	while (delta >= 0.1)
	{
		std::cout << "Enter small delta for precision: ";
		std::cin >> delta;
	}
	printf("result is %f\n", sinexminusx(x, delta));
}