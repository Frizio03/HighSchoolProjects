#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 100000

// input data
int N, R=0;

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/4", "r", stdin);
	freopen("output/4", "w", stdout);

	//input da file
    assert(1 == scanf("%d", &N));
    int C[N];
    for(int i=0; i<N; i++)
        assert(1 == scanf("%d", &C[i]));
    
    //programma
    for(int i=1; i<N; i++)
    {
    	if(C[i-1]<C[i])
    		R++;
	}
	
	//output su file
		printf("%d ", R);
}
