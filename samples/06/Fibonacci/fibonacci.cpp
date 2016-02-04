#include <iostream>

template <unsigned N>
struct Factorial
{
	// N! = N * (N - 1)!
	enum
	{
		VALUE = N * (Factorial<N - 1>::VALUE)
	};
};

// Терминальное условие (0! = 1)
template <>
struct Factorial<0>
{
	// 0! = 1
	enum
	{
		VALUE = 1
	};
};

template <unsigned N>
struct Fibonacci
{
	// fibonacci(n) = fibonacci(n - 1) + fibonacci(n - 2)
	enum
	{
		VALUE = Fibonacci<N - 1>::VALUE + Fibonacci<N - 2>::VALUE
	};
};

// Терминальное условие (0! = 1)
template <>
struct Fibonacci<0>
{
	// fibonacci(0) = 0
	enum
	{
		VALUE = 0
	};
};

template <>
struct Fibonacci<1>
{
	// fibonacci(1) = 1
	enum
	{
		VALUE = 1
	};
};


void main()
{
	std::cout << Fibonacci<0>::VALUE << std::endl;
	std::cout << Fibonacci<1>::VALUE << std::endl;
	std::cout << Fibonacci<2>::VALUE << std::endl;
	std::cout << Fibonacci<3>::VALUE << std::endl;
	std::cout << Fibonacci<4>::VALUE << std::endl;
	std::cout << Fibonacci<5>::VALUE << std::endl;
	std::cout << Fibonacci<6>::VALUE << std::endl;
	//std::cout << Fibonacci<42000>::VALUE << std::endl; compilation error
}
