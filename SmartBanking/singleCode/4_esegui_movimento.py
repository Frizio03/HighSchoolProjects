#Importazione librerie
import csv
import datetime
from termcolor import colored

#DEFINIZIONE FUNZIONI - lettura e scrittura
def readcsvFile(fileName):
	rows = []
	with open(fileName, "r") as file:
	    csvreader = csv.reader(file)
	    header = next(csvreader)
	    header.pop(3)
	    #print(header)
	    for row in csvreader:
	        row.pop(3)
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
	            file.write(str(x)+', ')
	        file.write('\n')

def updatecsvFile(fileName, mod, data):
	with open(fileName, mod) as file:
	    for row in data:
	        for x in row:
	            file.write(str(x)+', ')
	        file.write('\n')

#Lettura dei file csv di DataBase
anagrafica = readcsvFile("./database/anagrafica.csv")
saldoConti = readcsvFile("./database/saldoConti.csv")
listaMovimenti = readcsvFile("./database/listaMovimenti.csv")
lastID = int(anagrafica["rows"][-1][2])

#Definizione funzioni principali
def prelievo(idConto, importo, saldoConti=saldoConti, listaMovimenti=listaMovimenti):
	for conto in saldoConti["rows"]:
		if int(conto[0]) == idConto:
			print("Effettuo un prelievo")
			conto[1] = int(conto[1])
			if conto[1]>importo:
				conto[1] -= importo
				listaMovimenti["rows"].append([idConto, "-"+str(importo), str(datetime.date.today())])
				savecsvFile("./database/saldoConti.csv", "w", saldoConti["header"], saldoConti["rows"])
				updatecsvFile("./database/listaMovimenti.csv", "a", [listaMovimenti["rows"][-1]])
				return True
			else:
				print(colored("Importo inserito maggiore del saldo: inserire un importo valido", "red"))
				return False
	return False
			
	print(colored("Impossibile effettuare il prelievo!", "red"))
	return False
def versamento(idConto, importo, saldoConti=saldoConti, listaMovimenti=listaMovimenti):
	for conto in saldoConti["rows"]:
		if int(conto[0]) == idConto:
			timestamp = datetime.date.today()
			conto[1] = int(conto[1])
			conto[1] += importo
			conto[2] = str(timestamp)
			listaMovimenti["rows"].append([idConto, "+"+str(importo), str(datetime.date.today())])
			savecsvFile("./database/saldoConti.csv", "w", saldoConti["header"], saldoConti["rows"])
			updatecsvFile("./database/listaMovimenti.csv", "a", [listaMovimenti["rows"][-1]])
			return True	
	return False
	

#prelievo(10, 80000)
#versamento(10, 1100)

#Applicativo
comando = 0
print()
print("BENVENUTO NEL SOFTWARE DI GESTIONE CONTI")
print()
while comando != 3:
	print()
	print("Seleziona un comando:")
	print("    1. Effettua un versamento")
	print("    2. Effettua un prelievo")
	print("    3. ESCI e chiudi il programma")

	comando = int(input("Inserisci qui il tuo comando: "))
	print()

	if comando == 1:
		idConto = int(input("Inserisci ID del conto: "))
		importo = int(input("Inserisci l'importo da versare: "))
		if versamento(idConto, importo) == True:
			print(colored("Versamento effettuato con successo", "green"))
		else:
			print(colored("ERRORE nell'operazione, ritentare", "red"))
	elif comando == 2:
		idConto = int(input("Inserisci ID del conto: "))
		importo = int(input("Inserisci l'importo da prelevare: "))
		if prelievo(idConto, importo) == True:
			print(colored("Prelievo effettuato con successo!", "green"))
		else:
			print(colored("ERRORE nell'operazione, ritentare", "red"))
	elif comando == 3:
		done = True
	else:
		print()
		print(colored("COMANDO INSESISTENTE!!!", "yellow"))
		print()