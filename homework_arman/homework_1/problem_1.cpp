#include <iostream>
#include <cmath>
using namespace std;
double cubeRoot(double x, double delta) {
    if (x == 0.0) {
        return 0.0;
    }
    double result = x;
    while (abs(result * result * result - x) > delta) {
        result = (2 * result + x / (result * result)) / 3;
    }
    return result;
}
int main() {
    double cube;
    cin >> cube;
    cout << cubeRoot(cube, 0.0001);
}