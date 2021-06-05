/*
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
bool hasNext(element* el) {
    if (el->next != nullptr)
        return true;
    else
        return false;
}
bool hasPrev(element* el) {
    if (el->prev != nullptr)
        return true;
    else
        return false;
}
bool isEmpty(double_list l) {
    if (l.head == nullptr || l.tail == nullptr)
        return true;
    else
        return false;
}
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
void delTail(double_list& l) {
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
}
void delHead(double_list& l) {
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
}
void delPosition(double_list& l, int position)
{
    if (!isEmpty(l)) {
        element* temp = l.head;
        for (int i = 1; i < position - 1; i++)
            temp = temp->next;
        if (position == l.counter)
            delTail(l);
        else if (position == 1)
            delHead(l);
        else {
            element* temp_us = temp->next;
            temp->next = temp_us->next;
            temp->next->prev = temp;
            delete temp_us;
            l.counter--;
        }
        show(l);
    }
}
int sum(double_list& l) {
    element* temp = l.head;
    int i = 1;
    int sum = 0;
    for (; i <= l.counter;) {
        int number = (int)temp->number;
        if (number < 0)
            number = abs(number);
        int setki = 0, dziesiatki = 0, jednosci = 0;
        if (number > 100) {
            setki = number / 100;
            number %= 100;
        }
        if (number > 10) {
            dziesiatki = number / 10;
            jednosci = number % 10;
        }
        sum += setki + dziesiatki + jednosci;

        temp = temp->next;
        i++;
    }
    return sum;
}
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
}
void addPosition(double_list& l, int pos, double val) {
    element* temp = l.head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    element* el = new element;
    el->number = val;
    if (l.counter == 0 || pos == 1)
        addHead(l, val);
    else if (l.counter == pos - 1)
        addTail(l, val);
    else {
        el->prev = temp;
        el->next = temp->next;
        temp->next->prev = el;
        temp->next = el;
        l.counter++;
    }
    show(l);
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
            addPosition(l, pos, arg);
        }
        else if (znak == '>') {
            plik.get(znak);
            pos = (int)znak;
            delPosition(l, pos);
        }
        else if (znak == '!') {
            element* temp = l.head->next;
            int position = 2;
            while (position <= l.counter) {
                cout << "Kod '!'" << endl;
                if (temp->prev->number < temp->number) {
                    temp = temp->next;
                    delPosition(l, position);
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
*/