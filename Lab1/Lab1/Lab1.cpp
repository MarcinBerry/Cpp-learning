#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <sstream>

using namespace std;

struct student //struktura zawierajaca trzy pola
{
    string imie;
    string nazwisko;
    int punkty;
};

void deleteStudents(student*& tab)      //usuwanie tabeli studentów - zwalnianie miejsca
{
    delete[] tab;
}
void deleteTab(int* &tab)       //usuwanie tabeli - zwalnianie miejsca
{
    delete[] tab;
}
void displayTab(int* tab, int n)        //wyświetlanie każdego elementu tablicy 
{
    for (int i = 0; i < n; i++)
    {
        cout << tab[i] << endl;
    }
    cout << endl;
}
void sortBubble(int* &tab, int n, int tryb)     //sortowanie za pomocą BubbleSort
{
    switch (tryb)
    {
    case 1:             //sortowanie od najmniejszego
        for (int i = 0; i < n; i++)             //pętla zewnętrzna
            for (int j = 1; j < n - i; j++)     //pętla wewnętrzna
                if (tab[j - 1] > tab[j])
                    swap(tab[j - 1], tab[j]);   //zamiana elementów
        break;
    case 2:             //sortowanie od największego
        for (int i = 0; i < n; i++)             //pętla zewnętrzna
            for (int j = 1; j < n - i; j++)     //pętla wewnętrzna
                if (tab[j - 1] < tab[j])
                    swap(tab[j - 1], tab[j]);   //zamiana elementów
        break;
    }
}
void sortInsert(int*& tab, int n, int tryb)     //sortowanie metodą InsertSort
{
    int pom, j;
    
    switch (tryb)
    {
    case 1:     //sortowanie od najmniejszego
        for (int i = 1; i < n; i++)
        {
            
            pom = tab[i]; 
            j = i - 1;

            //przesuwanie elementów większych od pom
            while (j >= 0 && tab[j] > pom)
            {
                tab[j + 1] = tab[j]; 
                --j;
            }
            tab[j + 1] = pom;
        }   break;
    case 2:     //sortowanie od największego
        for (int i = 1; i < n; i++)
        {
            
            pom = tab[i]; 
            j = i - 1;

            //przesuwanie elementów większych od pom
            while (j >= 0 && tab[j] < pom)
            {
                tab[j + 1] = tab[j]; 
                --j;
            }
            tab[j + 1] = pom;
        }   break;
    }
}
void sortQuickSort(student*& tab, int lewy, int prawy, int tryb)        //sortowanie QuickSort
{
    int srodek = (lewy + prawy) / 2;
    student pivot = tab[srodek];
    tab[srodek] = tab[prawy];
    int maks = lewy;
    for (int i = lewy; i < prawy; ++i)
    {
        switch (tryb)       //uwzględnienie trybu sortowania
        {
        case 1:                                 //sortowanie od najmniejszego
            if (tab[i].punkty < pivot.punkty)
            {
                swap<student>(tab[maks], tab[i]);
                ++maks;
            }
        case 2:                                 //sortowanie od największego
            if (tab[i].punkty > pivot.punkty)
            {
                swap<student>(tab[maks], tab[i]);
                ++maks;
            }
        }
    }
    tab[prawy] = tab[maks];
    tab[maks] = pivot;
    //korzystanie z rekurencji
    if (lewy < maks - 1)
    {
        sortQuickSort(tab, lewy, maks - 1, tryb);
    }
    if (maks + 1 < prawy)
    {
        sortQuickSort(tab, maks + 1, prawy, tryb);
    }
}
void prepTab(int &n, int*& tab)         //Tworzenie tablicy i zapełnianie jej losoywmi liczbami z wybranego zakresu
{
    //Deklaracja tablicy
    cout << "Prosze podac dlugosc tablicy(wieksza od 2): ";
    
    do
    { 
        cin >> n;
    } while (!(n > 2));
    
    cout << endl;
    tab = new int[n];

    //Pobieranie zakresu liczb do losowania
    cout << "Prosze podac zakres liczb w tablicy. ";
    int min, maks;
    do
    {
        cout << "Najmniejsza liczba: " << endl;
        
        cin >> min;
        cout << endl;
        cout << "Najwieksza liczba:  ";
        cin >> maks;
        cout << endl;
    } while (!(min < maks));

    //Zapełnianie tablicy losowymi liczbami z zakreu
    for (int i = 0; i < n; i++)
    {
        tab[i] = rand() % (maks - min + 1) + min;
    }
}
void readStudents(student*& tab1, int& liczbaStudentow)
{
    string sciezka, linia;
    ifstream plik; //uchwyt do wczytania danych z pliku
    char sredniki;
    string temp_punkty;
    sciezka = "studenci.csv"; //nazwa pliku, plik ma sie znajdowac w katalogu projektu
    plik.open(sciezka); //otwarcie pliku
    plik >> liczbaStudentow; //wczytanie z pliku pierwszej linijki - liczby studentow
    tab1 = new student[liczbaStudentow];
    for (int i = 0; i < 2; i++) //kazda dana oddzielona jest srednikiem, w pierwszej linijce jest tylko jedna liczba stad trzeba
        plik >> sredniki; //przeczytac puste sredniki

    for (int i = 0; i < liczbaStudentow; i++)
    {
        plik >> linia; //wczytanie calej linijki, w ktorej sa przechowywane informacje o studencie

        istringstream ss(linia);
        getline(ss, tab1[i].imie, ';'); //miedzy srednikami znajduja sie kolejne dane, wyluskanie imienia
        getline(ss, tab1[i].nazwisko, ';'); //wyluskanie nazwiska

        getline(ss, temp_punkty, ';'); //wyluskanie punktow
        tab1[i].punkty = atoi(temp_punkty.c_str()); //punkty sa typu int, a zmienna temp_punkty jest typu String w zwiazku
    }                                              //z tym nalezy dokonac konwertacji zmiennej temp_punkty na typ int
    plik.close(); //po przeczytaniu wszystkich linijek, plik nalezy zamknac
}
void displayStudents(student* tab, int n)       //wyświetlanie studentów w tablicy
{
    for (int i = 0; i < n; i++)
    {

        cout << "Imie: " << tab[i].imie << endl;
        cout << "Nazwisko: " << tab[i].nazwisko << endl;
        cout << "Punkty: " << tab[i].punkty << endl;
    }
    cout << endl;
}
int main()
{
    srand(time(NULL));

    //Deklaracja zmienej i tablic
    int n;
    int* randomTab = nullptr;
    student* studentsTab = nullptr;


    while (true)
    {
                           //Wybor metody sortowanie
        int metoda;
        cout << "Prosze wybrac metode sortowania: " << endl;
        cout << "1. QuickSort" << endl;     //sortowanie QuickSort
        cout << "2. BubbleSort" << endl;    //sortowanie BubbleSort
        cout << "3. InsertSort" << endl;     //sortowanie InsertSort
        cout << "4. Wyjscie" << endl;       //Wyjscie
        do
        {
            cin >> metoda;
        } while (!(metoda == 1 || metoda == 2 || metoda == 3 || metoda == 4));

                           //Wybor trybu sortowania
        cout << "Tryb sortowania(1 - Od najmniejszej, 2 - Od najwiekszej): ";
        int tryb;
        do
        {
            cin >> tryb;
        } while (!(tryb == 1 || tryb == 2));

        switch (metoda)
        {
        case 1:           //sortowanie Studentów QuickSortem
            readStudents(studentsTab, n);                //wczytanie studentów do tablicy
            displayStudents(studentsTab, n);             //wyświetlenie studentów z tablicy przed sortwaniem
            sortQuickSort(studentsTab, 0, n-1, tryb);    //sortowanie studentów w tablicy za pomocą QuickSort'a
            displayStudents(studentsTab, n);             //wyświetlenie studentów z tablicy po sortowaniu
            deleteStudents(studentsTab);
            break;
        case 2:          //sortowanie tablicy BubbleSortem
            prepTab(n, randomTab);                       //tworzenie tablicy i zapełnianie jej losoywmi liczbami
            displayTab(randomTab, n);                    //wyświetlenie tablicy przed sortowaniem
            sortBubble(randomTab, n, tryb);              //sortowanie tablicy za pomocą BubbleSort'em
            displayTab(randomTab, n);                    //wyświetlenie tablicy po sortowaniu
            deleteTab(randomTab);                        //zwalnianie miejsca po tablicy
            break;
        case 3:           //sortowanie tablicy InsertSortem
            prepTab(n, randomTab);                       //tworzenie tablicy i zapełnianie jej losoywmi liczbami
            displayTab(randomTab, n);                    //wyświetlenie tablicy przed sortowaniem
            sortInsert(randomTab, n, tryb);              //sortowanie tablicy za pomocą InsertSort'em
            displayTab(randomTab, n);                    //wyświetlenie tablicy po sortowaniu
            deleteTab(randomTab);                        //zwalnianie miejsca po tablicy
            break;
        case 4: return 0; //wyjście z programu
        }      
    }
    return 0;
}
