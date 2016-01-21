#include <iostream>
#include <string>

class CBase
{
public:
	CBase(std::string const& message)
		:m_message(message)
	{}

	CBase(const CBase & b)
		:m_message(b.m_message)
	{
		std::cout << "CBase copy constructor\n";
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

void DoSomethingWithCBasePassedByValue(CBase b)
{
	b.PrintInfo();
}

void DoSomethingWithCBasePassedByReference(const CBase & b)
{
	b.PrintInfo();
}

void main()
{
	{
		std::cout << "Slicing\n";
		CDerived d("hi");
		// Код аналогичен DoSomethingWithCBasePassedByValue(static_cast<CBase&>(d));
		DoSomethingWithCBasePassedByValue(d);
	}

	std::cout << "-----\n";
	std::cout << "Slicing\n";
	try
	{
		CDerived d("Hello");
		std::cout << "Throwing derived\n";
		throw d;
	}
	catch (CBase b) 
	{
		// При перехвате исключения по значению происходит "срезка", 
		// приводящяя к потере части информации, специфичной для наследника
		b.PrintInfo();
	}

	std::cout << "-----\n";
	std::cout << "Slicing\n";
	try
	{
		CDerived d("Hello");
		std::cout << "Throwing derived\n";
		throw d;
	}
	catch (const CBase & b)
	{
		// При перехвате исключения по ссылке срезка не происходит, 
		// т.к. нет нужды создавать копию типа CBase.
		b.PrintInfo();
	}
}