#include <stdio.h>
#include <assert.h>

// input data
int N, K, risultato=1;


int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/7", "r", stdin);
	freopen("output/7", "w", stdout);
	
	//input variabili da file
    assert(2 == scanf("%d %d", &N, &K));
    int L[N];
	for(int i=0; i<N; i++)
        assert(1 == scanf("%d", &L[i]));
    
    //programma
    for(int i=0; i<N; i++)
    {
    	if(L[i]!=0 && L[i]!=K)
			risultato = risultato * L[i];
	}
    
    //Stampa del risultato sul file output
    printf("%d\n", risultato);
}
