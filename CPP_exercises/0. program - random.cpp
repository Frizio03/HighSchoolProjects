#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// PROTOTIPI
int random0N(int n);
int randomNM(int n, int m);

int main()
{
	// "Scuoto un sacchetto contenente dei numeri random", con seme generatore time(NULL), 
	//Inizializzazione dei secondi dal 01/01/1974
	srand(time(NULL));

	//Stampo 20 numeri random commpresi tra 0 e 50
	for (int i=0; i<20; i++)
		cout << random0M(50) << endl;
	
	//Stampo 20 numeri random commpresi tra -100 e 100
	for (int i=0; i<20; i++)
		cout << randomNM(-100, 100) << endl;
		
	return 0;
}

//Dato un valore N restituisce un valore random compreso tra 0 ed N
int random0N(int n)
{
	// o in alternativa --> randomNM(0, n)
	int numeroRandom = rand() % (n + 1);
	return numeroRandom;
}

//Dato un valore N restituisce un valore random compreso tra N ed M
int randomNM(int min, int max)
{
	int numeroRandom = rand() % (max - min + 1) + min;
	return numeroRandom;
}
