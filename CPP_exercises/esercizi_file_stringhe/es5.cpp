#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

// input data
string C[10000], L[10000];
int i=0, count=0;

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/5", "r", stdin);
	freopen("output/5", "w", stdout);
    
    //metto ogni riga nella variabile fino a quando ce ne sono
    while(getline(cin, C[i])>0)
    {
		if(int(C[i][1])!=47)
		{
			L[count] = C[i];
			count++;
		}
		else
		{
			if(int(C[i][0])!=47)
			{
				L[count] = C[i];
				count++;
			}
		}
		i++;
	}
	
	//stampa dell'output su file
	for(i=0; i<count; i++)
		cout << L[i] << endl;
}
