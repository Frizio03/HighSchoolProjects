1// Autori Fabrizio Tedeschi, Gianluca Ghinazzi, Matteo Morellini
#include <iostream> // libreria principale
#include <string> // libreria delle stringhe
#include <fstream> // libreria per lavorare con i file
#include <list>
#include <sstream>

using namespace std;

// definizione di funzioni utili
	
int main()
{
	//definizione variabili, stringhe e liste
	int comando=0, contatore=0, ricerca=0;
	string nome, cognome, ccognome, numero, risposta, posizione;
	//preparazione delle liste
	list<string> Numero;
	list<string> Nome;
	list<string> Cognome;
	Cognome.push_back("COGNOME");
	Nome.push_back("NOME");
	Numero.push_back("NUMERO\n");
	
	//stampa del menù principale
	while(comando !=5)
	{
		cout << "\nRUBRICA TELEFONICA\n";
		cout << "\n";
		cout << "comandi disponibili:\n";
		cout << "	1. Crea contatto\n";
		cout << "	2. Cerca contato\n";
		cout << "	3. Elimina contato\n";
		cout << "	4. Stampa nuovamente lista dei contatti\n";
		cout << "	5. Esci dalla rubrica e chiudi il programma\n";
		cout << "\n";
		cout << "Inserisci qui il tuo comando: ";
		cin >> comando;
		
		//realizzazione opzione scelta
		//Aggiungere un nuovo contatto
			if (comando == 1) {
			system("cls");
			ofstream salva;
				
				cout<<"Cognome del nuovo contatto: ";
				cin>>cognome;
				Cognome.push_back(cognome);
				
				cout<<"Nome del nuovo contatto: ";
				cin>>nome;
				Nome.push_back(nome);
				
				cout<<"Numero del nuovo contatto: ";
				cin>>numero;
				Numero.push_back(numero);
				
				salva.open("rubrica.txt",ios::app);
				salva<<cognome<<" ";
				salva<<nome<<" ";
				salva<<numero<<"\n";
				salva.close();
				system("cls");
				}
			//cercare un contatto
			if (comando == 2) {
				system("cls");
				cout<<"Inserisci il cognome da cercare: ";
				cin>>ccognome;
				list<string>::iterator it_cognome = Cognome.begin();
				list<string>::iterator it_nome = Nome.begin();
				list<string>::iterator it_numero = Numero.begin();
				for (int i = 0; i != Cognome.size(); i++){
					if (ccognome == *it_cognome){
						cout << *it_cognome << "  " << *it_nome << "  " << *it_numero << endl;
					};
					it_cognome++;
        			it_nome++;
        			it_numero++;
				};
			};
			if (comando == 3) {
				system("cls");
				cout<<"Inserire POSIZIONE del contatto da eliminare: ";
				cin>>posizione;
				stringstream str(posizione); 
    			int x = 0; 
    			str >> x; 
    			if (x != 0){
    				list<string>::iterator it = Cognome.begin();
    				advance(it, x);
        			Cognome.erase(it);
        			Nome.erase(it);
        			Numero.erase(it);
        			system("cls");
				}
				else {
					cout << "\n\nERRORE: impossibile eliminare il contatto 0\n\n";
				}
			};
			if (comando == 4) {
				system("cls");
				list<string>::iterator it_cognome = Cognome.begin();
				list<string>::iterator it_nome = Nome.begin();
				list<string>::iterator it_numero = Numero.begin();
				for (int i = 0; i != Cognome.size(); i++){
        		cout << i << ") " << *it_cognome << "  " << *it_nome << "  " << *it_numero << endl;
        		it_cognome++;
        		it_nome++;
        		it_numero++;
        		}
        		cout << endl << endl;
			};
		};
	};
