/* 
	ESERCIZIO:
	
	Input: valore N e una lista L di N numeri
	Output: lista L senza i valori pari
	
	Esempio input:
	10
	1 2 3 4 5 -1 -2 -3 -4 -5	
	
	Esempio output:	
	1 3 5 -1 -3 -5

*/

#include <iostream>
#include <cmath>
#include <assert.h>

using namespace std;

bool test = false;

int main()
{
	if (!freopen(test ? "./input/test1.txt" : "./input/1", "r", stdin)) 
	{
		cout << "Errore nell'apertura dei file di input" << endl << "Sei nella cartella giusta?" << endl;
		system("pause");
		return 1;
	} else if (!test) {
		freopen("./output/1", "w", stdout);
	}
	
	int N;
	assert(1 == scanf("%d", &N));
    int C[N];
    for(int i=0; i<N; i++)
        assert(1 == scanf("%d", &C[i]));
    
    for(int i=0; i<N; i++)
    {
    	if(C[i]%2!=0)
    		printf("%d ", C[i]);
	}
}
