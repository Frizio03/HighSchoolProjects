/* 
	ESERCIZIO:
	
	Input: valore N seguito da una lista di N coppie rappresentanti delle coordinate
	Output: la distanza (calcolata dall'origine) maggiore dei punti [troncato ad un intero]

	Esempio input:
	4
	0 10
	14 0
	8 8
	10 12
	
	Esempio output: 
	15
*/

#include <iostream>
#include <cmath>
#include <assert.h>

using namespace std;

bool test = true;

int main()
{
	if (!freopen(test ? "./input/test3.txt" : "./input/3", "r", stdin)) 
	{
		cout << "Errore nell'apertura dei file di input" << endl << "Sei nella cartella giusta?" << endl;
		system("pause");
		return 1;
	} else if (!test) {
		freopen("./output/3", "w", stdout);
	}

	int N, R, maggiore=0;
	assert(1 == scanf("%d", &N));
    int C[2*N];
    for(int i=0; i<2*N; i++)
        assert(1 == scanf("%d", &C[i]));
    
    //programma
    for(int i=0; i<2*N; i+=2)
    {
    	R = sqrt( C[i]*C[i] + C[i+1]*C[i+1] );
		if(R>maggiore)
			maggiore=R;
		R=0;
	}
	printf("%d", int(maggiore));
}
