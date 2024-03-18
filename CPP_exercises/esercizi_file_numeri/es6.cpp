#include <stdio.h>
#include <assert.h>

// input data
int N, K, somma, count=0, risultato;

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/6", "r", stdin);
	freopen("output/6", "w", stdout);
	
	//input di valori da file e dichiarazione vettore L
    assert(2 == scanf("%d %d", &N, &K));
    int L[N];
	for(int i=0; i<N; i++)
        assert(1 == scanf("%d", &L[i]));
    
    //programma
    for(int i=0; i<N; i++)
    {
    	if(L[i]>=K)
    	{
			somma += L[i];
			count +=1;
		}
	}
    
    risultato = somma/count;
    
    //Stampa del risultato sul file output
    printf("%d\n", risultato);
}
