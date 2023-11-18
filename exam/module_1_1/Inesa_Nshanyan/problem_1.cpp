//Inesa_Nshanyan_119_U
#include <iostream>
using TimeSig = std::pair<int, int>;

int computeOverlap(TimeSig, TimeSig);
int computeGCD(int a, int b);
int computeLCM(int a, int b);

int main() {
	int a1, b1;
	int a2, b2;
	std::cout << "Enter a1 and b1 : ";
	std::cin >> a1 >> b1;
	std::cout << "Enter a2 and b2 : ";
	std::cin >> a2 >> b2;
	TimeSig first(a1, b1);
	TimeSig second(a2, b2);
	std::cout << "Overlap at " << computeOverlap(first, second) << std::endl;
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
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int computeLCM(int a, int b) {
	return (a * b) / computeGCD(a, b);
}

int computeOverlap(TimeSig first, TimeSig second) {
	int a1, b1, a2, b2;
	b1 = computeLCM(first.second, second.second);
	b2 = b1;
	a1 = b1 / first.second * first.first;
	a2 = b2 / second.second * second.first;
	int Overlap = computeLCM(a1, a2);
	Overlap /= first.first;
	return Overlap;
}