#Importazione librerie
import csv
import datetime
import os
from termcolor import colored
from faker import Faker
fake = Faker()
from random import randint
from generator import generaPSW

#Variabili globali
logged = False
logged = {"Name": "Thomas", "lastname": "Martinez", "id_conto": 0}
comando = 0

#Funzioni di accesso area personale
def login(anagrafica):
	logged_user_data = {"Name": "", "lastname": "", "id_conto": ""}

	print(colored("---- PROCEDURA DI LOGIN ----", "blue"))
	firstname = input("   Inserisci il tuo nome: ")
	lastname = input("   Inserisci il tuo cognome: ")
	id_conto = int(input("   Inserisci ID del tuo conto: "))
	psw = input("   Inserisci PASSWORD: ")
	#print(anagrafica["rows"][0])
	
	user = []
	for row in anagrafica["rows"]:
		if int(row[2]) == id_conto:
			user = row
			break

	if user[0] == (firstname) and user[1] == (" "+lastname) and int(user[2]) == id_conto and user[3] == (" "+psw):
		print(colored("Login EFFETTUATO", "green"))
		logged = True
		logged_user_data["Name"] = firstname
		logged_user_data["lastname"] = lastname
		logged_user_data["id_conto"] = id_conto
		return logged_user_data
	else:
		print(colored("Login NON RIUSCITO: RITENTARE", "red"))
		return False

def logout():
	logged = False

#Funzione dei file di DB
def readcsvFile(fileName):
    rows = []
    with open(fileName, "r") as file:
        csvreader = csv.reader(file)
        header = next(csvreader)
        #header.pop(3)
        #print(header)
        for row in csvreader:
            #row.pop(3)
            rows.append(row)
            #print(row[1])
    

    return {
        "header": header,
        "rows": rows
    }

def savecsvFile(fileName, mod, header, data):
	with open(fileName, mod) as file:
	    for value in header:
	        file.write(str(value)+', ')
	    file.write('\n')
	    for row in data:
	        for x in row:
	            file.write(str(row[x])+', ')
	        file.write('\n')

def savecsvFile_bis(fileName, mod, header, data):
	with open(fileName, mod) as file:
	    for value in header:
	        file.write(str(value)+', ')
	    file.write('\n')
	    for row in data:
	        for x in row:
	            file.write(str(x)+', ')
	        file.write('\n')

def updatecsvFile(fileName, mod, data):
	with open(fileName, mod) as file:
	    for row in data:
	        for x in row:
	            file.write(str(x)+', ')
	        file.write('\n')

#FUNZIONI PROGRAMMA
def generate_DB():

    #definizione struct
    saldoConti = {
        "header": ["idConto", "Saldo", "timestamp"],
        "rows": []
    }

    listaMovimenti = {
        "header": ["idConto", "importo", "timestamp"],
        "rows": []
    }

    anagrafica = {
        "header": ["Nome", "Cognome", "idConto", "Password"],
        "rows": []  
    }

    #Generazione dati struct
    for i in range(0, 10):
        row = {
            "Nome": fake.name().split(" ")[0],
            "Cognome": fake.name().split(" ")[1],
            "idConto": i,
            "Password": "Pippopippo"
        }
        anagrafica["rows"].append(row)

    for i in range(0, 10):
        row = {
            "idConto": randint(0, 10),
            "importo": randint(-150, 150),
            "timestamp": fake.date(),
        }
        listaMovimenti["rows"].append(row)

    for i in range(0, 10):
        row = {
            "idConto": i,
            "saldo": randint(2000, 8000),
            "timestamp": fake.date()
        }
        saldoConti["rows"].append(row)

    #Salvataggio dei file
    savecsvFile('./database/saldoConti.csv', "w", saldoConti["header"], saldoConti["rows"])
    savecsvFile('./database/listaMovimenti.csv', "w", listaMovimenti["header"], listaMovimenti["rows"])
    savecsvFile('./database/anagrafica.csv', "w", anagrafica["header"], anagrafica["rows"])

    print(colored("DataBase generato correttamente :)", "green"))
    print()

def read_DB():
	db = []
	anagrafica = readcsvFile("./database/anagrafica.csv")
	saldoConti = readcsvFile("./database/saldoConti.csv")
	listaMovimenti = readcsvFile("./database/listaMovimenti.csv")
	db.append(anagrafica)
	db.append(saldoConti)
	db.append(listaMovimenti)
	return db

def prelievo(idConto, importo, saldoConti, listaMovimenti):
	for conto in saldoConti["rows"]:
		if int(conto[0]) == idConto:
			print("Effettuo un prelievo")
			conto[1] = int(conto[1])
			if conto[1]>importo:
				conto[1] -= importo
				listaMovimenti["rows"].append([idConto, "-"+str(importo), str(datetime.date.today())])
				savecsvFile_bis("./database/saldoConti.csv", "w", saldoConti["header"], saldoConti["rows"])
				updatecsvFile("./database/listaMovimenti.csv", "a", [listaMovimenti["rows"][-1]])
				return True
			else:
				print(colored("Importo inserito maggiore del saldo: inserire un importo valido", "red"))
				return False
	return False
			
	print(colored("Impossibile effettuare il prelievo!", "red"))
	return False

