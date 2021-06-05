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
void displayList(double_list& l) {
    element* el = l.head;
    for (int i = 1; i < l.counter; i++) {
        cout << el->number << " ";
        el = el->next;
    }
    cout << endl;
}
void addPosition(double_list& l, double val, int pos) {
    //Stworzenie nowego elementu
    element* el = new element;
    el->value = val;
    el->next = nullptr;
    el->prev = nullptr;
    //Dodanie go do struktury
    if (l.counter == 0) {
        l.head = el;
        l.tail = el;
    }
    else if (pos = 1 && l.counter != 0) { // Dodanie na pocz¹tku
        el->next = l.head;
        l.head = el;
    }
    else if (pos = l.counter && l.counter != 0) { //Dodanie na koñcu listy
        el->prev = l.tail;
        l.tail->el;
    }
    else {
        element* temp = l.head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        temp->prev = el;
        el->next = temp;
        el->prev = temp->prev;
        temp->prev->next = el;
    }
    displayList(l);
}
int main() {

    return 0;
}