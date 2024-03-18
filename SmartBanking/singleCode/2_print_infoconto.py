#Importazione librerie
import csv
from termcolor import colored

#Definizione funzioni
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

#Lettura dei file csv di DataBase
anagrafica = readcsvFile("./database/anagrafica.csv")
saldoConti = readcsvFile("./database/saldoConti.csv")
listaMovimenti = readcsvFile("./database/listaMovimenti.csv")

#Applicativo
comando = 0
print()
print("BENVENUTO NEL SOFTWARE DI SMART BANKING")
print()
while comando != 4:
	print("Seleziona un comando:")
	print("    1. Stampa lista conti")
	print("    2. Stampa saldo conto")
	print("    3. Stampa lista movimenti per conto")
	print("    4. ESCI e chiudi il programma")

	comando = int(input("inserisci qui il tuo comando: "))
	print()

	if comando == 1:
		print("\nLista conti correnti")
		print(anagrafica["header"])
		for row in anagrafica["rows"]:
			print("		-> ", row)
		print()
	elif comando == 2:
		saldo = None
		idConto = int(input("Inserisci qui ID del conto ricercato: "))
		for row in saldoConti["rows"]:
			if int(row[0]) == idConto:
				saldo = row[1]
				break
		print()
		print(colored("Il saldo del conto {} ammonta a{} euro.".format(idConto, saldo), "green"))
		print()
	elif comando == 3:
		idConto = int(input("Inserisci qui ID del conto ricercato: "))
		print()
		print("Lista movimenti del conto", idConto)
		esisteM = False
		for row in listaMovimenti["rows"]:
			if int(row[0]) == idConto:
				esisteM = True
				print("		->", row)
		if esisteM == False:
			print(colored("Non ci sono movimenti per questo conto corrente!", "red"))
		print()
	elif comando == 4:
		done = True
	else:
		print()
		print("COMANDO INSESISTENTE!!!")
		print()