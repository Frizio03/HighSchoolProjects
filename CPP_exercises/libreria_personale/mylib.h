//Autore: Fabrizio Tedeschi
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//**PROTOTIPI**
//Gestione random:
int randomNM(int n, int m);
float randomNM_float(int n, int m);
int random0N(int n);
float random0N_float(int n);
void setRandomMin(int min);
void setRandomMax(int max);
//Gestione vettore:
void setDimensioneMax(int x);
void riempiVettore(int v[], int n);
void riempiVettore(float v[], int n);
void riempiVettoreRandom(int v[], int n);
void riempiVettoreRandom(float v[], int n);
bool aggiungiElemento(int v[], int n, int x);
bool aggiungiElemento(float v[], int n, float x);
void rimuoviElemento(int v[], int n, int pos);
void rimuoviElemento(float v[], int n, int pos);
//Stampa del vettore
void stampaVettore(float v[], int n);
void stampaVettore(int v[], int n);
//Algoritmi dei vettori
void ordinamentoIngenuo(int v[], int n, bool inverso);
void ordinamentoIngenuo(int v[], int n, bool inverso);	
void bubbleSort(int v[], int n, bool inverso);
void bubbleSort(float v[], int n, bool inverso);
//Funzioni sui vettori
int sommaVettore(int v[], int n);
float sommaVettore(float v[], int n);
float media(int v[], int n);
float media(float v[], int n);
void inverti(int v[], int n);
void inverti(float v[], int n);
int ricercaBinaria(int v[], int n, int elemento);
int ricercaBinaria(float v[], int n, float elemento);
int presente(int v[], int n, int x);
int presente(float v[], int n, float x);
int minore(int v[], int n);
float minore(float v[], int n);
int maggiore(int v[], int n);
float maggiore(float v[], int n);
int posizioneMinore(int v[], int n);
int posizioneMinore(float v[], int n);
int posizioneMaggiore(int v[], int n);
int posizioneMaggiore(float v[], int n);

//DEFINIZIONE VARIABILI
bool random_inizializzato = false;
int random_min = 0, random_max = 100, len = 1000;

//**GESTIONE DEL RANDOM**

void setRandomMin(int min)
{
	random_min = min;
}

void setRandomMax(int max)
{
	random_max = max;
}

//funzioni random da 0 a max
int random0N(int n)
{
	if (random_inizializzato == false)
	{
		srand(time(NULL));
		random_inizializzato = true;
	}
	return rand() % n;
}

//funzione random da 0 a max
float random0N_float(int n)
{
	if (random_inizializzato == false)
	{
		srand(time(NULL));
		random_inizializzato = true;
	}
	int v1 = rand() % n;
	int v2 = rand() % 99;
	return (float)v1+((float)v2/100);
}

//funzione random int tra min e max
int randomNM(int n1, int n2)
{
	if (random_inizializzato == false)
	{
		srand(time(NULL));
		random_inizializzato = true;
	}
	return rand() % (n1-n2+1)+n1;
}

//funzione random float tra min e max
float randomNM_float(int n1, int n2)
{
	if (random_inizializzato == false)
	{
		srand(time(NULL));
		random_inizializzato = true;
	}
	int v1 = rand() % (n1-n2+1)+n1;
	int v2 = rand() % (0-99+1)+99;
	return (float)v1+((float)v2/100);
}

//funzione per scambiare 2 variabili int
void scambia_int(int &a, int &b)
{
	int box = a;
	a = b;
	b = box;
}

//funzione per scambiare 2 variabili float
void scambia_float(float &a, float &b)
{
	float box = a;
	a = b;
	b = box;
}

//**GESTIONE DEL VETTORE** (nota: n è la lunghezza logica del vettore mentre len quella fisica)

//settare dimensione massima del vettore
void setDimensioneMax(int x)
{
	len = x;
}

void riempiVettore(int v[], int n)
{
	for (int i=0; i<n; i++)
	{
		cout << "Inserisci elemento INT: ";
		cin >> v[i];
		cout << endl;
	}
}

void riempiVettore(float v[], int n)
{
	for (int i=0; i<n; i++)
	{
		cout << "Inserisci elemento FLOAT: ";
		cin >> v[i];
		cout << endl;
	}
}

//creazione di un vettore con elementi random int
void riempiVettoreRandom(int v[], int n)
{
	for (int i=0; i<n; i++)
	{
		v[i] = randomNM(random_min, random_max);
	}
}

//creazione di un vettore con elementi random float
void riempiVettoreRandom(float v[], int n)
{
	for (int i=0; i<n; i++)
	{
		v[i] = randomNM_float(random_min, random_max);
	}
}

//Aggiunge un elemento passato al vettore INT e ritorna true se possibile altrimenti ritorna false
bool aggiungiElemento(int v[], int n, int x=2)
{
	if (n == len)
	{
		return false;
	}
	else
	{
		v[n] = x;
		return true;
	}
}

