// Autore: Fabrizio Tedeschi
#include <iostream>
#include "mylib.h" //importo la mia libreria presente nella stessa cartella

using namespace std;

int main()
{
	int n=5, elem=15, VI[n];
	float elemf=32.32, VF[n];
	cout << random0N(100) << endl;
	cout << random0N_float(300);
	riempiVettoreRandom(VI, n);
	riempiVettoreRandom(VF, n);
	stampaVettore(VI, n);
	stampaVettore(VF, n);
	aggiungiElemento(VI, n, elem);
	aggiungiElemento(VF, n, elemf);
	n++;
	stampaVettore(VI, n);
	stampaVettore(VF, n);
	rimuoviElemento(VI, n, elem);
	rimuoviElemento(VF, n, elemf);
	n--;
	stampaVettore(VI, n);
	stampaVettore(VF, n);
	cout << "\nVETTORI ORDINATI CRESCENTE E DECRESCENTE:" << endl;
	//ordinamentoIngenuo(VI, n);
	//ordinamentoIngenuo(VF, n, true);
	bubbleSort(VI, n);
	bubbleSort(VF, n);
	stampaVettore(VI, n);
	stampaVettore(VF, n);
	cout << "\n----------------------------------------------------" << endl << endl;
	cout << "Somma vettore INT: " << sommaVettore(VI, n) << endl;
	cout << "Somma vettore FLOAT: " << sommaVettore(VF, n) << endl;
	cout << "Media vettore INT: " << media(VI, n) << endl;
	cout << "Media vettore FLOAT: " << media(VF, n) << endl;
	cout << "Maggiore degli INT: " << maggiore(VI, n) << " in indice: " << posizioneMaggiore(VI, n) << endl;
	cout << "Minore degli INT: " << minore(VI, n) << " in indice: " << posizioneMinore(VI, n) << endl;
	cout << "Maggiore dei FLOAT: " << maggiore(VF, n) << " in indice: " << posizioneMaggiore(VF, n) << endl;
	cout << "Minore dei FLOAT: " << minore(VF, n) << " in indice: " << posizioneMinore(VF, n) << endl;
	cout << "----------------------------------------------------" << endl << endl;
	ricercaBinaria(VI, n, 9);
	ricercaBinaria(VF, n, 99.18);
	cout << presente(VI, n, 7);
	cout << " // ";
	cout << presente(VF, n, 35.12);
}
