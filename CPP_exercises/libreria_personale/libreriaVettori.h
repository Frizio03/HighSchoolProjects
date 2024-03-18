#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


/* PROTOTIPI */
void setRandomMin(int min);
void setRandomMax(int max);
int randomNM(int n, int m);
float randomNM_float(int n, int m);
int random0N(int n);
float randomNM_float(int n);
void riempiVettore(int v[], int n);
void riempiVettore(float v[], int n);
void riempiVettoreRandom(int v[], int n);
void riempiVettoreRandom(float v[], int n);
void stampaVettore(float v[], int n);
void stampaVettore(int v[], int n);
void ordinamentoIngenuo(int v[], int n, bool inverso);
void ordinamentoIngenuo(float v[], int n, bool inverso);
void bubbleSort(int v[], int n, bool inverso);
void bubbleSort(float v[], int n, bool inverso);
int ricercaBinaria(int v[], int n, int x);
int ricercaBinaria(int v[], int n, int x);
int presente(int v[], int n, int x);
int presente(float v[], int n, float x);
float media(int v[], int n);
float media(float v[], int n);
float sommaVettore(float v[], int n);
int sommaVettore(int v[], int n);
void inverti(int v[], int n);
void inverti(float v[], int n);

int minimo(int v[], int n);
float minimo(float v[], int n);
int massimo(int v[], int n);
float massimo(float v[], int n);
int posizioneMinimo(int v[], int n);
int posizioneMinimo(float v[], int n);
int posizioneMassimo(int v[], int n);
int posizioneMassimo(float v[], int n);

/* FINE PROTOTIPI */


/* PER NON RICHIAMARE DUE VOLTE srand(time(NULL)) in un breve lasso di tempo */
bool randomInizializzato = false;
int random_min = 0, random_max = 100;
int dimensione_max = 1000;

void setDimensioneMax(int max)
{
	dimensione_max = max;
}

void setRandomMin(int min)
{
	random_min = min;
}

void setRandomMax(int max)
{
	random_max = max;
}

float randomNM_float(int n, int m)
{
	return (float) randomNM(n*10, m*10) / 10;
}

int randomNM(int n, int m)
{
	return rand() % (m-n+1) + n;
}

float random0N_float(int n, int m)
{
	return (float) randomNM_float(0, n*10) / 10;
}

int random0N(int n)
{
	return randomNM(0, n);
}

void riempiVettore(int v[], int n)
{
	cout << "INSERIMENTO VETTORE:" << endl;
	for (int i=0; i<n; i++)
	{
		cout << "\tInserisci elemento " << i+1 << ": ";
		cin >> v[i];
	}
	
	cout << endl;
}

void riempiVettore(float v[], int n)
{
	cout << "INSERIMENTO VETTORE:" << endl;
	for (int i=0; i<n; i++)
	{
		cout << "\tInserisci elemento " << i+1 << ": ";
		cin >> v[i];
	}
	
	cout << endl;
}

void riempiVettoreRandom(float v[], int n)
{
	if (!randomInizializzato)
	{
		srand(time(NULL));
		randomInizializzato = true;
	}
	
	srand(time(NULL));
	cout << "INSERIMENTO VETTORE RANDOM:" << endl;
	for (int i=0; i<n; i++)
	{
		cout << "\tInserimento random elemento " << i+1 << ": ";
		v[i] = randomNM_float(random_min, random_max);
		cout << v[i] << endl;
	}
	
	cout << endl;
}

void riempiVettoreRandom(int v[], int n)
{
	if (!randomInizializzato)
	{
		srand(time(NULL));
		randomInizializzato = true;
	}
	
	srand(time(NULL));
	cout << "INSERIMENTO VETTORE:" << endl;
	for (int i=0; i<n; i++)
	{
		cout << "\tInserimento random elemento " << i+1 << ": ";
		v[i] = randomNM(random_min, random_max);
		cout << v[i] << endl;
	}
	
	cout << endl;
}

void stampaVettore(int v[], int n)
{
	cout << "STAMPO IL VETTORE: " << endl;
	for (int i=0; i<n; i++)
	{
		cout << "\tElemento " << i+1 << ": " << v[i] << endl;
	}
	cout << endl;
}

void stampaVettore(float v[], int n)
{	
	cout << "STAMPO IL VETTORE: " << endl;
	for (int i=0; i<n; i++)
	{
		cout << "\tElemento " << i+1 << ": " << v[i] << endl;
	}
	cout << endl;
}

int sommaVettore(int v[], int n)
{
	int s = 0; 
	for (int i=0; i<n; i++)
		s += v[i];
	return s;
}

float sommaVettore(float v[], int n)
{
	float s = 0;
	for (int i=0; i<n; i++)
		s += v[i];
	return s;
}

float media(int v[], int n)
{
	return (float)sommaVettore(v,n) / n;
}

float media(float v[], int n)
{
	return sommaVettore(v,n) / n;
}

