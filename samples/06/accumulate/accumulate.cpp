#include <iostream>
#include <vector>
#include <string>
#include <complex>
#include <functional>

using namespace std;

template <typename T, typename Op = plus<T>>
T AccumulateVector(const vector<T> & items, Op op = Op(), T acc = T())
{
	for (auto & item : items)
	{
		acc = op(acc, item);
	}
	return acc;
}

void main()
{
	vector<int> v = { 10, 20, 5 };
	auto r = AccumulateVector(v);// r = 35
	cout << r << endl;

	vector<string> vs = { "A", "B", "C" };
	auto rs = AccumulateVector(vs);// rs = "ABC“
	cout << rs << endl;

	vector<complex<double>> cs = {{3.8, 0.2}, {-1.5, 3.1}};
	auto rc = AccumulateVector(cs);// rc = 2.3+3.3i
	cout << rc << endl;

	auto m = AccumulateVector(v, multiplies<int>(), 1);
	cout << m << endl;
}