#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

// input data
int N, risultato;
char C[10000], L[0000];
int i=0, count=0;

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/2", "r", stdin);
	freopen("output/2", "w", stdout);
    
    while(scanf("%c", &C[i])>0)
    {
		if(int(C[i])!=32)
    	{
    		i++;
		} 
	}
	
	printf("%d", i);
}
