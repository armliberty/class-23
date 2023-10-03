#include <iostream>
using namespace std;
bool isPrime(int n) {
    if (n <= 1) {
        return false; 
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false; // Divisible by 2 or 3
    }
    for (int i = 5; i * i <= n; i++ ) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int num;
    cin >> num;
    if (isPrime(num)) {
        cout << num << "is prime." << endl;
    } else {
        cout << num << "is not prime." << endl;
    }
    return 0;
}