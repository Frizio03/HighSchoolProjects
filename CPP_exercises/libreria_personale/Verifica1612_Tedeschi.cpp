// Verifica C++ 16/12/2019 - Tedeschi Fabrizio
#include <iostream>
#include "libreriaVettori.h"

using namespace std;

// la funzione diminuisce del 5% tutti i conti con valore minore di 30000
void diminuisciPercentuale(float v[], int n)
{
	for (int i=0; i<n; i++)
	{
		if (v[i]<30000)
		{
			v[i] = v[i]*(1-0.05);
		}
	}
}

// la funzione mostra il credito di un conto il cui indice è dato in input
void mostraCredito(float v[], int n)
{
	int C=-1;
	do
	{
		cout << "Inserisci indice del conto: ";
		cin >> C;
		if (C<0)
		{
			cout << "il valore non può essere negativo..." << endl;
			C=-1;
		}
		if (C>n-1)
		{
			cout << "il valore è troppo alto..." << endl;
			C=-1;
		}
	}while(C==-1);
	cout << "Credito di " << C << " = " << v[C] << endl;
}

// la funzione aumenta di un valore dato in input di un conto con indice dato in input 
void aumento(float v[], int n)
{
	int C=0;
	float V=0;
	cout << "Inserisci indice del conto: ";
	cin >> C;
	cout << "\nInserisci valore V da aggiungere: ";
	cin >> V;
	v[C] += V;
	cout << "Credito di " << C << " = " << v[C] << endl;
}

// la funzione divide il credito di un conto spalmandolo sugli altri e azzerandpo il conto con indice dato in input in C 
void dividi(float v[], int n)
{
	int C=0;
	float div=0;
		do
	{
		cout << "Inserisci indice del conto: ";
		cin >> C;
		if (C<0)
		{
			cout << "il valore non può essere negativo..." << endl;
			C=-1;
		}
		if (C>n-1)
		{
			cout << "il valore è troppo alto..." << endl;
			C=-1;
		}
	}while(C==-1);
	div = v[C]/(n-1);
	for (int i=0; i<n; i++)
	{
		if (i != C)
			v[i] += div;
	}
	v[C] = 0;
}

// la funzione stampa gli indici e i valori di tutti i conti conti con valore maggiore
void Maggiori(float v[], int n)
{
	for (int i=0; i<n; i++)
	{
		if (v[i]==massimo(v, n))
			cout << "\nIl/i conto/i maggiore/i è/sono: " << i << " con valore " << v[i] << endl;
	}
	cout << endl << endl;
}

// verifica se i valori dei conti sono ordinati in ordine crescente
bool verifica(float v[], int n)
{
	for (int i=0; i<n; i++)
	{
		if (v[i]>v[i+1])
		{
			cout << "I conti NON sono ordinati in ordine crescente..." << endl;
			return false;
		}
	}
	cout << "I conti sono ordinati in ordine crescente..." << endl;
	return true;
}

// stampa sul terminale le opzioni del menu per l'utente
void stampaMenu()
{
	cout << "1. Uscita" << endl;
	cout << "2. Mostra vettore" << endl;
	cout << "3. Diminusci del 5% i conti minori di 30''000" << endl;
	cout << "4. Mostra il credito di un conto" << endl;
	cout << "5. Aumenta di un valore V un conto" << endl;
	cout << "6. Mostra il conto con credito maggiore" << endl;
	cout << "7. Dividi i soldi di un conto equamente su tutti gli altri e azzeralo" << endl;
	cout << "8. Verifica se i crediti sono in ordine crescente" << endl;
}

//gestisce il menu e le opzioni scelte dall'utente
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
				diminuisciPercentuale(vettore, n);
				break;
			case 4:
				mostraCredito(vettore, n);
				break;
			case 5:
				aumento(vettore, n);
				break;
			case 6:
				Maggiori(vettore, n);
				break;
			case 7:
				dividi(vettore, n);
				break;
			case 8:
				verifica(vettore, n);
				break;
			default:
				cout << "Opzione non valida" << endl;
				break;
		}
		cout << "Scegli un comando: ";
		cin >> scelta;
	}while(scelta != 1);
}

//programma principale
int main()
{
	int len=10000, scelta, n;
	float vettore[len];
	setRandomMin(0);
	setRandomMax(50000);
	do{	
		cout << "Inserire dimensione del vettore: ";
		cin >> n;
		if(n<0)
		{
			cout << "Il vettore non può essere negativo..." << endl;
			n=0;
		}
		if(n>len)
		{
			cout << "Il vettore non può essere maggiore di 10'000 elementi..." << endl;
			n=0;
		}
	}while(n==0);
	riempiVettoreRandom(vettore, n);
	menu(vettore, n, scelta);
}
