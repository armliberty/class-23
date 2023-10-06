#include <iostream>
#include <vector>

bool isPrime(int num) {
    if (num <= 1)
        return false;
    for (int divider = 2; divider <= num; divider++) {
        if (num % divider == 0)
            return false;
    }
    return true;
}

std::vector<int> primeFactorize(int n) {
  std::vector<int> factors;
  for (int i=2; i<=n; i++) {
    if (isPrime(i)) {
      while (n%i==0) {
        factors.push_back(i);
        n /= i;
      }
    }
  }
  return factors;
}

 void findGCDandLCM(int a, int b) {
     std::vector<int> primeFactorsA = primeFactorize(a);
     std::vector<int> primeFactorsB = primeFactorize(b);

     int gcd = 1;
     int i = 0, j = 0;

     while (i < primeFactorsA.size() && j < primeFactorsB.size()) {
         if (primeFactorsA[i] == primeFactorsB[j]) {
             gcd *= primeFactorsA[i];
           i++;
             j++;
        } else if (primeFactorsA[i] < primeFactorsB[j]) {
             i++;
        } else {
             j++;
        }
     }

     int lcm = (a * b) / gcd;

    std::cout << "GCD: " << gcd <<std::endl;
    std::cout << "LCM: " << lcm << std::endl;
 }