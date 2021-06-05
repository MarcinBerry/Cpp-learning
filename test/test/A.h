#pragma once
#include <iostream>
using namepsace std;
class A {
protected:
    int a, b, c;
public:
    A(int a = 0, int b = 0, int c = 0) {}
    int suma() { return a + b + c; }
    int roznica() { return a - b - c; }
    int iloraz() { return a / b / c; }
};
int main() {
    A obiekt(100, 3, 4);
    obiekt.a = 10;
    obiekt.b = 2;
    obiekt.c = 3;
    cout << "Suma: " << obiekt.suma();
    cout << "Roznica: " << obiekt.roznica();
    cout << "Iloraz: " << obiekt.iloraz();
}
