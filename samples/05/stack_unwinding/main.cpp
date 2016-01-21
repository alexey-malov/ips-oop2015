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

void FnInner()
{
	cout << "Entered FnInner()\n";

	CLogger y("y within FnInner");

	cout << "FnInner will throw 42;\n";
	throw 42;
}

void FnOuter()
{
	cout << "Entered FnOuter()\n";

	CLogger x("x within FnOuter");

	cout << "Calling FnInner()\n";
	FnInner();
}


void main()
{
	try
	{
		CLogger first("first");
		CLogger second("second");
		cout << "throw 0;\n";
		throw 0;
	}
	catch (...)
	{
		cout << "Catched\n";
	}
	cout << "======\n";

	{
		CLogger hello("hello");

		try
		{
			CLogger abc("abc");
			cout << "Calling FnOuter();\n";
			FnOuter();
		}
		catch (...)
		{
			cout << "Catched\n";
		}
		cout << "Object hello will be destroyed\n";
	}
}
