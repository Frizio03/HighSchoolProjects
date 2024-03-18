# GAF - SmartBanking
Il progetto si propone di realizzare un software di smart banking usufruibile da terminale e collegato ad un database con file .csv

## Scopo e finalità future del progetto
Comprendere e realizzare in semplice un applicativo su diversi livelli (software e database)

## Istruzioni di avvio

    $ pip install termcolor
    $ pip install Faker
    $ pip install time
    $ python main.py
   

## Componenti

- **DataBase**:  basato su file di tipo .csv con campi separati da virgole;
- **Software**:  realizzato in linguaggio python. Le funzioni sono su file separati e vengono importate dal programma main.py che viene avviato;
- **Libreria Faker**:  genera dati casuali per testare e riempire il database;
- **Libreria termcolor**:  rende l'aspetto del programma da terminale maggiormente userFriendly

## Creators

**Fabrizio Tedeschi**, Classe 5FS
> Stesura codice delle varie funzioni che utilizza il programma. Gestione consensi utente e livelli di accesso tramite psw. Ottimizzazione.

**Alex Foderaro**, Classe 5FS
> Unione del codice in un unico programma e import delle funzioni. Struttura menu del programma.

**Gianluca Ghinazzi**, Classe 5FS
> Gestione della grafica, dei colori e delle funzioni di print(). Sviluppo generatore password.

## Linguaggi utilizzati
Python 3, CSV
