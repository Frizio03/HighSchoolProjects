//libreria per input ed ouput
#include <iostream>

//utilizzo della libreria standard sempre per evitare std::cout
using namespace std;

// definizione variabili
int x=0;
int y=1;
string s = "";

/*definizione puntatori
	* --> deferenziatore --> mostra il valore di una variabile
	& --> referenziatore --> mostra l'indirizzo di una variabile
*/
int *px = &x;	//puntatore p su indirizzo memoria x
int *px2 = px;	//puntamento di un puntatore --> i due puntatori puntano la stessa variabile

// definizione funzioni
void scambia(int &a, int &b) //si usa & per evitare di distruggere le variabili
{
	int t = a;
	a = b;
	b = t;
}

//funzione principale che decreta l'inizio del programma
int main()
{
	//istruzione di output con endl = \n
	cout << "Hello World" << endl;
	
	//restituisce quanti byte occupa un tipo di variabile
	cout << sizeof(long long) << "Byte" << endl;
	
	//istruzione di input
	cout << "Input variabile x: ";
	cin >> x;
	cout << "x = " << x << "\n";
	
	//fermare un momento il programma e poi premere INVIO
	system("pause");

	//Ciclo if
	if (x % 2 == 0)
	{
		cout << "Il numero" << x << "è pari" << endl;
	}
	else
	{
		cout << "Il numero" << x << "è dispari" << endl;
	}

	//output puntatori
	cout << "\nmostro l'indirizzo di x: " << &x << endl;
	cout << "mostro il valore di px: " << px << endl;
	cout << "mostro il valore di x: " << x << endl;
	cout << "mostro il valore puntato da px: " << *px << endl;
	cout << "mostro l'indirizzo della variabile puntata da px (=px)': " << &(*px) << endl;
	cout << "mostro l'indirizzo di px: " << &px << endl;
	cout << "mostro il valore puntato da px2: " << *px2 << endl;
	
	//utilizzo puntatori per modifica variabili
	*px = 20;

	//utilizzo della funzione
	scambia(x, y);
	cout << x << " - " << y;

	//Per migliorare la sintassi poichè una funzione
	//ritorna sempre qualcosa
	return 0;
}
