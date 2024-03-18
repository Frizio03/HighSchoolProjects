#Importazione librerie
from faker import Faker
fake = Faker()
from random import randint

#Funzione di salvataggio
def savecsvFile(fileName, mod, header, data):
	with open(fileName, mod) as file:
	    for value in header:
	        file.write(str(value)+', ')
	    file.write('\n')
	    for row in data:
	        for x in row:
	            file.write(str(row[x])+', ')
	        file.write('\n')

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
	"header": ["Nome", "Cognome", "idConto"],
	"rows": []  
}

#Generazione dati struct
for i in range(0, 10):
	row = {
		"Nome": fake.name().split(" ")[0],
		"Cognome": fake.name().split(" ")[1],
		"idConto": i
	}
	anagrafica["rows"].append(row)

for i in range(0, 10):
	row = {
		"idConto": randint(0, 10),
		"importo": randint(-150, 150),
		"timestamp": fake.date()
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