#include <stdio.h>
#include <assert.h>

// input data
int N, M, s;

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/14", "r", stdin);
	freopen("output/14", "w", stdout);

	//input da file
    assert(1 == scanf("%d", &N));
    int R=0;
    for(int i=0; i<N; i++)
	{
    	assert(1 == scanf("%d", &M));
        for(int j=0; j<M; j++)
    	{
    		assert(1 == scanf("%d", &s));
			R += s;
		}
	}
	
    //stampa del risultato
	printf("%d ", R);
}
