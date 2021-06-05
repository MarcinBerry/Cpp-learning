#include <iostream>

using namespace std;

string login,haslo;

int main()
{
    cout << "Podaj Login:";
    cin>>login;
    cout<< "Podaj Haslo:";
    cin>>haslo;

    if ((login=="admin")&&(haslo=="szarlotka"))
    {
        cout<< "Udalo sie zalogowac";
    }
    else
    {
        cout<<"nie udalo sie zalogowac,sprobuj ponownie";
    }
    return 0;
}
