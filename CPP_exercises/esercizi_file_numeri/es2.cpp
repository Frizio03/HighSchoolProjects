#include <stdio.h>
#include <assert.h>

// input data
int N, risultato;

//funzioni necessarie
int minore(int v[], int n)
{
	int vmin=v[0];
	for (int i = 0; i < n; i++)
	{
		if (v[i]<vmin)
			vmin = v[i];
	}
	return vmin;
}

int maggiore(int v[], int n)
{
	int vmax=v[0];
	for (int i = 0; i < n; i++)
	{
		if (v[i]>vmax)
			vmax = v[i];
	}
	return vmax;
}

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/2", "r", stdin);
	freopen("output/2", "w", stdout);

	//input valori da file
    assert(1 == scanf("%d", &N));
    int C[N];
    for(int i=0; i<N; i++)
        assert(1 == scanf("%d", &C[i]));
    
    //programma
    risultato = maggiore(C, N) + minore(C, N);
    
    //Stampa del risultato sul file output
    printf("%d\n", risultato);
}
