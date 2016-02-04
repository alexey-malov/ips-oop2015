#include <iostream>
#include <vector>
#include <string>
#include <complex>

using namespace std;

template <typename T>
T AccumulateVector(const vector<T> & items)
{
	T sum = T();
	for (auto & item : items)
	{
		sum += item;
	}
	return sum;
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
}