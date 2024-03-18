#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 100000

// input data
int N, risultato;

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/1", "r", stdin);
	freopen("output/1", "w", stdout);

	//input da file
    assert(1 == scanf("%d", &N));
    int C[N];
    for(int i=0; i<N; i++)
        assert(1 == scanf("%d", &C[i]));
    
    //programma
    for(int i=N-1; i>=0; i--)
    {
    	printf("%d ", C[i]);
	}
    
    //Stampa del risultato sul file output
    
}
