#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
using namespace std;

struct node {
	int key = 0;
	node* parent = nullptr;
	node* left = nullptr;
	node* right = nullptr;
};

/* ----------- Tworzenie drzewa ----------- */
node* makeNode(int value) {
	node* n = new node;
	n->key = value;
	n->left = nullptr;
	n->right = nullptr;
	n->parent = nullptr;
	return n;
}
void addNode(node*& root, int value) {
	if (root == nullptr) {
		root = makeNode(value);
		return;
	}
	node* temp = root;
	while (true) {
		if (value >= temp->key) {
			if (temp->right == nullptr) {
				temp->right = makeNode(value);
				temp->right->parent = temp;
				return;
			}
			else
				temp = temp->right;
		}
		else {
			if (temp->left == nullptr) {
				temp->left = makeNode(value);
				temp->left->parent = temp;
				return;
			}
			else
				temp = temp->left;
		}

	}
}

/* ---------- Wyœwietlanie drzewa --------- */
void preOrder(node* root) {
	if (root != nullptr) {
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}

}
void postOrder(node* root) {
	if (root != nullptr) {
		postOrder(root->left);
		postOrder(root->right);
		cout << root->key << " ";
	}

}
void inOrder(node* root) {
	if (root != nullptr) {
		inOrder(root->left);
		cout << root->key << " ";
		inOrder(root->right);
	}
}
void showMenu() {
	system("cls");
	cout << "############   Labortorium 5 z Podstaw Algorytmiki   ############" << endl;
	cout << "##  1. Sprawdzenie czy drzewo jest puste.                      " << endl;
	cout << "##  2. Dodanie nowego wezla do drzewa.                         " << endl;
	cout << "##  3. Wczytanie danych z pliku drzewo.txt do drzewa.          " << endl;
	cout << "##  4. Policzenie czestosci wystepowania elelmentow w drzewie. " << endl;
	cout << "##  5. Usuniecie calego drzwa.                                 " << endl;
	cout << "##  6. Wyjscie z programu.                                     " << endl;
}

node* findNode(node* root, int value) {
	while (root != nullptr) {
		if (root->key == value) 
			return root;
		
		if (value > root->key)
			root = root->right;
		else
			root = root->left;
	}
	return nullptr;
}

/* ---------- Opcje ----------*/
//Opcja 1
string isEmpty(node* root) {
	if (root != nullptr)
		return "Drzewo nie jest puste!";
	else
		return "Drzewo jest puste!";
}

//Opcja 2
void option2(node*& root) {
	int v = -1;
	do {
		cout << "Prosze podac wartosc nowego wezla (w przedziale 0 - 20): ";
		cin >> v;
	} while (v < 0 || v > 20);
	if (findNode(root, v) == nullptr) {
		cout << "Drzewo przed dodaniem wezla: " << endl;
		inOrder(root);
		cout << endl;
		addNode(root, v);
		cout << "Drzewo po dodaniu wezla: " << endl;
		inOrder(root);
		cout << endl;
	}
	else
		cout << "Nie dodano wezla do drzewa! Wezel o podanej wartosci juz istnieje." << endl;
}

//Opcja 3
void option3(node*& root) {
	cout << "Drzewo przed wczytaniem z pliku: " << endl;
	inOrder(root);
	readFile(root);
	cout << "Drzewo po wczytaniu z pliku: " << endl;
	inOrder(root);
}
void readFile(node*& root) {
	fstream file;
	file.open("drzewo.txt");

	char ch;
	int t = 0, i = 0, temp = 0;

	while (file.get(ch)) {
		if ((int)ch == 10) {
			addNode(root, t);
			t = 0;
			i = 0;
			temp = 0;
		}
		else {
			if (temp != 0)
				t *= 10;
			temp = ((int)ch - 48);
			t += temp;
		}
	}
	file.close();
}

//Opcja 4
void option4(node*& root) {
	int tabSize = 0, iter = 0;

	countTree(root, tabSize);
	int* tab = new int[tabSize];

	toTable(root, tab, iter);
	for (int i = 0; i <= 20; i++)
		cout << "Wartosci o wielkosci " << i << " jest: " << countNods(root, i, tab, tabSize) << endl;

	tab = nullptr;
	tabSize = 0, iter = 0;
}
void toTable(node* root, int tab[], int& iter) {
	if (root != nullptr) {
		toTable(root->left, tab, iter);
		tab[iter] = root->key;
		iter++;
		toTable(root->right, tab, iter);
	}
}
void countTree(node* root, int& i) {
	if (root != nullptr) {
		i++;
		countTree(root->left, i);
		countTree(root->right, i);
	}
}
int countNods(node* root, int value, int tab[], int tabSize) {
	int ii = 0;
	for (int i = 0; i < tabSize; i++) {
		if (tab[i] == value)
			ii++;

	}
	return ii;
}

int main() {
	node* root = nullptr;
	while (true) {
		int c = 0;
		do {
			showMenu();
			cout << "## Prosze wybrac akcje: ";
			cin >> c;
		} while (c < 1 || c > 6);
		switch (c)
		{
		case 1:
			system("cls");
			cout << isEmpty(root) << endl;;
			system("pause");
			break;
		case 2:
			system("cls");
			option2(root);
			system("pause");
			break;
		case 3: 
			system("cls");
			option3(root);
			system("pause");
			break;
		case 4: 
			system("cls");
			option4(root);
			system("pause");
			break;
		case 5: 
			system("cls");
			root = nullptr;
			system("pause");
			break;
		case 6:	
			return 0;
		}
		
	}

	return 0;
}