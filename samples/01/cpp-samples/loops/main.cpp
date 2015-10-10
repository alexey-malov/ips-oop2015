#include <iostream>
#include <algorithm>
#include <string>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void main()
{
	// Простейший цикл for
	{
		// Выводит 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
		// Область видимости переменной i ограничена телом цикла
		for (int i = 0; i < 10; ++i)
		{
			cout << i << ", ";
		}
		cout << endl;
	}

	// Используем вложенный цикл for для поиска простых чисел
	{
		cout << "Primes: ";
		for (int i = 2; i < 100; ++i)
		{
			bool isPrime = true;

			// Наивный метод определения простоты числа i
			//	проверяем i на делимость на любое из чисел диапазона [2; sqrt(i)]
			for (int j = 2; j * j <= i; ++j)
			{
				// Если найден множитель числа i, выходим из цикла при помощи break
				if (i % j == 0)
				{
					isPrime = false;
					break;
				}
			}
			if (isPrime)
			{
				cout << i << ", ";
			}
		}
		cout << endl;
	}

	// Цикл while
	{
		unsigned a = 714;
		unsigned b = 312;
		cout << "Greatest Common Denominator of " << a << " and " << b << " is ";
		while (b != 0)
		{
			std::swap(a, b);
			b = b % a;
		}
		cout << std::max(a, 1u) << endl;
	}

	// Цикл do-while
	{
		std::string userInput;
		do 
		{
			cout << R"(Enter text or "bye" to finish: )";
			getline(cin, userInput);
			cout << "You entered: " << userInput << endl;
		} while (userInput != "bye");
	}

	// Бесконечный цикл for
	{
		std::mt19937 generator;
		std::uniform_int_distribution<int> dist(0, 10);

		// Также можно использовать цикл while:
		//	while (true)
		//	{
		//		тело цикла 
		//	}
		// либо цикл do-while: 
		//	do 
		//	{
		//		тело цикла
		//	} while(true);
		for (;;)
		{
			cout << "Next random number: " << dist(generator) << endl;
			cout << "Type q or Q to quit the game: ";
			string userInput;
			getline(cin, userInput);
			if (userInput == "q" || userInput == "Q")
			{
				break;
			}
		}
	}
}
