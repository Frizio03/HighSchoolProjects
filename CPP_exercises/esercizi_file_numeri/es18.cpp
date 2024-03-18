#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 100000

// input data
int N, risultato=0;

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/18", "r", stdin);
	freopen("output/18", "w", stdout);

	//input da file
    assert(1 == scanf("%d", &N));
    int L[N];
    
    //input + programma + stampa su file
	for(int i=0; i<N; i++)
    {
    	for(int j=0; j<N; j++)
	    {
	    	assert(1 == scanf("%d", &L[j]));
			risultato += L[j];
		}
		//Stampa elemento della lista sul file output
		printf("%d ", risultato);
		risultato = 0;
	}
	
}