//Aggiunge un elemento passato al vettore FLOAT e ritorna true se possibile altrimenti ritorna false
bool aggiungiElemento(float v[], int n, float x=2.2)
{
	if (n == len)
	{
		return false;
	}
	else
	{
		v[n] = x;
		return true;
	}
}

//elimina un elemento dal vettore int
void rimuoviElemento(int v[], int n, int pos)
{
	for (int i=pos; i<n; i++)
	{
		v[i] = v[i+1];
	}
	v[n-1] = 0;
}

//elimina un elemento dal vettore float
void rimuoviElemento(float v[], int n, int pos)
{
	for (int i=pos; i<n; i++)
	{
		v[i] = v[i+1];
	}
	v[n-1] = 0;
}

//**STAMPA DEL VETTORE**

//stampa il vettore di int
void stampaVettore(int v[], int n)
{
	cout << "\n" << "Il tuo vetore INT: [";
	for (int i=0; i<n; i++)
	{
		cout << " " << v[i] << ",";
	}
	cout << "]" << endl;
}

//stampa il vettore di float
void stampaVettore(float v[], int n)
{
	cout << "\n" << "Il tuo vetore Float: [";
	for (int i=0; i<n; i++)
	{
		cout << " " << v[i] << ",";
	}
	cout << "]" << endl;
}

//**ALGORITMI DEI VETTORI**

//ordinamento ingenuo di un vettore di int
void ordinamentoIngenuo(int v[], int n, bool inverso=false)
{
	if (inverso == false)
	{
		for (int i=0; i<n-1; i++)
		{
			for (int j=i+1; j<n; j++)
			{
				if (v[i]>v[j])
					scambia_int(v[i], v[j]);
			}
		}
	}
	else
		for (int i=0; i<n-1; i++)
		{
			for (int j=i+1; j<n; j++)
			{
				if (v[i]<v[j])
					scambia_int(v[i], v[j]);
			}
		}
}

//ordinamento ingenuo di un vettore di float
void ordinamentoIngenuo(float v[], int n, bool inverso=false)
{
	if (inverso == false)
	{
		for (int i=0; i<n-1; i++)
		{
			for (int j=i+1; j<n; j++)
			{
				if (v[i]>v[j])
					scambia_float(v[i], v[j]);
			}
		}
	}
	else
	{
		for (int i=0; i<n-1; i++)
		{
			for (int j=i+1; j<n; j++)
			{
				if (v[i]<v[j])
					scambia_float(v[i], v[j]);
			}
		}
	}
}

//Ordinamento per bubbleSort con SENTINELLA di int
void bubbleSort(int v[], int n, bool inverso=false) 
{ 
   if (inverso == false)
   {
	   bool ordinato; 
	   do { 
	     ordinato = false; 
	     for (int i = 0; i < n-1; i++) 
	     { 
	        if (v[i]>v[i+1]) 
	        { 
	           scambia_int(v[i], v[i+1]); 
	           ordinato = true; 
	        } 
	     } 
	  
	   }while(ordinato==true);
	}
   else
   {
	   bool ordinato; 
	   do { 
	     ordinato = false; 
	     for (int i = 0; i < n-1; i++) 
	     { 
	        if (v[i]<v[i+1]) 
	        { 
	           scambia_int(v[i], v[i+1]); 
	           ordinato = true; 
	        } 
	     } 
	  
	   }while(ordinato==true);
	}
}

//Ordinamento per bubbleSort con SENTINELLA di float
void bubbleSort(float v[], int n, bool inverso=false) 
{ 
   if (inverso == false)
   {
	   bool ordinato; 
	   do { 
	     ordinato = false; 
	     for (int i = 0; i < n-1; i++) 
	     { 
	        if (v[i]>v[i+1]) 
	        { 
	           scambia_float(v[i], v[i+1]); 
	           ordinato = true; 
	        } 
	     } 
	  
	   }while(ordinato==true);
	}
   else
   {
	   bool ordinato; 
	   do { 
	     ordinato = false; 
	     for (int i = 0; i < n-1; i++) 
	     { 
	        if (v[i]<v[i+1]) 
	        { 
	           scambia_float(v[i], v[i+1]); 
	           ordinato = true; 
	        } 
	     } 
	  
	   }while(ordinato==true);
	}
}

//**FUNZIONI SU ARRAY**

//somma tutti gli elementi del vettore int
int sommaVettore(int v[], int n)
{
	int somma=0;
	for (int i=0; i<n; i++)
	{
		somma += v[i];
	}
	return somma;
}

//somma tutti gli elementi del vettore float
float sommaVettore(float v[], int n)
{
	float somma=0;
	for (int i=0; i<n; i++)
	{
		somma += v[i];
	}
	return somma;
}

