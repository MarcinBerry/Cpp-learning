#include <iostream>

using namespace std;

int uczniowie,cukierki,x,y;

int main()
{
    cout<<"Ile cukierkow kupila Twoja mama:"<<endl;
    cin>>cukierki;

    cout<<"Ile jest uczniow w Twojej klasie:"<<endl;
    cin>>uczniowie;

    x = cukierki/(uczniowie-1);
    cout<<"Ilosc cukierkow dla uczniow:"<<x;

    y = cukierki-(uczniowie-1)*x;
    cout<<endl<<"Ilosc cukierkow dla Jasia na wieczor:"<<y;
    return 0;
}
