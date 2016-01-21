#include <iostream>
#include <cmath>
#include <string>
#include <stdexcept>

double MySqrt(double arg)
{
	if (arg < 0)
	{
		throw std::invalid_argument("the argument must be >= 0");
	}

	return sqrt(arg);
}

int main()
{
	try
	{
		std::cout << "sqrt(3) = " << MySqrt(3) << "\n";
		std::cout << "sqrt(-1) = " << MySqrt(-1) << "\n";
	}
	catch (std::invalid_argument const & e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}

	return 0;
}
