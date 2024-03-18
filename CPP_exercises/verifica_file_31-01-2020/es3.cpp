#include <stdio.h>
#include <assert.h>
#include <cmath>
#include <iostream>
using namespace std;

// input data
int N;
float ivato, somma=0;

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/3", "r", stdin);
	freopen("output/3", "w", stdout);
	
	//input valori da file
    assert(1 == scanf("%d", &N));
    float C[3*N];
    for(int i=0; i<3*N; i++)
        cin >> C[i];
    
    //programma
    for(int i=0; i<3*N; i+=3)
    {
    	ivato = C[i+1] + (float(C[i+1]/100)*C[i+2]);
    	somma += C[i]*ivato;
	}
	//output su file
	printf("%d", int(somma));
    
}
