<<<<<<< HEAD:0. program - array e matrici e vector.cpp
//libreria per input ed ouput
#include <iostream>
// libreria dei vector
#include <vector>

//utilizzo della libreria standard sempre per evitare std::cout
using namespace std;

//funzione principale che decreta l'inizio del programma
int main()
{
	//definizione del vector v con notazione a diamante <...>
	vector<int> v;
	//aggiunta di un elemento
	v.push_back(10);
	v.push_back(34);
	//funzione che mostra la lunghezza v.size()
	cout << "elemnti: " << v.size() << endl;
	
	// cout << v[0] == cout << v.at(0)
	for (int i=0; i<v.size(); i++)
	{
		cout << v[i] << " - ";
		cout << v.at(i) << endl;
	}
	
	//utilizzo degli iteratori/puntatori per la stampa dei vector senza distruggerli
	for (vector<int>::iterator p = v.begin(); p != v.end(); p++)
	{
		cout << "Elemento: " << *p << endl;
	}
	
	v.erase(v.begin()+1);
	
}
=======
//libreria per input ed ouput
#include <iostream>
// libreria dei vector
#include <vector>

//utilizzo della libreria standard sempre per evitare std::cout
using namespace std;

//funzione principale che decreta l'inizio del programma
int main()
{
	//definizione del vector v
	vector<int> v;
	//aggiunta di un elemento
	v.push_back(10);
	v.push_back(34);
	//funzione che mostra la lunghezza v.size()
	cout << "elemnti: " << v.size() << endl;
	
	// cout << v[0] == cout << v.at(0)
	for (int i=0; i<v.size(); i++)
	{
		cout << v[i] << " - ";
		cout << v.at(i) << endl;
	}
	
	//utilizzo degli iteratori/puntatori per la stampa dei vector senza distruggerli
	for (vector<int>::iterator p = v.begin(); p != v.end(); p++)
	{
		cout << "Elemento: " << *p << endl;
	}
	
	v.erase(v.begin()+1);
	
}
>>>>>>> ba43d71b83c6c1a82e5876301bcf6caa3ae136e2:0. program - vector.cpp
