#include <iostream>

using namespace std;

string imie;
int ilosc;

int main()
{
    cout<<"Podaj Imie:";
    cin>>imie;
    cout<<"Podaj Liczbe:";
    cin>>ilosc;

    for(int i=1; i<=ilosc; i++)
        {
            cout<<i<<". "<<imie<<endl;
        }
}
