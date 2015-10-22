#include <string>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <cfloat>

void main()
{
	{
		assert(std::to_string(10) == "10");
		// �� ����� ����������� ���������� ����
		assert(std::to_string(10.7) == "10.700000");
	}

	{
		// ������� ����� ��������� � ������� ������ ������
		std::ostringstream strm;
		strm << 10.5;
		assert(strm.str() == "10.5");
	}
	{
		std::ostringstream strm;
		strm << std::setprecision(4) << 102.12345678;
		assert(strm.str() == "102.1");
	}
	{
		std::ostringstream strm;
		strm << std::fixed << std::setprecision(4) << 102.12345678;
		assert(strm.str() == "102.1235");
	}

	{
		assert(std::stoi("42") == 42);
		size_t stoppedAt;
		assert(std::stoi("123456blablabla", &stoppedAt) == 123456);
		assert(stoppedAt == 6);
		assert(std::stoi("f3eblablabla", &stoppedAt, 16) == 0xf3eb);
		assert(stoppedAt == 4);
	}

	{
		try
		{
			// ��� ������ stoi �������� ����������, ���� �� ������ ���������������
			std::stoi("not a number");
			// ���� �� �� �������
			assert(false);
		}
		catch (const std::invalid_argument & err)
		{
			// ������� ����
			std::cout << err.what();
		}

		try
		{
			int i = std::stoi("123not a number");
			assert(i == 123);
		}
		catch (const std::invalid_argument & /*err*/)
		{
			// ���� �� �������, �.�. ������� ��������������� ���� ���-��
			assert(false);
		}

		try
		{
			std::stoi("5555555555not a number");
			// ���� �� �� �������
			assert(false);
		}
		catch (const std::out_of_range & err)
		{
			// ������� ����, �.�. 5555555555 �� ���������� � int
			std::cout << err.what();
		}

	}

	{
		// ������� ��������� �����, ��������� �� ������� "123.78"
		std::istringstream strm("123.78");
		double value;
		strm >> value; // ��������� �������� ���� double
		assert(strm);  // ��������� �� ������� ������
		assert(abs(value - 123.78) < DBL_EPSILON);
	}

	{
		// ������� ��������� �����, ��������� �� ������� "not-a-string"
		std::istringstream strm("not-a-string");
		double value;
		strm >> value; // ��������� �������� ���� double
		assert(!strm);  // �������, ��� ����� ��������� � ��������� ������, �.�. ������� double �� �����
	}

}