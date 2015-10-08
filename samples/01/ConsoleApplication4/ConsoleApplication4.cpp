// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <cstdint>
#include <string>
#include <memory>

using namespace std;

enum WeekDay
{
	Sunday, Monday, Tuesday, Wednesday,
	Thursday, Friday, Saturday,
};

enum Colors
{
	Red = 0xff000,
	Green = 0x00ff00,
	Blue = 0x0000ff,
	ButtonColor = Green,
	DefaultColor = ButtonColor,
};

enum class RobotState : uint32_t
{
	TurnedOff,
	WaitingForCommand,
	Walking,
	Fighting,
};
enum class DogState
{
	Dead,
	WaitingForCommand,
	Walking,
	Barking,
};

namespace xyz
{
namespace abc
{
namespace bbbb
{
struct StuctWithVeryLongName
{
	int x;
};
}
}
}


void Pointers()
{
	int thisIs5 = 5;
	char thisIsA = 'A';

	int * pointerTo5 = &thisIs5;
	char * pointerToA = &thisIsA;

	int * someIntInTheMemory = reinterpret_cast<int *>(0x123456);

	int ** pointerToPointerTo5 = &pointerTo5;


	(*(*pointerToPointerTo5)) = 6;
	cout << thisIs5 << endl;
}

int g_SomeGlobalVar = 33;

void StaticMemory()
{
	g_SomeGlobalVar = 66;

	static int someStaticVariable = 24;

	++someStaticVariable;
}

int Fib(unsigned n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	unsigned fibPrev = Fib(n - 1);
	unsigned fibPrevPrev = Fib(n - 2);
	return fibPrev + fibPrevPrev;
}

void DynamicMemory()
{
	int n = 100;
	// Выделить массив из n элементов в куче (про инициализированы нулями)
	{
		int * p = new int[n];
		delete[] p;
		p = nullptr;
	}
	// Настоящие пацаны пишут так:
	{
		auto p = make_unique<int[]>(n);
		// нельзя создать копию уникального указателя
		// auto p2 = p;
		
		auto p2 = move(p);
		// p теперь указывает на nullptr
		// p2 указывает на массив

		p[10] = 17;
	}

	// Выделить одно значение в куче и инициализировать числом 42
	{
		int * someInt = new int(42);
		delete someInt;
	}
	// Реальные пацаны пишут так:
	{
		auto someInt = make_unique<int>(42);
	}
	// Совместное владение
	{
		auto someInt = make_shared<int>(42);
		shared_ptr<int> oneMoreOwner = someInt;
		// оба указателя хранят адрес одного и того int-а (42)

		// weakOwner автоматически обнулится, как только все shared-ссылки на 
		// объект будут уничтожены
		weak_ptr<int> weakOwner = someInt;
		shared_ptr<int> strongOwner = weakOwner.lock();
	}
}

int main()
{
	cout << Fib(7) << endl;

	typedef xyz::abc::bbbb::StuctWithVeryLongName MyStruct;

	typedef std::wstring wstr;
	typedef std::string str;

	wstr hello = L"Hello";

	MyStruct someStruct;

	WeekDay today = Monday;
	cout << today << endl;
	int color = Red;

	RobotState state = RobotState::Walking;
	DogState dogState = DogState::Walking;
	
	cout << static_cast<int>(dogState) << endl;

	auto xx = 17 + 3.8; // 17.0 + 3.8

	Pointers();

	return 0;
}