void ordinamentoIngenuo(int v[], int n, bool inverso = false)
{
	for (int i=0; i<n-1; i++)
		for (int j=i+1; j<n; j++)	
			if (!inverso && v[i] > v[j])
				swap(v[i], v[j]);
			else if (inverso && v[i] < v[j])
				swap(v[i], v[j]);
}

void ordinamentoIngenuo(float v[], int n, bool inverso = false)
{
	for (int i=0; i<n-1; i++)
		for (int j=i+1; j<n; j++)	
			if (!inverso && v[i] > v[j])
				swap(v[i], v[j]);
			else if (inverso && v[i] < v[j])
				swap(v[i], v[j]);
}

void bubbleSort(int v[], int n, bool inverso = false)
{
	bool ordinato = false;
	while (n != 1 && !ordinato)
	{
		ordinato = true;
		for (int i=0; i<n-1; i++)
		{
			if (v[i] > v[i+1] && !inverso) 
			{
				swap(v[i], v[i+1]);
				ordinato = false;
			} 
			else if (v[i] < v[i+1] && inverso)
			{
				swap(v[i], v[i+1]);
				ordinato = false;
			}
		}
		n--;
	}
}

void bubbleSort(float v[], int n, bool inverso = false)
{
	bool ordinato = false;
	while (n != 1 && !ordinato)
	{
		ordinato = true;
		for (int i=0; i<n-1; i++)
		{
			if (v[i] > v[i+1] && !inverso) 
			{
				swap(v[i], v[i+1]);
				ordinato = false;
			} 
			else if (v[i] < v[i+1] && inverso)
			{
				swap(v[i], v[i+1]);
				ordinato = false;
			}
		}
		n--;
	}
}

int ricercaBinaria(int v[], int n, int x)
{
	int inizio = 0, fine = n-1, medio;
	while (inizio <= fine)
	{
		medio = (inizio + fine) / 2;
		
		if (v[medio] == x)
			return medio;
			
		if (v[medio] > x)
			fine = medio - 1;
		else
			inizio = medio + 1;
	}
	
	return -1;
}

int ricercaBinaria(float v[], int n, int x)
{
	int inizio = 0, fine = n-1, medio;
	while (inizio <= fine)
	{
		medio = (inizio + fine) / 2;
		
		if (v[medio] == x)
			return medio;
			
		if (v[medio] > x)
			fine = medio - 1;
		else
			inizio = medio + 1;
	}
	
	return -1;
}

int presente(int v[], int n, int x)
{
	for (int i=0; i<n; i++)
		if (v[i] == x)
			return i;
			
	return -1;
}

int presente(float v[], int n, float x)
{
	for (int i=0; i<n; i++)
		if (v[i] == x)
			return i;
			
	return -1;
}

void inverti(int v[], int n)
{
	for (int i=0; i<n/2; i++)
		swap(v[i], v[n-i-1]);
}

void inverti(float v[], int n)
{
	for (int i=0; i<n/2; i++)
		swap(v[i], v[n-i-1]);
}

bool aggiungiElemento(float v[], int &n, int x)
{
	if (n == dimensione_max)
		return false;
		
	v[n++] = x;
	
	return true;
}

bool aggiungiElemento(int v[], int &n, int x)
{
	if (n == dimensione_max)
		return false;
		
	v[n++] = x;
	
	return true;
}

bool rimuoviElemento(float v[], int &n, int p)
{
	if (p >= n || p < 0)
		return false;
		
	for (int i=p; i<n-1; i++)
		v[i] = v[i+1];
		
	n--;
	
	return true;
}

bool rimuoviElemento(int v[], int &n, int p)
{
	if (p >= n || p < 0)
		return false;
		
	for (int i=p; i<n-1; i++)
		v[i] = v[i+1];
		
	n--;
	
	return true;
}

int minimo(int v[], int n)
{
	if (n == 0)
		return -1;
	
	return v[posizioneMinimo(v,n)];
}

float minimo(float v[], int n)
{
	if (n == 0)
		return -1;
	
	return v[posizioneMinimo(v,n)];
}

int massimo(int v[], int n)
{
	if (n == 0)
		return -1;
	
	return v[posizioneMassimo(v,n)];
}

float massimo(float v[], int n)
{
	if (n == 0)
		return -1;
	
	return v[posizioneMassimo(v,n)];
}

int posizioneMinimo(int v[], int n)
{
	if (n == 0)
		return -1;
		
	int im = 0;
		
	for (int i=0; i<n; i++)
		if (v[i] < v[im])
			im = i;
			
	return im;
}

int posizioneMinimo(float v[], int n)
{
	if (n == 0)
		return -1;
		
	int im = 0;
		
	for (int i=0; i<n; i++)
		if (v[i] < v[im])
			im = i;
			
	return im;
}

int posizioneMassimo(int v[], int n)
{
	if (n == 0)
		return -1;
		
	int im = 0;
		
	for (int i=0; i<n; i++)
		if (v[i] > v[im])
			im = i;
			
	return im;	
}

int posizioneMassimo(float v[], int n)
{
	if (n == 0)
		return -1;
		
	int im = 0;
		
	for (int i=0; i<n; i++)
		if (v[i] > v[im])
			im = i;
			
	return im;	
}
