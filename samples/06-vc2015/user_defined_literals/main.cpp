#include <iostream>
#include <complex>
#include <chrono>

using namespace std;
using namespace std::complex_literals;

using namespace std::chrono;
using namespace std::chrono_literals;

typedef complex<double> ComplexNum;

void main()
{
	ComplexNum x(3, 8.5);
	cout << x << endl;

	auto x1 = 3.6 + 7.5i;
	cout << x1 << endl;

	std::chrono::seconds time(10);
	cout << time.count() << " seconds" << endl;

	auto time1 = 18ms; // time1:std::chrono::milliseconds
	cout << time1.count() << " ms" << endl;

	auto result = time + time1; // result: std::chrono:milliseconds
	cout << result.count() << " ms" << endl;

	auto timeNs = 135ns;
	auto resultNs = result + timeNs;
	cout << resultNs.count() << " ns" << endl;

	result += duration_cast<milliseconds>(resultNs);
	cout << result.count() << " ms" << endl;
}