def versamento(idConto, importo, saldoConti, listaMovimenti):
	for conto in saldoConti["rows"]:
		if int(conto[0]) == idConto:
			timestamp = datetime.date.today()
			conto[1] = int(conto[1])
			conto[1] += importo
			conto[1] = str(conto[1])
			conto[2] = str(timestamp)
			listaMovimenti["rows"].append([idConto, "+"+str(importo), str(datetime.date.today())])
			savecsvFile_bis("./database/saldoConti.csv", "w", saldoConti["header"], saldoConti["rows"])
			updatecsvFile("./database/listaMovimenti.csv", "a", [listaMovimenti["rows"][-1]])
			return True	
	return False

#--------------------------PROGRAMMA------------------------------

print()
print("BENVENUTO NEL SOFTWARE DI SMART BANKING")
print()
while comando != 10:
	os.system('clear')
	if logged != False:
		print("---------------------------------------------------------------------------------------")
		print(colored("				Logged as "+logged["Name"], "green"))
		print("---------------------------------------------------------------------------------------")
		print()
	else:
		print("---------------------------------------------------------------------------------------")
		print(colored("				Not logged", "red"))
		print("---------------------------------------------------------------------------------------")
		print()

	print("Seleziona un comando:")
	print("    1. Genera DB correntisti")
	print("    2. Stampa lista conti (ADMIN)")
	print("    3. LOGIN")
	print("    4. Stampa saldo del tuo conto")
	print("    5. Stampa lista movimenti del tuo conto")
	print("    6. Crea un nuovo conto")
	print("    7. Effettua un versamento")
	print("    8. Effettua un prelievo")
	print("    9. LOGOUT")
	print("    10. ESCI e chiudi il programma")

	comando = int(input("inserisci qui il tuo comando: "))
	print()
	if comando == 1:
		generate_DB()
	
	elif comando == 2:
		db = read_DB()
		print("\nLista conti correnti")
		print("		   ", colored(db[0]["header"], "yellow"))
		for row in db[0]["rows"]:
			print("		-> ", row)
		print()
	
	elif comando == 3:
	    db = read_DB()
	    logged = login(db[0])
	
	elif comando == 4:
		if logged != False:
			db = read_DB()
			saldo = None
			idConto = int(logged["id_conto"])
			for row in db[1]["rows"]:
				if int(row[0]) == idConto:
					saldo = row[1]
					break
			print()
			print(colored("Il saldo del conto {} ammonta a{} euro.".format(idConto, saldo), "green"))
			print()
		else:
			print(colored("Per vedere il saldo del conto devi essere loggato", "red"))
	
	elif comando == 5:
		if logged != False:
			db = read_DB()
			idConto = int(logged["id_conto"])
			print()
			print("Lista movimenti del conto", idConto)
			print("		  ", colored(db[2]["header"], "yellow"))
			esisteM = False
			for row in db[2]["rows"]:
				if int(row[0]) == idConto:
					esisteM = True
					print("		->", row)
			if esisteM == False:
				print(colored("Non ci sono movimenti per questo conto corrente!", "red"))
			print()
		else:
			print(colored("Per vedere i movimenti del conto devi essere loggato", "red"))

	elif comando == 6:
		db = read_DB()
		lastID = int(db[0]["rows"][-1][2])

		print()
		print(colored("---- CREAZIONE NUOVO CONTO ----", "blue"))
		print()
		#Input valori
		newID = lastID + 1 
		nome = input("Inserire il NOME del correntista: ")
		cognome = input("Inserire il COGNOME del correntista: ")
		deposito = int(input("Somma da depositare inizialmente sul conto: "))
		nchar = int(input("Lunghezza password (>= 20 caratteri): "))
		new_psw = generaPSW(nchar)
		timestamp = datetime.date.today()
		#Aggiornamento DB
		updatecsvFile("./database/anagrafica.csv", "a", [[nome, cognome, newID, new_psw]])
		updatecsvFile("./database/saldoConti.csv", "a", [[newID, deposito, timestamp]])
		updatecsvFile("./database/listaMovimenti.csv", "a", [[newID, ("+"+str(deposito)), timestamp]])

	elif comando == 7:
		db = read_DB()
		if logged != False:
			print()
			print(colored("---- Avvio procedura di VERSAMENTO ----", "blue"))
			print()
			importo = int(input("Importo da versare (+): "))
			if importo > 0:
				versamento(int(logged["id_conto"]), importo, db[1], db[2])
				print("Versamento Effettuo")
			else:
				print(colored("Inserire valore numerico maggiore di zero", "red"))
			
		else:
			print(colored("Per questa operazione devi essere loggato", "red"))
	
	elif comando == 8:
		db = read_DB()
		if logged != False:
			print()
			print(colored("---- Avvio procedura di PRELIEVO ----", "blue"))
			print()
			importo = int(input("Importo da prelevare: "))
			prelievo(int(logged["id_conto"]), importo, db[1], db[2])
			print("Prelievo Effettuo")
		else:
			print(colored("Per questa operazione devi essere loggato", "red"))
	
	elif comando == 9:
		logged = False
	elif comando == 10:
		done = True
	else:
		print()
		print(colored("COMANDO INSESISTENTE!!!", "yellow"))
		print()