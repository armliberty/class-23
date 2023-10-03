#include<iostream>
#include<math.h>

double cubeRoot(double, double);


int main() {
	    double x, delta;
	        std::cout << "Input delta: "; std::cin >> delta;
		    std::cout << "Input x0: "; std::cin >> x;
		        std::cout << cubeRoot(x, delta) << " is output  ";

}

double cubeRoot(double x, double delta) {
	    double xn,guess_root;
	        std::cout << "Input guess_root: "; std::cin >> guess_root;
		    xn = (2 * pow(guess_root, 3) + x) / (3 * pow(guess_root, 2));
		        while (fabs(xn - guess_root) > delta)
				    {
					            guess_root = xn;
						            xn = (2 * pow(guess_root, 3) + x) / (3 * pow(guess_root, 2));
							        }
			    return xn;

}
