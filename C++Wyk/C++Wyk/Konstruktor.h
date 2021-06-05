#include <string>
#include <iostream>
#include <fstream>

using namespace std;
class Konstruktor
{
private:
	static ofstream plik;
public:
	Konstruktor(string sciezka)
	{
		plik.open(sciezka);

		if (plik)
		{
			plik << "Hello, world!" << endl;
			cout << "Zapisano do pliku" << endl;
		}
		else
		{
			cout << "B³¹d odczytu pliku" << endl;
		}
	}
	~Konstruktor()
	{
		plik.close();
	}
};
