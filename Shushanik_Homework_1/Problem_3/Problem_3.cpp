#include<iostream>
#include<vector>

bool isPrime(int);
std::vector<int> primeFactorize(int);

int main() {
	    int a, b,n;
	        std::vector<int> factorize;
		std::cout << "Input integer: "; std::cin >> n;
			    factorize = primeFactorize(n);
			        for (int j = 0; j < factorize.size(); ++j)
					        std::cout << factorize[j] << std::endl;
}

bool isPrime(int i) {
	    for (int j = 2; j * j <= i; ++j) {
		            if (i % j == 0) {
				                return false;
						        }
			        }
	        return true;
}

std::vector<int> primeFactorize(int n) {
	    std::vector<int> factorize;
	        int quantity = n, remainder, i = 2;

		    if (isPrime(n)) {
			            factorize.push_back(n);
				            return factorize;
					        }
		        else {
				        while (i <= quantity) {
						            remainder = quantity % i;
							                if (isPrime(i) && remainder == 0) {
										                factorize.push_back(i);
												                quantity = quantity / i;
														                i = 2;
																            }
									            else if (isPrime(i) && remainder != 0) {
											                    ++i;
													                }
										                else {
													                ++i;
															            }
												        }
					        return factorize;
						    }
}
