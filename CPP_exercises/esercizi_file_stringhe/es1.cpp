#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

// input data
int N, risultato;
char C[10000], L[10000];
int i=0, count=0;

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/1", "r", stdin);
	freopen("output/1", "w", stdout);
    
    //metto i valori della stringa in un vettore fino a quando scanf trova dei caratteri e restituisce 1
    while(scanf("%c", &C[i])>0)
    {
    	//controllo che il valore asci di ogni carattere non sia quello di una vocale
		if(int(C[i])!=97 && int(C[i])!=101 && int(C[i])!=105 && int(C[i])!=111 && int(C[i])!=117 && int(C[i])!=121)
    	{
    		L[count] = C[i];
    		//aggiorno un contatore per sapere la lunghezza di L
			count++;
		}
		i++; 
	}
	
	//stampa dell'output su file
	for(i=0; i<count; i++)
	{
		printf("%c", L[i]);
	}
}
