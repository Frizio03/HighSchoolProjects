/* 
	ESERCIZIO:
	
	Input: valore N seguito da una lista di N triple (3 valori consecutivi a b c)
	Output: per ogni tripla dire quante triple sono ordinate in senso strettamente crescente (a < b < c)	
	
	Esempio input:
	5
	1 2 3
	2 3 -1
	-2 3 4
	0 0 0
	3 4 100
	
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
	if (!freopen(test ? "./input/test5.txt" : "./input/5", "r", stdin)) 
	{
		cout << "Errore nell'apertura dei file di input" << endl << "Sei nella cartella giusta?" << endl;
		system("pause");
		return 1;
	} else if (!test) {
		freopen("./output/5", "w", stdout);
	}

	int N, R=0;
	assert(1 == scanf("%d", &N));
    int C[3*N];
    for(int i=0; i<3*N; i++)
        assert(1 == scanf("%d", &C[i]));
    
    for(int i=0; i<3*N; i+=3)
    {
    	if(C[i]<C[i+1] && C[i+1]<C[i+2])
    		R++;
	}
    printf("%d", R);
}
