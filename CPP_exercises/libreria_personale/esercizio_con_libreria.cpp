#include <iostream>
#include "mylib.h"

using namespace std;

void stampaMenu()
{
	cout << "0. Uscita" << endl;
	cout << "1. Crea vettore" << endl;
	cout << "2. Stampa vettore" << endl;
}

void menu(int vettore[], int n, int scelta)
{
	stampaMenu();
	do
	{
		switch(scelta)
		{
			case 1:
				riempiVettoreRandom(vettore, n);
				break;
			case 2:
				stampaVettore(vettore, n);
				break;
			default:
				cout << "Opzione non valida" << endl;
				break;
		}
		cout << "Scegli un comando: ";
		cin >> scelta;
	}while(scelta != 0);
}

int main()
{
	int n=10, scelta;
	int vettore[10];
	menu(vettore, n, scelta);
}
