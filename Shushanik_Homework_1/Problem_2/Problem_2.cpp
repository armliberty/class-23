#include<iostream>

bool isPrime(int);
void printPrime(int);

int main() {
	    int i;
	        std::cout << "Input integer" << std::endl;
		    std::cin >> i;
		        printPrime(i);
			  }

bool isPrime(int i) {
	        for (int j = 2; j * j <= i; ++j) {

			        if (i % j == 0) {
					            return false;
						            }
				    }
		    return true;
}

void printPrime(int i) {
	if (isPrime(i)) {
		        std::cout << i << " is prime" << std::endl;
			    }
	    else {
		    std::cout << i << " is not prime" << std::endl;
}
}
