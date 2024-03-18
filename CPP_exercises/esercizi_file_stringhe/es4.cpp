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
	freopen("input/4", "r", stdin);
	freopen("output/4", "w", stdout);
    
    //metto i valori della stringa in un vettore fino a quando scanf trova dei caratteri e restituisce 1
    while(scanf("%c", &C[i])>0)
    {
		i++;
	}
	
	for(int j=0; j<i; j++)
	{
		//controllo che il valore asci di ogni carattere non sia quello di una vocale
		if(int(C[j])==97 && int(C[j+1])==98 && int(C[j+2])==101 && int(C[j+3])==109 && int(C[j+4])==117 && int(C[j+5])==115)
    	{
    		//aggiorno un contatore per sapere il num di abemus
			count++;
		}
	}
	
	//stampa dell'output su file
	printf("%d", count);
}
