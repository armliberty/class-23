#include <iostream>
#include <cmath>
#include <vector>

int computeGCD(int, int);
int computeLCM(int, int);
void PrimeFactorize(int, std::vector<int>&);
void print(std::vector<int>&);

std::vector<int> primeFactorizeA;
std::vector<int> primeFactorizeB;

int complexity = 0;

int main() {
	int a, b;
	std::cout << "Enter two numbers (>=1) ";
	std::cin >> a >> b;
	std::cout << "GCD = " << computeGCD(a, b) << "\n";
	std::cout << "LCM = " << computeLCM(a, b) << "\n";
	std::cout << "complexity = " << complexity << std::endl;
}

int computeGCD(int a, int b) {
	PrimeFactorize(a, primeFactorizeA);
	PrimeFactorize(b, primeFactorizeB);
	int GCD = 1;
	for (auto i = 0; i < primeFactorizeA.size(); ++i) {
		for (auto j = 0; j < primeFactorizeB.size(); ++j) {
			if (primeFactorizeA[i] == primeFactorizeB[j]) {
				GCD *= primeFactorizeA[i];
				primeFactorizeB[j] = 1; 
				complexity++;
				break;
			}
		}
	}
	return GCD;
}

int computeLCM(int a, int b) {
	return (a*b)/computeGCD(a, b);
}

void PrimeFactorize(int num, std::vector<int>& primeFactorize) {
	primeFactorize.clear();
	if (num <= 1) {
		primeFactorize.push_back(num);
	}
	int temp = num;
	while (temp % 2 == 0) {
		primeFactorize.push_back(2);
		temp /= 2;
	}
	temp = num;
	for (auto i = 3; i <= temp; i += 2) {
		while (temp % i == 0) {
			primeFactorize.push_back(i);
			temp /= i;
		}
	}
}

void print(std::vector<int>& primeFactorize)
{
	for (auto i = 0; i < primeFactorize.size(); ++i) {
		std::cout << primeFactorize[i] << " ";
	}
}
