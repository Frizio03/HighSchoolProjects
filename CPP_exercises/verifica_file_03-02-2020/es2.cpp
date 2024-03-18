/* 
	ESERCIZIO:
	
	Input: valore N, valore K e una lista L di N numeri
	Output: numero di valori della lista multipli di K

	Esempio input:
	7 3
	10 12 -3 2 1 2 30
	
	Esempio output: 
	3
*/

#include <iostream>
#include <cmath>
#include <assert.h>

using namespace std;

bool test = false;

int main()
{
	if (!freopen(test ? "./input/test2.txt" : "./input/2", "r", stdin)) 
	{
		cout << "Errore nell'apertura dei file di input" << endl << "Sei nella cartella giusta?" << endl;
		system("pause");
		return 1;
	} else if (!test) {
		freopen("./output/2", "w", stdout);
	}
	
	int N, K, valori=0;
	assert(1 == scanf("%d", &N));
	assert(1 == scanf("%d", &K));
    int C[N];
    for(int i=0; i<N; i++)
        assert(1 == scanf("%d", &C[i]));
    
    for(int i=0; i<N; i++)
    {
    	if(C[i]%K==0)
    		valori++;
	}
	printf("%d ", valori);
}
