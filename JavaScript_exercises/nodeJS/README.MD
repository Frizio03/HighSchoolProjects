# Contenuto repository:
- Come avviare un progetto di node js
- Conoscere il file "package.json"
- Librerie e cartella node_modules
- Libreria node-fetch https://www.npmjs.com/package/node-fetch
- Servizi di fake-api: https://jsonplaceholder.typicode.com/

*Avviare un progetto in nodeJS*
1. Creare la cartella del prgetto senza spazi nel nome
2. Digitare su terminale il seguente comando
```sh
$ npm init
$ npm init -y
```
con flag -y per completamento automatico: sarà creato il file "package.json" con tutte le informazioni sul progetto

*Installare le librerie*
1. Eseguire il comando _npm install "nomeLibreria"_
2. La libreria viene installata nella nuova cartella node_modules

*Il file package.json*
>Si tratta di un file nel quale vengono salvate tutte le info del progetto di nodeJS come ad esempio nome, versione e librerie utili.
Se si scarica un progetto di node da GitHub non è necessario controllare quali librerie sono necessarie ma è sufficiente eseguire il comando _npm install_ e verranno installate le librerie presenti nel suddetto file all'ultima versione.

*Il file package-lock.json*
>Questo file contiene i nomi delle librerie e la versione di esse al momento della creazione del progetto e funge da file di backup dei dati originali al momento della creazione del progetto.

*Avviare il main file di un progetto*
>Se non si conosce il nome preciso del file principale di un progetto scaricato sarà possibile avviarlo comunque sempre grazie al file package.json eseguendo su terminale il seguente comando:
```sh
$ npm start
```
NB: il comando start deve essere impostato dal creatore nel file pakage.json inserendo sotto la voce _scripts_ la seguente riga di codice:

```sh
"start": "node nomeMainFile.js"
```

*I json: JavaScript Object Notation*
>Sono file che contengono stringhe o semplici stringhe che vengono trasmesse online.
>A seguito di opportune operazioni (PARSING) da parte di un programma possono essere convertiti in struture dati chiave-valore con le quali operare e da cui estrarre dati.
```sh
//Parsing di una stringa e conversione in json
.then(res => res.json())
```

*I servizi di fake-API*
>Tali servizi trasmettono dei dati sotto forma di json usufruibili da un programma (dopo averli richiesti tramire node-fetch)
