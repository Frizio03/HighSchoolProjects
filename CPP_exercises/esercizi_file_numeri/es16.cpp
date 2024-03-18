#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 100000

// input data
int N, count=0;

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/16", "r", stdin);
	freopen("output/16", "w", stdout);

	//input da file
    assert(1 == scanf("%d", &N));
    int L[N];
    for(int i=0; i<N; i++)
    	assert(1 == scanf("%d", &L[i]));

    //programma
    for(int i=0; i<N; i++)
    {
    	if(L[i]%5==0 && L[i]!=5)
    		count++;
	}
    
    //Stampa del vettore sul file output
	printf("%d ", count);
}
