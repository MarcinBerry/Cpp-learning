// test.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "A.h"
using namespace std;

int main() {
    A obiekt(100, 3, 4);
    obiekt.a = 10;
    obiekt.b = 2;
    obiekt.c = 3;
    cout << "Suma: " << obiekt.suma();
    cout << "Roznica: " << obiekt.roznica();
    cout << "Iloraz: " << obiekt.iloraz();
}

/