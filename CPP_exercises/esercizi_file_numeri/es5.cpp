#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

// input data
int N, risultato;
string Mesi[] = {"gennaio", "febbraio", "marzo", "aprile", "maggio", "giugno", "luglio", "agosto", "settembre", "ottobre", "novembre", "dicembre"};

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/5", "r", stdin);
	freopen("output/5", "w", stdout);

	//input di valori da file
    assert(1 == scanf("%d", &N));
    int C[N];
    for(int i=0; i<N; i++)
        assert(1 == scanf("%d", &C[i]));
    
    //programma con stampa del risultato
    for(int i=0; i<N; i++)
    {
    	risultato = C[i];
		//è necessario aggiungere lo spazio " " dopo ogni valore per lettura agent
		cout << Mesi[risultato-1] << " ";
	}
    
    
}
