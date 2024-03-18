#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 100000

// input data
int dati, risultato;
int C[MAXN];

int main() {
	//Apertura dei file necessari impostandoli come standard input e standard output
	freopen("input/esercizio.txt", "r", stdin);
	freopen("output/esercizio.txt", "w", stdout);

	//assegnazione di valori a variabile --> "%d" indica un decimale
	// con scanf si leggono i valori di un file SOLO IN FILA
	// assert controlla se i parametri restituiti da scanf sono corretti
    assert(2 == scanf("%d %d", &N, &M));
    //assegnazione dei valori al vettore (riempimento)
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &C[i]));
    
    //TESTO ESERCIZIO
    
    //Stampa del risultato sul file output
    printf("%d\n", risultato);
}
