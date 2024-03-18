#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

// input data
int N;

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/9", "r", stdin);
	freopen("output/9", "w", stdout);

	//input valori da file
    assert(1 == scanf("%d", &N));
    int L[N];
    for(int i=0; i<N; i++)
        assert(1 == scanf("%d", &L[i]));
    
    //programma e stampa dei valori
	for(int i=0; i<N; i++)
	{
		for(int j=1; j<=L[i]; j++)
		{
			if(L[i]%j==0)
				cout << j << " ";
		}
		cout << endl;
	}
}
