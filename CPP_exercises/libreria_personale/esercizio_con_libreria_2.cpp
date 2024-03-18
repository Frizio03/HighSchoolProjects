#include <iostream>
#include "mylib.h"

using namespace std;

void aumentoPercentuale(int v[], int n, int percent)
{
	for (int i=0; i<n; i++)
	{
		v[i] = v[i]*1.1;
	}
}

void stampaIndicePari(int v[], int n)
{
	cout << "\n" << "Elementi di indice pari: [";
	for (int i=0; i<n; i++)
	{
		if ((i%2)==0)
			cout << " " << v[i] << ",";
	}
	cout << "]" << endl;
}

int volteMin(int v[], int n)
{
	int min = minore(v, n);
	int counter=0;
	for (int i=0; i<n; i++)
	{
		if (v[i]==min)
			counter++;
	}
	return counter;
}

void stampaVettorePari(int v[], int n)
{
	cout << "\n" << "Il tuo vetore pari/dispari:" << endl;
	for (int i=0; i<n; i++)
	{
		if ((v[i]%2)==0)
			cout << v[i] << " PARI," << endl;
		else
			cout << v[i] << " DISPARI," << endl;
	}
}

void stampaMenu()
{
	cout << "1. Uscita" << endl;
	cout << "2. Stampa vettore" << endl;
	cout << "3. Aumenra del 10% ogni elemento del vettore" << endl;
	cout << "4. Elemento massimo del vettore" << endl;
	cout << "5. N volte di elemento minimo" << endl;
	cout << "6. Elementi di inice pari" << endl;
	cout << "7. stampa vettore con descrizione pari/dispari" << endl;
}

void menu(int vettore[], int n, int scelta)
{
	stampaMenu();
	cout << "--------------------------" << endl;
	do
	{
		switch(scelta)
		{
			case 2:
				stampaVettore(vettore, n);
				break;
			case 3:
				aumentoPercentuale(vettore, n, 10);
				break;
			case 4:
				cout << "il massimo è: " << maggiore(vettore, n) << endl;
				break;
			case 5:
				cout << "Elemento minimo presente volte: " << volteMin(vettore, n) << endl;
				break;
			case 6:
				stampaIndicePari(vettore, n);
				break;
			case 7:
				stampaVettorePari(vettore, n);
				break;
			default:
				cout << "Opzione non valida" << endl;
				break;
		}
		cout << "Scegli un comando: ";
		cin >> scelta;
	}while(scelta != 1);
}

int main()
{
	int n=10, scelta;
	setRandomMin(50);
	setRandomMax(150);
	cout << "Inserire dimensione del vettore: ";
	cin >> n;
	int vettore[n];
	riempiVettoreRandom(vettore, n);
	menu(vettore, n, scelta);
}
