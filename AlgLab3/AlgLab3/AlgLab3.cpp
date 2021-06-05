#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct element{
    char znak;
    element* next;
};
/* ----- Dodanie znaku do stosu ----- */
void push(element* &stack, char z)
{
    element* el = new element;
    el->znak = z;
    el->next = stack;
    stack = el;
}
/* ----- Usunięcie znaku ze stosu ----- */
void pop(element*& stack)
{
    element* temp = stack;
    stack = stack->next;
    delete temp;
}
/* ----- Sprawdzenie czy stos jest pusty ----- */
bool isEmpty(element* stack)
{
    if (stack == nullptr)
        return true;
    else return false;
}
/* ----- Zwrócenei pierwszego znaku z góry ----- */
char top(element* stack)
{
    return stack->znak;
}
/* ----- Wyświetlenie i opróznienie całego stosu ----- */
void throwAll(element*& stack)
{
    while(!isEmpty(stack))
    {
        cout << top(stack);
        pop(stack);
    }
}
/* ----- Zadanie 1 -----*/
void exercise1(element*& stack)
{
    /* ----- Otwrzcie strumienia odczytu z Znaki1.txt ----- */
    fstream in;
    in.open("Znaki1.txt");

    /* ----- Otwarcie strumienia zapisu do wyniki.txt ----- */
    ofstream outstream;
    outstream.open("wynik.txt");

    /* ----- Odczyt z pliku Znaki1.txt znaków i dodawanie ich do stosu -----*/
    do {                        
        push(stack, in.get());
    } while (!in.eof());

    /* ----- Zapis znaków ze stosu do pliku wyniki.txt ----- */
    do {    
        cout << top(stack);
        outstream << top(stack);
        pop(stack);
    } while (!isEmpty(stack));
    cout << endl << endl << "Tekst zapisano do pliku wyniki.txt" << endl;
}
/* ----- Zadanie 2 ----- */
void exercise2(element*& stack)
{
    /* ----- Tworzenie strumienia odczytu stosu.txt -----*/
    fstream in;
    in.open("stos.txt");

    char znak;
    /* ----- Odczyt stosu znak po znaku ----- */
    while(!in.eof())
    {
        znak = in.get();
        if (znak == '<')            //Dodanie nastęopnego znaku do stosu
        {
            push(stack, in.get());
        }
        if (znak == '>')            // Usunięcie znaku ze stosu
        {
            pop(stack);
        }
        if (znak == '|')            // Wyświetlenie znaków w stosie
        {
            throwAll(stack);
        }
        
    }
    cout << endl << endl;
}

int main()
{
    /* ---------- Tworzenie zasobów ---------- */
    element* stack = nullptr;

    /* ---------- Wejście do menu ---------- */
    while (true)
    {
        cout << "1. Zadanie 1" << endl;
        cout << "2. Zadanie 2" << endl;
        cout << "3. Wyjscie" << endl;
        int t;
        do                  // Wymuszenie poprawnych poprawnych liczb od użytkownika
        {
            cin >> t;
        } while (t < 1 || t > 3);

        switch (t)
        {
        case 1: system("cls"); exercise1(stack); break;
        case 2: system("cls"); exercise2(stack); break;
        case 3: return 0;
        }
    }
}
