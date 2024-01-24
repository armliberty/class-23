#include <iostream>
#include"prime_checker.h"
/*
int main() {

  int n;

  std:: cout << "Enter a positive integer: ";
  std::cin >> n;

  if (n < 0) {
    std::cout << "Please enter a positive integer." << std::endl;
    return 1; 
  }

  if (check_prime(n))
    std::cout << n << " is a prime number.";
  else
    std::cout << n << " is not a prime number.";

  return 0;
}
*/
bool check_prime(int n) {
  bool is_prime = true;

  if (n == 0 || n == 1) {
    is_prime = false;
  }

  for (int i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      is_prime = false;
      break;
    }
  }

  return is_prime;
}
