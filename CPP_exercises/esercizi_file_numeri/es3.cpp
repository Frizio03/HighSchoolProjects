#include <stdio.h>
#include <assert.h>

// input data
int N, risultato;

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/3", "r", stdin);
	freopen("output/3", "w", stdout);
	
	//input valori da file
    assert(1 == scanf("%d", &N));
    int C[N];
    for(int i=0; i<N; i++)
        assert(1 == scanf("%d", &C[i]));
    
    //programma
    for(int i=0; i<N; i++)
    {
    	if((C[i]%2)==0)
    		C[i] = C[i]/2;
    	else
    		C[i] = C[i]*2;
	}
    
    //Stampa del risultato sul file output
    //NOTA: è importante mettere uno spazio dopo %d e togliere /n
    for(int i=0; i<N; i++)
		printf("%d ", C[i]);
}
