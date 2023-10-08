#include <iostream>
#include <cmath>

bool isPrime(int);

int main() {
	int num;
	std::cout << "Enter a number ";
	std::cin >> num;
	std::cout << isPrime(num) << std::endl;
}

bool isPrime(int num){
	if (num <= 1) {
		return false;
	}
	for (auto i = 2; i < sqrt(num); ++i) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
} 

