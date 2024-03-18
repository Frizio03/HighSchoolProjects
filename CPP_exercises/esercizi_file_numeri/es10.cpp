#include <stdio.h>
#include <assert.h>

// input data
int N;

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/10", "r", stdin);
	freopen("output/10", "w", stdout);

	//input valori da file
    assert(1 == scanf("%d", &N));
    int L[N];
    for(int i=0; i<N; i++)
        assert(1 == scanf("%d", &L[i]));
    
    //programma e stampa dei risultati
    for(int i=0; i<N; i++)
    {
    	printf("%d ", L[i]*L[i]);
	} 
}
