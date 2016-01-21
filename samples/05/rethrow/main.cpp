#include <iostream>
#include <string>

class CBase
{
public:
	CBase(std::string const& message)
		:m_message(message)
	{
		// ������� ����� ��������������� ������� �������� ������
		std::cout << "CBase " << this << "\n";
	}

	~CBase()
	{
		// ������� ����� ������������ ������� �������� ������
		std::cout << "~CBase " << this << "\n";
	}

	CBase(const CBase & b)
		:m_message(b.m_message)
	{
		// ������� ����� ��������������� ������� �������� ������
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
			// ������������� ����� b (� ������� �������)
			// ��������� ����� ���������� �������� �����������
			throw b;
		}
	}
	catch (const CBase & b)
	{
		// ������� ���������� ����� ������������� ����������
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
			// ������������� ��������� ������ ���������� (CDerived)
			// (��������� ������ ���������� �������� �����������)
			throw; 		
		}
	}
	catch (const CBase & b)
	{
		// ������ ������������ ������ ����������
		std::cout << "Outer catch: &b=" << &b << "\n";
		b.PrintInfo();
	}
}