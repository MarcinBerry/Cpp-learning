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

void bubbleSort(student* tab, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (tab[j].punkty > tab[j + 1].punkty)
                swap(tab[j], tab[j + 1]);
        }
    }
}
void delStud(student*& tab)      //usuwanie tabeli studentów - zwalnianie miejsca
{
    delete[] tab;
}
void disStud(student* tab, int n)       //wyświetlanie studentów w tablicy
{
    for (int i = 0; i < n; i++)
    {

        cout << "Imie: " << tab[i].imie << endl;
        cout << "Nazwisko: " << tab[i].nazwisko << endl;
        cout << "Punkty: " << tab[i].punkty << endl;
    }
    cout << endl;
}
void readStud(student*& tab1, int& liczbaStudentow)
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
void save(ofstream& outstream, student tab)
{
    outstream << tab.imie << ";" << tab.nazwisko << ";" << tab.punkty << endl;
}
void biSearch(student*& tab, int n, int search)
{
    ofstream outstream;
    string path = "wynik.csv";
    outstream.open(path);

    int lewy = 0, prawy = n - 1, srodek = 0;
    for (; lewy <= prawy;)
    {
        srodek = (int)(lewy + prawy) / 2;
        if (tab[srodek].punkty == search)
        {
            save(outstream, tab[srodek]);

            for (int i = 1; search == tab[srodek + i].punkty; i++)
                save(outstream, tab[srodek + i]);
            for (int ii = 1; search == tab[srodek - ii].punkty; ii++)
                save(outstream, tab[srodek - ii]);
            return;
        }
        else
        {
            if (search < tab[srodek].punkty)
                prawy = srodek - 1;
            else
                lewy = srodek + 1; 
        }
    }
    cout << "Nie znaleziono studenta z podana liczba punktow.";
}
void disStudWithDivide(student* tab, int n, int d, int divider)
{
    int i;
    cout << "Studenci ktorzy otrzymali <= " << divider << " punktow " << endl;
    for (i = 0; i < d; i++)
    {
        cout << "Imie: " << tab[i].imie << endl;
        cout << "Nazwisko: " << tab[i].nazwisko << endl;
        cout << "Punkty: " << tab[i].punkty << endl;
    }
    cout << "Studenci ktorzy otrzymali > " << divider << " punktow " << endl;
    for (; i >= d && i < n; i++)
    {
        cout << "Imie: " << tab[i].imie << endl;
        cout << "Nazwisko: " << tab[i].nazwisko << endl;
        cout << "Punkty: " << tab[i].punkty << endl;
    }
    cout << endl;
}
int divideOnTwo(student*& tab, int n, int divider) 
{
    int i = 0;
    int j = n - 1;
    for (; i < j;)
    {
        for (; tab[i].punkty <= divider && i < j;)
            i++;
        for (; tab[j].punkty > divider && i < j;)
            j--;
        if (i < j)
        {
            swap(tab[i], tab[j]);
            i++;
            j++;
        }
    }
    if (tab[i].punkty <= divider)
        return i + 1;
    else
        return i;
}

int main()
{
    /* --- DEKLARACJA ZMIENNYCH --- */
    int n;                             // liczba studentów, index podzialu
    student* studentsTab = nullptr;       //tablica z studentami

    while (true)                          //pętla z mnu wielokrotnego wyboru
    {
                                                        //Wybor działania
        int action = 0, score = 0, divider = 10, d = 0;;
        cout << "Prosze wybrac dzialanie: " << endl;    
        cout << "1. Podzial zbioru na dwa" << endl;     
        cout << "2. Szukanie bisekwencyjne" << endl;
        cout << "3. Wyjscie" << endl;
        do
        {
            cin >> action;                              //Wprowadzenie wyboru
        } while (!(action == 1 || action == 2 || action == 3));

        switch (action)
        {
        case 1:                                         //Podział zbioru na dwa
            readStud(studentsTab, n);                
            disStud(studentsTab, n);             
            d = divideOnTwo(studentsTab, n, divider);
            disStudWithDivide(studentsTab, n, d, divider);             
            delStud(studentsTab);
            break;
        case 2:                                         //Szukanie bisekcyjne wybranej liczby
            do
            {
                cout << "Prosze podac liczbe punktow (rowna lub wieksza od  0): ";
                cin >> score;
            } while (score < 0 || !isdigit(score) == false);

            readStud(studentsTab, n);                
            cout << "Studenci przed sortowaniem: " << endl;
            disStud(studentsTab, n);             
            bubbleSort(studentsTab, n);
            cout << "Studenci po sortowaniu: " << endl;
            disStud(studentsTab, n);
            biSearch(studentsTab, n, score);
            delStud(studentsTab);
            break;
        case 3: return 0;                               //wyjście z programu
        }
    }
    return 0;
}
