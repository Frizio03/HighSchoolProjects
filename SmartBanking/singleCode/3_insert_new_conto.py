#Importazione librerie
import csv
import datetime

#DEFINIZIONE FUNZIONI
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
	            file.write(str(row[x])+', ')
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
#PROGRAMMA
print()
print("INSERISCI UN NUOVO CONTO")
print()
#Input valori
newID = lastID + 1 
nome = input("Inserire il NOME del correntista: ")
cognome = input("Inserire il COGNOME del correntista: ")
deposito = int(input("Somma da depositare inizialmente sul conto: "))
timestamp = datetime.date.today()
#Aggiornamento DB
updatecsvFile("./database/anagrafica.csv", "a", [[nome, cognome, newID]])
updatecsvFile("./database/saldoConti.csv", "a", [[newID, deposito, timestamp]])
updatecsvFile("./database/listaMovimenti.csv", "a", [[newID, ("+"+str(deposito)), timestamp]])