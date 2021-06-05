#include <iostream>

using namespace std;

int wiek;

int main()

{
    cout << "Ile masz lat:" << endl;
    cin>>wiek;

    if (wiek<18)
    {
        cout <<"Nie jestes pelnoletni i nie mozesz zostac prezydentem ";
    }
    else if ((wiek>=18)&&(wiek<35))
    {
        cout <<"Jestes pelnolteni ale nie mozesz zostac prezydentem ";
    }
    else
    {
        cout <<"Jestec pelnoletni i mozesz zostac prezydentem";
    }
    return 0;
}
