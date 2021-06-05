#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

using namespace std;

char wybor, klasa;
string imie, postac;

int main()
{
    while (true)
    {
    cout<<"Moja gra v0.1"<<endl;

    cout<<"Witaj w mojej pierwszej grze"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"MENU GLOWNE"<<endl;
    cout<<"1. Kontynuj"<<endl;
    cout<<"2. Rozpocznij nowa gre"<<endl;
    cout<<"3. Opcje"<<endl;
    cout<<"4. Wylacz gre"<<endl;

    wybor=getch();

    switch(wybor)
    {
    case '1':
        {
            cout<<"Dobrze Cie widziec ";
            cout<<imie;
            cout<<".";
            system("pause");
        }
        break;
    case '2':
        {
            system("CLS");
            cout<<"Podaj swoje imie przybyszu: ";
            cin>>imie;
            system("CLS");
            cout<<"Swietnie! Teraz wybierz swoja postac: "<<endl;
            cout<<"--------------------------------------"<<endl;
            cout<<"1. Wojownik - Duzo zycia, wysokie obrazenia"<<endl;
            cout<<"2. Lotrzyk - Malo zycia, male obrazenie, wieksze prawdopodobienstwo unikniecia obrazen"<<endl;
            cout<<"3. Krzyzowiec - Srednie zycia, srednie obrazenia, czesc zadanych obrazen leczy bohatera"<<endl;
            cout<<"4. Lucznik - Malo zycia, srednie obrazenia, wysokie prawdopodobienstwo krytycznych obrazen"<<endl;
            klasa=getch();
            system("CLS");
            ;
        }
        break;
    case '3':
        {

        }
        break;
    case '4':
        {
            exit(0);
        }
        break;
    }
    }
    return 0;
}
