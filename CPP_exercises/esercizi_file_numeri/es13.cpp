#include <stdio.h>
#include <assert.h>

// input data
int N, R;

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/13", "r", stdin);
	freopen("output/13", "w", stdout);
	
	//input valori da file
    assert(1 == scanf("%d", &N));
    int C[2*N];
    for(int i=0; i<2*N; i++)
        assert(1 == scanf("%d", &C[i]));
    
    //programma
    for(int i=0; i<2*N; i+=2)
    {
    	R = C[i] + C[i+1];
		//output su file
		printf("%d ", R);
	}
    
}
