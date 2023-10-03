#include <cmath>
#include <iostream>

double sine(double x, double delta);

int main() {
  double x, delta = 0.001;
  std::cout << "x: "; std::cin >> x;
  std::cout << "root of sine(x) is: " << sine(x,delta) << std::endl;
  return 0;
}

double sine(double x,double delta) {
  x = (x * M_PI)/180;

 do {
    x = x - (std::sin(x) - x*x)/(std::cos(x) - 2*x);
    
    if (std::abs(std::sin(x) - x) < delta)
      break;
  }while(1);
  return x;
}