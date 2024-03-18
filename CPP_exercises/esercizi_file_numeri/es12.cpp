#include <stdio.h>
#include <assert.h>

// input data
int N, risultato;

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/12", "r", stdin);
	freopen("output/12", "w", stdout);

	//input valori da file
    assert(1 == scanf("%d", &N));
    int C[N];
    for(int i=0; i<N; i++)
        assert(1 == scanf("%d", &C[i]));
    
    //programma
    for(int i=0; i<N; i++)
    {
    	if(C[i]%2==0)
    		C[i] += 1;
    	else
    		C[i] -= 1;
	}
	
    //Stampa del risultato sul file output
    for(int i=0; i<N; i++)
		printf("%d ", C[i]);
}
