#include <iostream>
#include <cmath>
#include <vector>

int computeGCD(int, int);
int computeLCM(int, int);

int complexity = 0;

int main() {
	int a, b;
	std::cout << "Enter two numbers (>= 1)";
	std::cin >> a >> b;
	std::cout << "GCD = " << computeGCD(a, b) << "\n";
	std::cout << "LCM = " << computeLCM(a, b) << "\n";
	std::cout << "complexity = " << complexity << std::endl;
}

int computeGCD(int a, int b)
{
	if (b > a) {
		int temp = a;
		a = b;
		b = temp;
	}
	while (b != 0)
	{
		complexity++;
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}


int computeLCM(int a, int b) {
	return (a * b) / computeGCD(a, b);
}