//restituisce la media degli elementi del vettore int
float media(int v[], int n)
{
	int somma = sommaVettore(v, n);
	return (float)somma/n;
}

//restituisce la media degli elementi del vettore float
float media(float v[], int n)
{
	float somma = sommaVettore(v, n);
	return somma/n;
}

//gira al contrario un vettore di int
void inverti(int v[], int n)
{
	int mezzo=n/2;
	for (int i=0; i<mezzo; i++)
	{
		scambia_int(v[i], v[n-i-1]);
	}
}

// gira al contarrio un vettore di float
void inverti(float v[], int n)
{
	int mezzo=n/2;
	for (int i=0; i<mezzo; i++)
	{
		scambia_float(v[i], v[n-i-1]);
	}
}

// ricerca elemento all'interno di un vettore di INT ordinato
int ricercaBinaria(int v[], int n, int elemento)
{
	int count=1, i=0, f=n-1, m;
	while(i<=f)
	{
		m = (i+f)/2;
		if (v[m] > elemento)
			f = m - 1;
		else if (v[m] < elemento)
			i = m + 1;
		else if (v[m] == elemento)
		{
			cout << "Il numero " << elemento << " trovato in " << count << " passaggi" << endl;
			return m;
		}
		count += 1;
	}
	
	cout << "Il numero " << elemento << " NON viene trovato nel vettore" << endl;
	return -1;
}

// ricerca elemento all'interno di un vettore di FLOAT ordinato
int ricercaBinaria(float v[], int n, float elemento)
{
	int count=1, i=0, f=n-1, m;
	while(i<=f)
	{
		m = (i+f)/2;
		if (v[m] > elemento)
			f = m - 1;
		else if (v[m] < elemento)
			i = m + 1;
		else if (v[m] == elemento)
		{
			cout << "Il numero " << elemento << " trovato in " << count << " passaggi" << endl;
			return m;
		}
		count += 1;
	}
	
	cout << "Il numero " << elemento << " NON viene trovato nel vettore" << endl;
	return -1;
}

// restituisce l'indice dell'elemento INT se presente altrimenti restituisce -1
int presente(int v[], int n, int elem)
{
	for (int i=0; i<n; i++)
	{
		if (v[i]==elem)
		{
			return i;
		}
	}
	return -1;
}

// restituisce l'indice dell'elemento FLOAT se presente altrimenti restituisce -1
int presente(float v[], int n, float elem)
{
	for (int i=0; i<n; i++)
	{
		if (v[i]==elem)
		{
			return i;
		}
	}
	return -1;
}

//resituisce il numero maggiore di un vettore int
int minore(int v[], int n)
{
	int vmin=v[0];
	for (int i = 0; i < n; i++)
	{
		if (v[i]<vmin)
			vmin = v[i];
	}
	return vmin;
}

//resituisce il numero maggiore di un vettore float
float minore(float v[], int n)
{
	float vmin=v[0];
	for (int i = 0; i < n; i++)
	{
		if (v[i]<vmin)
			vmin = v[i];
	}
	return vmin;
}

//resituisce il numero maggiore di un vettore int
int maggiore(int v[], int n)
{
	int vmax=v[0];
	for (int i = 0; i < n; i++)
	{
		if (v[i]>vmax)
			vmax = v[i];
	}
	return vmax;
}

//resituisce il numero maggiore di un vettore float
float maggiore(float v[], int n)
{
	float vmax=v[0];
	for (int i = 0; i < n; i++)
	{
		if (v[i]>vmax)
			vmax = v[i];
	}
	return vmax;
}

//resituisce l'indice del numero maggiore di un vettore int
int posizioneMaggiore(int v[], int n)
{
	int vmax=v[0], index=0;
	for (int i = 0; i < n; i++)
	{
		if (v[i]>vmax)
		{
			vmax = v[i];
			index=i;
		}
	}
	return index;
}

//resituisce l'indice del numero maggiore di un vettore float
int posizioneMaggiore(float v[], int n)
{
	float vmax=v[0];
	int index=0;
	for (int i = 0; i < n; i++)
	{
		if (v[i]>vmax)
		{
			vmax = v[i];
			index=i;
		}
	}
	return index;
}

//resituisce l'indice del numero minore di un vettore int
int posizioneMinore(int v[], int n)
{
	int vmin=v[0], index=0;
	for (int i = 0; i < n; i++)
	{
		if (v[i]<vmin)
		{
			vmin = v[i];
			index=i;
		}
	}
	return index;
}

//resituisce l'indice del numero minore di un vettore float
int posizioneMinore(float v[], int n)
{
	float vmin=v[0];
	int index=0;
	for (int i = 0; i < n; i++)
	{
		if (v[i]<vmin)
		{
			vmin = v[i];
			index=i;
		}
	}
	return index;
}
