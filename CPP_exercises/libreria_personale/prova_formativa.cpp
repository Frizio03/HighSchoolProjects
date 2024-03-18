#include <iostream>
#include "mylib.h"

using namespace std;

void aumento(float v[], int n)
{
	for (int i=0; i<n; i++)
	{
		if (v[i]>5000)
			v[i] += 100;
	}
}

int contaValori(float v[], int n)
{
	int count = 0;
	for (int i=0; i<n; i++)
	{
		if (v[i]>=6000 && v[i]<=7000)
			count++;
	}
	return count;
}

void filtro(float v[], int n)
{
	int H=0;
	do{
		cout << "Inserisci il valore dell'indice per filtro: ";
		cin >> H;
		if (H >= n)
		{
			cout << "Valore indice inserito non valido..."  << endl;
			H = 0;
		}
	}while(H == 0);
	
	cout << "Mostro solo i valori minori di " << v[H] << endl;
	stampaVettore(v, H);
	cout << endl;
}

void posizioneMaggiori(float v[], int n)
{
	for (int i=0; i<n; i++)
	{
		if (v[i]==maggiore(v, n))
			cout << "\nLa posizione dell'elemento maggiore è: " << i << " - ";
	}
	cout << endl << endl;
}

void differenza(float v[], int n)
{
	for (int i=1; i<n; i++)
	{
		cout << "Il conto in posizione " << i << " è " << v[i]-v[i-1] << " volte maggiore rispetto a quello in posizione " << i-1 << endl;
	}
}

void stampaMenu()
{
	cout << "1. Uscita" << endl;
	cout << "2. Mostra vettore" << endl;
	cout << "3. Aumenta di 100 tutti i valori maggiori di 5000" << endl;
	cout << "4. Conta quanti sono i valori compresi tra 6000 e 7000 compresi" << endl;
	cout << "5. Mostrare il numero (l'indice) del conto con più alto (se ce ne sono di più mostrarli tutti)" << endl;
	cout << "6. Prendere in input un valore H. Mostrare tutti i conti con valori < V[H]" << endl;
	cout << "7. Contare quante volte un conto è maggiore del suo precedente (il primo non è da controllare…)" << endl;
}

void menu(float vettore[], int n, int scelta)
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
				aumento(vettore, n);
				break;
			case 4:
				cout << "\nCi sono " << contaValori(vettore, n) << " valori compresi fra 6000 e 7000 inclusi\n" << endl;
				break;
			case 5:
				posizioneMaggiori(vettore, n);
				break;
			case 6:
				filtro(vettore, n);
				break;
			case 7:
				differenza(vettore, n);
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
	int len=10000, scelta, n;
	float vettore[len];
	setRandomMin(1000);
	setRandomMax(10000);
	do{	
		cout << "Inserire dimensione del vettore: ";
		cin >> n;
		if(n<0)
		{
			cout << "Il vettore non può essere negativo..." << endl;
			n=0;
		}
	}while(n==0);
	riempiVettoreRandom(vettore, n);
	menu(vettore, n, scelta);
}
