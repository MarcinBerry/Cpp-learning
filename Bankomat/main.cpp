#include <iostream>

using namespace std;

string PIN;
int main()
{
    cout << "Witaj w mBank" << endl;
    cout <<"Podja numer PIN karty:";
    cin >>PIN;

    if(PIN=="1729")
    {
        cout<<"PIN poprawny, prosze wprowadziæ kwote do wyplaty:";

    }
    else
    {
        cout<<"PIN niepoprawny,wpisz PIN ponownie";
    }

    return 0;
}
