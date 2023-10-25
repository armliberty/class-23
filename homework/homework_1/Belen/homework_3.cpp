#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int divider; divider  < n; divider++) {
        if (n % divider == 0) {
            return false;
        }
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

int main() {
  int n;
  cout << "Enter a number: ";
  cin >> n;
  vector<int> factors = primeFactorize(n);
  cout << "Prime factors of " << n << ": ";
  for (int i=0; i<factors.size(); i++) {
    cout << factors[i] << " ";
  }
  cout << endl;
  return 0;
}