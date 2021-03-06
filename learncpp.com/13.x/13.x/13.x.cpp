// 13.x.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <string>

template <typename T1, typename T2>
class Pair
{
protected:
	T1 m_p1;
	T2 m_p2;
public:
	Pair(const T1 &p1, const T2 &p2) : m_p1(p1), m_p2(p2) {}

	T1 first() { return m_p1; }
	T2 second() { return m_p2; }
	T1 first() const { return m_p1; }
	T2 second() const { return m_p2; }
};

template<typename T>
class StringValuePair : public Pair<std::string, T>
{
public:
	StringValuePair(const std::string& name, const T& value) : Pair<std::string, T>(name, value) {}
};

int main()
{
	Pair<int, double> p1(5, 6.7);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	Pair<double, int> p2(2.3, 4);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	StringValuePair<int> svp("Hello", 5);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;
}

