#include <iostream>
#include <vector>

bool isPrime(int);
std::vector<int> primeFactorize(int);
int computeGCD(int, int);
void Input(int &, int &);

int main()
{
	int a, b;
	std::cout << "compute GCD" << std::endl;
	Input(a, b);
	std::cout << "GCD(" << a << "," << b << "): " << computeGCD(a, b) << std::endl;
}

void Input(int &a, int &b)
{
	std::cout << "Input a:";
	std::cin >> a;
	std::cout << "Input b:";
	std::cin >> b;
}

bool isPrime(int i)
{

	for (int j = 2; j * j <= i; ++j)
	{

		if (i % j == 0)
		{
			return false;
		}
	}
	return true;
}

std::vector<int> primeFactorize(int n)
{
	std::vector<int> factorize;
	int quantity = n, remainder, i = 2;

	if (isPrime(n))
	{
		factorize.push_back(n);
		return factorize;
	}
	else
	{
		while (i <= quantity)
		{
			remainder = quantity % i;
			if (isPrime(i) && remainder == 0)
			{
				factorize.push_back(i);
				quantity = quantity / i;
				i = 2;
			}
			else if (isPrime(i) && remainder != 0)
			{
				++i;
			}
			else
			{
				++i;
			}
		}
		return factorize;
	}
}

int computeGCD(int a, int b)
{
	if (a == 0 || b == 0)
	{
		return (a + b);
	}
	if (a == b)
	{
		return a;
	}
	int i = 0, j = 0, gcd = 1;
	while (i < primeFactorize(a).size() && j < primeFactorize(b).size())
	{
		if (primeFactorize(a)[i] > primeFactorize(b)[j])
		{
			++j;
		}
		else if (primeFactorize(a)[i] < primeFactorize(b)[j])
		{
			++i;
		}
		else
		{
			gcd *= primeFactorize(a)[i];
			++i;
			++j;
		}
	}
	return gcd;
}
