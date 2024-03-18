#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

// input data
int W, H, X, Y, N;

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/5", "r", stdin);
	freopen("output/5", "w", stdout);
    
	assert(1 == scanf("%d", &W));
	assert(1 == scanf("%d", &H));
	assert(1 == scanf("%d", &X));
	assert(1 == scanf("%d", &Y));
	assert(1 == scanf("%d", &N));
	//controllo per debug: cout << W << " " << H << " " << X << " " << Y << " " << N << "\n";
	int MAPPA[W][H];
	char movimenti[2*N];

	//riempimento vettore dei movimenti
	for(int i=0; i<2*N; i++)
	{
		assert(1 == scanf("%c", &movimenti[i]));
		//controllo per dubug: cout << movimenti[i] << "-";
	}

	//inizializzazione matrice
	for(int i=0; i<W; i++)
	{
		for(int j=0; j<H; j++)
		{
			MAPPA[i][j] = 0;
		}
	}
	
	//segnare le caselle di passaggio
	for(int i=1; i<2*N+1; i++)
	{
		MAPPA[Y][X] = 1;
		
		//aggiornamento di X e Y
		if(int(movimenti[i]!=32))
		{
			if(int(movimenti[i]) == 78)
				Y -= 1;
			else if(int(movimenti[i]) == 83)
				Y += 1;
			else if(int(movimenti[i]) == 69)
				X += 1;
			else if(int(movimenti[i]) == 87)
				X -= 1;
			//controllo per debug: cout << "comando " << movimenti[i] << " risulta "<< "(" << X << " ; " << Y << ")" << endl;
		}
	}
	
	//stampa della mappa per colonne
	for(int i=0; i<W; i++)
	{
		for(int j=0; j<H; j++)
		{
			if (MAPPA[i][j] == 1)
				printf("%s", "[*]");
			else 
				printf("%s", "[ ]");
		}
		printf("\n", "");
	}
}
