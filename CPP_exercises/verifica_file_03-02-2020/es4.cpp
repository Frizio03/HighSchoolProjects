/* 
	ESERCIZIO:
	
	Input: valore N seguito da una lista di N quintuple (5 valori consecutivi a b c d e)
	Output: per ogni quintupla stampare il risultato a + b*e - c*d	
	
	Esempio input: 
	3
	1 2 3 4 5 
	-2 3 1 5 3
	0 1 2 0 3
	
	Esempio output: 
	-1 2 3

*/

#include <iostream>
#include <cmath>
#include <assert.h>

using namespace std;

bool test = false;

int main()
{
	if (!freopen(test ? "./input/test4.txt" : "./input/4", "r", stdin)) 
	{
		cout << "Errore nell'apertura dei file di input" << endl << "Sei nella cartella giusta?" << endl;
		system("pause");
		return 1;
	} else if (!test) {
		freopen("./output/4", "w", stdout);
	}
	
	int N, R=0;
	assert(1 == scanf("%d", &N));
    int C[5*N];
    for(int i=0; i<5*N; i++)
        assert(1 == scanf("%d", &C[i]));
    
    for(int i=0; i<5*N; i+=5)
    {
    	R = C[i] + C[i+1]*C[i+4] - C[i+2]*C[i+3];
    	printf("%d ", R);
	}
    
}
