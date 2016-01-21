#include <iostream>
#include <string>

using namespace std;

struct CLogger
{
	CLogger(const string& name)
		:name(name)
	{
		cout << "Object '" << name << "' was created at " << this << " \n";
	}
	~CLogger()
	{
		cout << "Object '" << name << "' was destroyed at " << this << "\n";
	}
	string name;
};

struct X
{
	X(bool mustThrow = true) 
		:y("X.y"), mustThrow(mustThrow)
	{

	}

	~X()
	{
		if (mustThrow)
		{
			throw 0;
		}
	}

	bool mustThrow;

	CLogger y;
};


void main()
{
	try
	{
		X x;
	}
	catch (...)
	{
		cout << "catched" << "\n";
	}

	cout << "-----\n";

	try
	{
		X x;
		// ¬ыброс исключени€ в теле деструкта x во врем€ раскрутки стека 
		// недопустимо и приведет к аварийному завершению программы
		throw 0;
	}
	catch (...)
	{
		cout << "catched" << "\n";
	}
}