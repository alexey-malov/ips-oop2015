#include <iostream>
#include <string>

class CBase
{
public:
	CBase(std::string const& message)
		:m_message(message)
	{
		// Выводим адрес конструируемого объекта базового класса
		std::cout << "CBase " << this << "\n";
	}

	~CBase()
	{
		// Выводим адрес разрушаемого объекта базового класса
		std::cout << "~CBase " << this << "\n";
	}

	CBase(const CBase & b)
		:m_message(b.m_message)
	{
		// Выводим адрес конструируемого объекта базового класса
		std::cout << "CBase copy constructor " << this << "\n";
	}

	std::string GetMessage()const
	{
		return m_message;
	}

	virtual void PrintInfo()const
	{
		std::cout << "CBase exception: "
			<< m_message << "\n";
	}
private:
	std::string m_message;
};

class CDerived : public CBase
{
public:
	CDerived(std::string const& message)
		:CBase(message)
	{
	}

	CDerived(const CDerived& d)
		:CBase(d)
	{
		std::cout << "CDerived copy constructor\n";
	}

	virtual void PrintInfo()const override
	{
		std::cout << "CDerived exception: "
			<< GetMessage() << "\n";
	}
};

void main()
{
	std::cout << "Throwing with slicing\n";
	try
	{
		try
		{
			throw CDerived("Hi");
		}
		catch (const CBase & b)
		{
			std::cout << "Inner catch: &b=" << &b << "\n";
			b.PrintInfo();
			std::cout << "throw b;\n";
			// Выбрасывается копия b (с неявной срезкой)
			// Срезанная копия передается внешнему обработчику
			throw b;
		}
	}
	catch (const CBase & b)
	{
		// Поймана обрезанная копия оригинального исключения
		std::cout << "Outer catch: &b=" << &b << "\n";
		b.PrintInfo();
	}

	std::cout << "================\n";
	std::cout << "Rethrowing\n";
	try
	{
		try
		{
			throw CDerived("Hi");
		}
		catch (const CBase & b)
		{
			std::cout << "Inner catch: &b=" << &b << "\n";
			b.PrintInfo();
			std::cout << "throw;\n";
			// Выбрасывается пойманный объект исключения (CDerived)
			// (пойманный объект передается внешнему обработчику)
			throw; 		
		}
	}
	catch (const CBase & b)
	{
		// Пойман оригинальный объект исключения
		std::cout << "Outer catch: &b=" << &b << "\n";
		b.PrintInfo();
	}
}