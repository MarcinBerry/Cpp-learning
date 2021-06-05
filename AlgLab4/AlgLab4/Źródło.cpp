
#include <iostream>
#include <fstream>
using namespace std;

struct element {
    double number;
    element* next;
    element* prev;
};
struct double_list {
    element* head = nullptr;
    element* tail = nullptr;
    int counter = 0;
};
/* ---------- Funkcje wyœwietlaj¹ce ---------- */
void show(double_list& l) {
    element* el = l.head;
    for (int i = 1; i <= l.counter; i++) {
        cout << el->number << " ";
        el = el->next;
    }
    cout << endl;
}
void showMenu() {
    system("cls");
    cout << "-------------------- MENU --------------------" << endl;
    cout << "   1. Zadanie 1" << endl;
    cout << "   2. Zadanie 2" << endl;
    cout << "   3. Exit" << endl << endl;
    cout << "Prosze wybrac opcje: ";
}
/* ---------- Funkcje usuwaj¹ce -------------- */
void delTail(double_list& l)
{
    element* temp = l.tail;
    if (l.counter == 1) {
        l.tail = nullptr;
        l.head = nullptr;
    }
    else {
        l.tail = l.tail->prev;
        l.tail->next = nullptr;
    }
    delete temp;
    l.counter--;
    show(l);
}
void delList(double_list& l)
{
    element* temp = l.tail;
    for (int i = l.counter; i > 0; i--) {
        delTail(l);
    }
}
void delHead(double_list& l)
{
    element* temp = l.head;
    if (l.counter == 1) {
        l.tail = nullptr;
        l.head = nullptr;
    }
    else {
        l.head = l.head->next;
        l.head->prev = nullptr;
    }
    delete temp;
    l.counter--;
    show(l);
}
void delPosition(double_list& l, int pos) {
    element* temp = l.head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;
    element* temp_us = temp->next;
    temp->next = temp_us->next;
    temp->next->prev = temp;
    delete temp_us;
    l.counter--;
    show(l);
}
void delElement(double_list& l, int pos) {
    if (pos == 1)
        delHead(l);
    else if (pos == l.counter)
        delTail(l);
    else
        delPosition(l, pos);
}
/* ---------- Funkcje dodaj¹ce --------------- */
void addHead(double_list& l, double val) {
    element* el = new element;
    el->number = val;
    el->next = nullptr;
    el->prev = nullptr;
    if (l.head != nullptr) {
        l.head->prev = el;
        el->next = l.head;
    }
    else
        l.tail = el;

    l.head = el;
    l.counter++;
    show(l);
}
void addTail(double_list& l, double val) {
    element* el = new element;
    el->number = val;
    el->next = nullptr;
    el->prev = nullptr;
    if (l.tail != nullptr) {
        l.tail->next = el;
        el->prev = l.tail;
    }
    else
        l.head = el;
    l.tail = el;
    l.counter++;
    show(l);
}
void addPosition(double_list& l, int pos, double val) {
    element* temp = l.head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;
    element* el = new element;
    el->number = val;
    el->prev = temp;
    el->next = temp->next;
    temp->next->prev = el;
    temp->next = el;
    l.counter++;
    show(l);
}
void addElement(double_list& l, int pos, double val) {
    if (pos == 1)
        addHead(l, val);
    else if (pos > l.counter)
        addTail(l, val);
    else
        addPosition(l, pos, val);
}
int sum(double_list& l) {
    element* temp = l.head;
    int sum = 0;
    for (int i = 1; i <= l.counter; i++) {
        int number = (int)temp->number;
        if (number < 0)
            number = abs(number);
        int setki = 0, dziesiatki = 0, jednosci = 0;
        if (number >= 100) {
            setki = number / 100;
            number %= 100;
        }
        else if (number >= 10) {
            dziesiatki = number / 10;
            jednosci = number % 10;
        }
        else {
            jednosci = number;
        }
        sum += setki + dziesiatki + jednosci;
        
        temp = temp->next;  
    }
    return sum;
}
void readFile() {
    ifstream plik;
    plik.open("plik2.tsk");
    char znak;
    while(plik.get(znak)) {
        cout << (int)znak << " ";
    }
    cout << endl;
}
double srednia(double_list& l) {
    double sum = 0;
    element* temp = l.head;
    sum += temp->number;
    int ii = 1;
    double higest = temp->number;
    for (int i = 1; i <= l.counter - 1; i++) {
        if (higest > temp->next->number)
            temp = temp->next;
        else {
            temp = temp->next;
            higest = temp->number;
            sum += temp->number;
            ii++;
        }
    }
    return sum / ii;
}

void zadanie_1(double_list& l) {
    ifstream plik;
    plik.open("plik1.tsk");
    char znak;
    while (plik.get(znak)) {
        int pos = 0, arg = 0;
        if (znak == '<') {
            plik.get(znak);
            pos = (int)znak;
            plik.get(znak);
            arg = (int)znak;
            addElement(l, pos, arg);
        }
        else if (znak == '>') {
            plik.get(znak);
            pos = (int)znak;
            delElement(l, pos);
        }
        else if (znak == '!') {
            element* temp = l.head->next;
            int position = 2;
            while (position <= l.counter) {
                if (temp->prev->number < temp->number) {
                    temp = temp->next;
                    delElement(l, position);
                }
                else {
                    temp = temp->next;
                    position++;
                }

            }
        }
    }
    cout << endl;
    cout << "Suma powyzszych cyfr: " << sum(l) << endl;
}

void zadanie_2(double_list& l) {
    ifstream plik;
    plik.open("plik2.tsk");
    char znak;
    int pos, arg;
    while (plik.get(znak)) {
        pos = 0, arg = 0;
        if (znak == '<') {
            plik.get(znak);
            pos = (int)znak;
            plik.get(znak);
            arg = (int)znak;
            addElement(l, pos, arg);
        }
        else if (znak == '>') {
            plik.get(znak);
            pos = (int)znak;
            delElement(l, pos);
        }
        else if (znak == '!') {
            element* pair1 = l.head;
            show(l);
            for (int srPos = 1; srPos <= l.counter; srPos += 3) {
                if (pair1->next == nullptr) {
                    addTail(l, pair1->number);
                }
                element* pair2 = pair1->next;
                double sr = (double)(pair1->number + pair2->number) / 2;
                addElement(l, srPos + 1, sr);
                
                pair1 = pair2->next;
            }
            }
        
        } 
    show(l);
    cout << endl << "Srednia z powyzszych liczb: " << srednia(l) << endl;
}

int main()
{
    double_list l;
    while (true) {
        int choice;

        do {
            showMenu();
            
            cin >> choice;
        } while (choice > 3 || choice < 1);
        switch (choice)
        {
        case 1:
            system("cls");
            zadanie_1(l);
            system("pause");
            delList(l);
            break;
        case 2: system("cls");
            zadanie_2(l);
            system("pause");
            delList(l);
            break;
        case 3: return 0;
        }

    }
    return 1;
}
