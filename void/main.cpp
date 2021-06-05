#include <cstdlib>
#include <iostream>
using namespace std;

void powiel(char znak)
{
  for(int i=0; i<20; i++)
    cout<<znak;

  cout<<endl;
}

int main()
{

  char znak;

  cout<<"Podaj znak, który chcesz powieliæ 20 razy: ";
  cin>>znak;

  //wywo³anie funkcji powiel(char)
  powiel(znak);

  system("pause");
  return 0;
}
