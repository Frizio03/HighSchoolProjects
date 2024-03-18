#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

// input data
string C;
int i=0, count=0;

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/3", "r", stdin);
	freopen("output/3", "w", stdout);
    
    //metto ogni riga nella variabile fino a quando ce ne sono
    while(getline(cin, C)>0)
    {
		count++;
	}
	
	//stampa dell'output su file
	printf("%d", count);
}
