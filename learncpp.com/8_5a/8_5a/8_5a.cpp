// 8_5a.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <cstdint>

class RGBA
{
private:
	std::uint8_t m_red;
	std::uint8_t m_green;
	std::uint8_t m_blue;
	std::uint8_t m_alpha;

public:
	
	RGBA()
	{
		m_red = 0;
		m_green = 0;
		m_blue = 0;
		m_alpha = 255;
	}
	
	RGBA(const std::uint8_t red = 0, const std::uint8_t green = 0, const std::uint8_t blue = 0, std::uint8_t alpha = 255)
		: m_red(red),
		m_green(green),
		m_blue(blue),
		m_alpha(alpha)
	{
	}
	void print()
	{
		std::cout << "r=" <<static_cast<int>(m_red) << " g=" << static_cast<int>(m_green) << " b=" << static_cast<int>(m_blue) << " a=" << static_cast<int>(m_alpha) << "\n";
	}
};

int main()
{
	RGBA teal(0, 127, 127);
	teal.print();
    return 0;
}

