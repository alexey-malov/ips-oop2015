#include <iostream>
#include <string>

using namespace std;
/*
Объект, сообщающий о вызове своих конструкторов и деструкторов
*/
struct Object
{
	Object()
	{
		cout << this << " Default constructed" << endl;
	}

	Object(const string & name)
		: m_name(name)
	{
		cout << this << " Constructed with name " << m_name << endl;
	}

	Object(const Object & o)
		: m_name(o.m_name)
	{
		cout << this << " Copy constructed " << m_name << endl;
		++m_copyCounter;
	}

	Object(Object && o)
		: m_name(move(o.m_name))
	{
		cout << this << " Move constructed " << m_name << endl;
		++m_moveCounter;
	}

	Object& operator=(const Object& rhs)
	{
		if (this != &rhs)
		{
			m_name = rhs.m_name;
		}
		cout << this << " Copy assigned " << m_name << endl;
		return *this;
	}

	Object& operator=(Object && rhs)
	{
		if (this != &rhs)
		{
			m_name = move(rhs.m_name);
		}
		cout << this << " Move assigned " << m_name << endl;
		return *this;
	}

	~Object()
	{
		cout << this << " Destroyed " <<  m_name << endl;
	}

	static size_t GetCopyCounter()
	{
		return m_copyCounter;
	}

	static size_t GetMoveCounter()
	{
		return m_moveCounter;
	}

	static void ClearOperationsCount()
	{
		m_copyCounter = 0;
		m_moveCounter = 0;
	}
private:
	string m_name;
	static size_t m_copyCounter;
	static size_t m_moveCounter;
};

size_t Object::m_copyCounter = 0;
size_t Object::m_moveCounter = 0;

struct Client
{
	Client(const Object & obj1, const Object & obj2)
		: m_obj1(obj1)
		, m_obj2(obj2)
	{
	}

	Client(Object && obj1, Object && obj2)
		: m_obj1(move(obj1))
		, m_obj2(move(obj2))
	{
	}

	Client(const Object & obj1, Object && obj2)
		: m_obj1(obj1)
		, m_obj2(move(obj2))
	{
	}

	Client(Object && obj1, const Object & obj2)
		: m_obj1(move(obj1))
		, m_obj2(obj2)
	{
	}
private:
	Object m_obj1;
	Object m_obj2;
};

struct SmartClient
{
	template <typename Arg1, typename Arg2>
	SmartClient(Arg1 && obj1, Arg2 && obj2)
		: m_obj1(forward<Arg1>(obj1))
		, m_obj2(forward<Arg2>(obj2))
	{
	}
private:
	Object m_obj1;
	Object m_obj2;
};

template <typename Action>
void PrintOperationsCount(const string& description, const Action & action)
{
	cout << description << endl;
	Object::ClearOperationsCount();
	action();
	cout << "Number of copy operations: " << Object::GetCopyCounter() << endl;
	cout << "Number of move operations: " << Object::GetMoveCounter() << endl;
	cout << "------------------" << endl;
}

void main()
{
	cout << "Using client with 4 constructors" << endl;
	PrintOperationsCount("Named objects are copied", []{
		Object o1("Obj1");
		Object o2("Obj2");
		Client c(o1, o2);
	});

	PrintOperationsCount("Temporary objects are moved", []{
		Client c(Object("Obj1"), Object("Obj2"));
	});

	PrintOperationsCount("First arg is named, Second arg is temporary", []{
		Object o1("Obj1");
		Client c(o1, Object("Obj2"));
	});

	PrintOperationsCount("First arg is temporary, Second arg is named", []{
		Object o2("Obj2");
		Client c(Object("Obj1"), o2);
	});

	cout << "Using SmartClient with 1 template constructor" << endl;

	PrintOperationsCount("Named objects are copied", []{
		Object o1("Obj1");
		Object o2("Obj2");
		SmartClient c(o1, o2);
	});

	PrintOperationsCount("Temporary objects are moved", []{
		SmartClient c(Object("Obj1"), Object("Obj2"));
	});

	PrintOperationsCount("First arg is named, Second arg is temporary", []{
		Object o1("Obj1");
		SmartClient c(o1, Object("Obj2"));
	});

	PrintOperationsCount("First arg is temporary, Second arg is named", []{
		Object o2("Obj2");
		SmartClient c(Object("Obj1"), o2);
	});
}
