#include <cmath>
#include <iostream>
#include <vector>

std::vector<int> Prime_Factorize(int);

int main() {
  int number;
  std::cout << "the number is: ";
  std::cin >> number;
  std::vector<int> vector;

  vector = Prime_Factorize(number);
  for(int i = 0; i < vector.size(); i++) {
    std::cout << vector[i] << std::endl;
  }
  return 0;
}


std::vector<int> Prime_Factorize(int n) {
    std::vector<int> vect;

    while(n % 2 == 0) {
        n = n / 2;
        vect.push_back(2);   
    }

    for(int i = 3; i <= std::sqrt(n); i += 2) {
        while(n % i == 0) {
            vect.push_back(i);
            n = n / i;
        } 
    } 

    if(n >= 2) {
        vect.push_back(n);
    }

    return vect;
}