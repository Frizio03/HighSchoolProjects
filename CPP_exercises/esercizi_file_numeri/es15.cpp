#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 100000

// input data
int N, a=0, b=0, c=0, somma=0;

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/15", "r", stdin);
	freopen("output/15", "w", stdout);

	//input da file
    assert(1 == scanf("%d", &N));
    int C[N];
    int R[N];
        
    //programma
    for(int i=0; i<N; i++)
    {
    	assert(1 == scanf("%d", &a));
    	assert(1 == scanf("%d", &b));
    	assert(1 == scanf("%d", &c));
    	//Oppure assert(3 == scanf("%d", "%d", "%d", &a, &b, &c));
    	//metto la media dei tre valori in un vettore
		somma = a + b + c;
		R[i] = int(somma/3);
	}
    
    //Stampa del vettore sul file output
    for(int i=0; i<N; i++)
		printf("%d ", R[i]);
}
