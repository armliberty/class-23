#include <cmath>
#include <iostream>
#include <vector>

std::vector<int> primeFactorize(int);

int main() {
  int number;
  std::cout << "Enter a number: ";
  std::cin >> number;
  std::vector<int> vector;

  vector = primeFactorize(number);
  for(int i = 0;i < vector.size(); i++) {
    std::cout << vector[i] << std::endl;
  }
  return 0;
}

std::vector<int> primeFactorize(int n) {
    std::vector<int> vec;

    while(n % 2==0) {
        n = n / 2;
        vec.push_back(2);   
    }

    for(int i = 3; i<=std::sqrt(n); i+=2) {
        while(n % i == 0) {
            vec.push_back(i);
            n = n / i;
        } 
    } 

    if(n >= 2) {
        vec.push_back(n);
    }

    return vec;
}
