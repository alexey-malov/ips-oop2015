#include "stdafx.h"
#include "VectorProcessor.h"
#include <algorithm>
#include <numeric>

using namespace std;

void ProcessVector(std::vector<double> & numbers)
{
	auto IsPositive = [](double number){return number > 0; };

	size_t numberOfPositives = 0;

	// функция, суммирующая только положительные числа с подсчетом их количества
	auto addIfPositive = [&numberOfPositives](double acc, double current) {
		if (current > 0.0)
		{
			++numberOfPositives;
			return acc + current;
		}
		return acc;
	};

	auto sumOfPositives = accumulate(numbers.begin(), numbers.end(), 0.0, addIfPositive);

	double avg = (numberOfPositives > 0) ? sumOfPositives / numberOfPositives : 0.0;

	// TODO: Используй силу алгоритма std::transform, Люк, вместо этого цикла
	for (auto &number : numbers)
	{
		number += avg;
	}
}