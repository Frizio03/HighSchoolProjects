#include <stdio.h>
#include <assert.h>
#include <cmath>
// input data
int N, R;

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/2", "r", stdin);
	freopen("output/2", "w", stdout);
	
	//input valori da file
    assert(1 == scanf("%d", &N));
    int C[4*N];
    for(int i=0; i<4*N; i++)
        assert(1 == scanf("%d", &C[i]));
    
    //programma
    for(int i=0; i<4*N; i+=4)
    {
    	R = sqrt(pow(C[i]-C[i+2], 2)+pow(C[i+1]-C[i+3], 2));
		//output su file
		printf("%d ", int(R));
		R=0;
	}
    
}
