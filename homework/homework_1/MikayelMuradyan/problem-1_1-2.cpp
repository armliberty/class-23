#include <cmath>
#include <iostream>

double sine(double x, double delta);

int main() {
  double n, delta = 0.0001;
  std::cout << "n: "; std::cin >> n;
  std::cout << "root is: " << sine(n,delta) << std::endl;
  return 0;
}

double sine(double x,double delta) {
  x = (x * M_PI)/180;

 do {
    x = x - (std::sin(x) - x)/(std::cos(x) - 1);
    
    if (std::abs(std::sin(x) - x) < delta)
      break;
  }while(1);
  return x;
}