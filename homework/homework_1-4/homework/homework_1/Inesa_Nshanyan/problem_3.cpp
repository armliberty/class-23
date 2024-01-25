#include <iostream>
#include <cmath>
#include <vector>

void PrimeFactorize(int, std::vector<int>&);
void print(std::vector<int>&);

int main() {
	int num;
	std::vector<int> primeFactorize;
	std::cout << "Enter a number ";
	std::cin >> num;
	PrimeFactorize(num, primeFactorize);
	print(primeFactorize);
}

void PrimeFactorize(int num, std::vector<int>& primeFactorize) {
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
