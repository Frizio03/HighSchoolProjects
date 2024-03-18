#include <stdio.h>
#include <assert.h>

// input data
int N, risultato;

bool primo(int n)
{
	for(int j=2; j<n; j++)
	{
		if(n%j==0)
			return false;
	}
	return true;
}

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/8", "r", stdin);
	freopen("output/8", "w", stdout);

	//input valori da file
    assert(1 == scanf("%d", &N));
    int L[N];
    for(int i=0; i<N; i++)
        assert(1 == scanf("%d", &L[i]));
    
    //programma es tampa del risultato con aggiunta di " " dopo ogni numero
    for(int i=0; i<N; i++)
    {
		if(primo(L[i])==true)
			printf("%d ", 1);
		else
			printf("%d ", 0);
	}    
}
