#include <stdio.h>
#include <assert.h>

// input data
int N, risultato;

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/4", "r", stdin);
	freopen("output/4", "w", stdout);

	//input da file
    assert(1 == scanf("%d", &N));
    int C[N];
    for(int i=0; i<N; i++)
        assert(1 == scanf("%d", &C[i]));
    
    //programma con stampa del risultatp
    for(int i=0; i<N; i++)
    {
    	if(C[i]%2!=0)
			printf("%d ", C[i]);
	}
}
