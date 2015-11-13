#include <iostream>
#include <stdexcept>
#include <typeinfo>

void YouShouldAlwaysCatchExceptionsByReference()
{
	std::cout << "Catching a runtime_exception by value:\n";
	try
	{
		throw std::runtime_error("Runtime error");
	}
	catch (std::exception e)	// The information about runtime_error has been sliced
	{
		std::cout << e.what() << ", type name: " << typeid(e).name() << "\n\n";
	}

	std::cout << "Catching a runtime_exception by reference:\n";
	try
	{
		throw std::runtime_error("Runtime error");
	}
	catch (std::exception const& e)	// No slicing (we are dealing with the reference to the exception object)
	{
		std::cout << e.what() << ", type name: " << typeid(e).name() << std::endl;
	}
}

void main()
{
	YouShouldAlwaysCatchExceptionsByReference();
}