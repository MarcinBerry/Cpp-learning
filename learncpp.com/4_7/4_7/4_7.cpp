// 4_7.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>

/*struct Ad
{
	int views;
	float clicked;
	float moneyPerAd;
};

struct Employee
{
	short id;
	int age;
	double wage;
};

float getValue(std::string valueName)
{
	std::cout << "Enter a number of " << valueName << std::endl;
	float value;
	std::cin >> value;

	return value;
}
void printValue(Ad websiteAd)
{
	
	std::cout << "Number of your viewed Ads " << websiteAd.views << std::endl;
	std::cout << "Percent of your clicked Ad " << websiteAd.clicked << "%" << std::endl;
	std::cout << "Money that you earn from clicked Ad " << websiteAd.moneyPerAd << std::endl;
	
	double dailyMoney = websiteAd.views * (websiteAd.clicked / 100) * websiteAd.moneyPerAd;
	if (dailyMoney > 10)
		std::cout << std::setprecision(4);
	else
		std::cout << std::setprecision(3);

	std::cout << "Money earned this day " << dailyMoney << std::endl;

}
int main()
{
	//std::cout << "The size of Empoyee is" << sizeof(Employee) << std::endl;
	Ad websiteAd;

	websiteAd.views = getValue("views");
	websiteAd.clicked = getValue("clicked Ad (in percent)");
	websiteAd.moneyPerAd = getValue("money from clicked Ad");

	printValue(websiteAd);
	

    return 0;
}
*/
struct fraction
{
	int numerator;
	int denumerator;
};
void multiply(fraction f1, fraction f2)
{

}
int main 
{
	fraction f1;
	std::cout << "Enter you frist numerator ";

	
	return 0;
}
