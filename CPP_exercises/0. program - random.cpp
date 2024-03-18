#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// PROTOTIPI
int random0N(int n);
int randomNM(int n, int m);

int main()
{
<<<<<<< HEAD
	//inizializzazione dei secondi dal 01/01/1974
	srand(time (NULL));
	
	//random tra 0 e un numero n
	int n = 50;
	cout << "Random normale da 0 a max: "<< rand() % (n+1) << endl;
=======
	// "Scuoto un sacchetto contenente dei numeri random", con seme generatore time(NULL), 
	// ossia il numero di secondi trascorsi dal 01/01/1970
	srand(time(NULL)); 
>>>>>>> ba43d71b83c6c1a82e5876301bcf6caa3ae136e2
	
	//stampo 20 numeri random commpresi tra -100 e 100
	for (int i=0; i<20; i++)
		cout << randomNM(-100, 100) << endl;
		
	return 0;
}

//dato un valore N restituisce un valore random compreso tra 0 ed N
int random0N(int n)
{
	// o in alternativa --> randomNM(0, n)
	int numeroRandom = rand() % (n + 1);
	return numeroRandom;
}

//dato un valore N restituisce un valore random compreso tra N ed M
int randomNM(int min, int max)
{
	int numeroRandom = rand() % (max - min + 1) + min;
	return numeroRandom;
}
