// 9_x.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <cassert>
#include <cmath>
/*
class Avarage
{
private:
	int32_t sumAll;
	int8_t sumMany;
public:
	Avarage(int32_t all = 0, int8_t many = 0) : sumAll(all), sumMany(many) {}

	Avarage(Avarage &avg)
	{
		sumAll = avg.sumAll;
		sumMany = avg.sumMany;
	}

	friend std::ostream& operator<< (std::ostream &out, const Avarage &avg);
	Avarage operator+= (double x)
	{
		sumAll += x;
		++sumMany;
		return *this;
	}
};
std::ostream& operator<< (std::ostream &out, const Avarage &avg)
{
	out << static_cast<double>(avg.sumAll) / avg.sumMany;
	return out;
}
int main()
{
	Avarage avg;

	avg += 4;
	std::cout << avg << '\n';

	avg += 8;
	std::cout << avg << '\n';

	avg += 24;
	std::cout << avg << '\n';

	avg += -10;
	std::cout << avg << '\n';

	(avg += 6) += 10;
	std::cout << avg << '\n';

	Avarage copy = avg;
	std::cout << copy << '\n';
    return 0;
}

class IntArray
{
private:
	int m_length;
public:
	IntArray(int length) : m_length(length)
	{

	}
	int& operator[]
};

IntArray fillArray()
{
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;
}
int main()
{
	return 0;
}
*/
class FixedPoint2
{
private:
	int16_t m_base;
	int8_t m_decimal;
public:
	FixedPoint2(int16_t base = 0, int8_t decimal = 0) : m_base(base), m_decimal(decimal)
	{
		if (m_base < 0.0 || m_decimal < 0.0)
		{
			if (m_base > 0.0)
				m_base = -m_base;
			if (m_decimal > 0.0)
				m_decimal = -m_decimal;
		}
	}
	FixedPoint2(double d)
	{
		m_base = static_cast<int16_t>(d);
		m_decimal = static_cast<std::int8_t>(round((d - m_base) * 100));
	}
	operator double() const
	{
		return m_base + static_cast<double>(m_decimal) / 100;
	}
	friend bool operator==(const FixedPoint2 &fp1, FixedPoint2 &fp2)
	{
		return (fp1.m_base == fp2.m_base && fp1.m_decimal == fp2.m_decimal);
	}
	friend FixedPoint2 operator+(const FixedPoint2 &fp1, const FixedPoint2 &fp2)
	{
		return FixedPoint2(static_cast<double>(fp1) + static_cast<double>(fp2));
	}
	FixedPoint2 operator-() const
	{
		return FixedPoint2(-m_base, -m_decimal);
	}
	friend std::ostream& operator<< (std::ostream &out, const FixedPoint2 &fp1)
	{
		out << static_cast<double>(fp1);
		return out;
	}
	friend std::istream& operator>> (std::istream &in, FixedPoint2 &fp1)
	{
		double d;
		in >> d;
		fp1 = FixedPoint2(d);
		return in;
	}
};
void testAddition()
{
	// h/t to reader Sharjeel Safdar for this method of testing
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.23) == FixedPoint2(1.98)) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.50) == FixedPoint2(2.25)) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.23) == FixedPoint2(-1.98)) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.50) == FixedPoint2(-2.25)) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.23) == FixedPoint2(-0.48)) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.50) == FixedPoint2(-0.75)) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.23) == FixedPoint2(0.48)) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.50) == FixedPoint2(0.75)) << '\n'; // first negative, possible decimal overflow
}

int main()
{
	testAddition();

	FixedPoint2 a(-0.48);
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';

	return 0;
}
