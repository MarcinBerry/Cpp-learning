#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

string imie, nazwisko;
int nr_tel;
int nr_lini=1;

int main()
{
    fstream plik;
    plik.open("wizytówka.txt", ios::in);

    if(plik.good()==false)
    {
        cout<<"Plik nie istnieje!";
        exit(0);
    }

    string linia;
    while(getline(plik,linia))
    {
       switch(nr_lini)
       {
           case 1: imie = linia; break;
           case 2: nazwisko = linia; break;
           case 3: nr_tel=atoi(linia.c_str()); break;
       }

        nr_lini++;
    }

    plik.close();

    cout<<imie<<endl;
    cout<<nazwisko<<endl;
    cout<<nr_tel<<endl;


    return 0;
}
