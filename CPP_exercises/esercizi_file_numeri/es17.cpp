#include <stdio.h>
#include <assert.h>

// input data
int N, count=0;

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/17", "r", stdin);
	freopen("output/17", "w", stdout);
	
	//input valori da file
    assert(1 == scanf("%d", &N));
    int C[5*N], R[N];
    for(int i=0; i<5*N; i++)
        assert(1 == scanf("%d", &C[i]));
    
    //programma
    for(int i=0; i<5*N; i+=5)
    {
    	R[count] = (C[i]*C[i+1])-(C[i+2]*C[i+3])+C[i+4];
    	count++;

	}
	
	//output su file
	for(int i=0; i<N; i++)
		printf("%d ", R[i]);
    
}
