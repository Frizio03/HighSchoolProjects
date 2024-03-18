from spalla import Verifica

Verifica.url = "http://192.168.1.231:8000"
Verifica.firma("Fabrizio Tedeschi")
Verifica.stampa_voto()

def es_1():
	es = Verifica.inizia_esercizio(1)
	es.consegna(es.dati.lower())

def es_2():
	es = Verifica.inizia_esercizio(2)
	soluzione = es.dati
	soluzione *= es.dati
	es.consegna(es.dati)

def es_3():
	es = Verifica.inizia_esercizio(3)
	es.consegna(es.dati["cognome"])

def es_4():
	es = Verifica.inizia_esercizio(4)
	es.consegna(len(es.dati))

def es_5():
	es = Verifica.inizia_esercizio(5)
	soluzione = []
	for parola in es.dati:
		soluzione.append(parola.upper())
	es.consegna(soluzione)

def es_6():
	es = Verifica.inizia_esercizio(6)
	somma = 0
	for numero in es.dati:
		somma += numero
	es.consegna(somma)

def es_7():
	es = Verifica.inizia_esercizio(7)
	somma = 0
	for numero in es.dati:
		if numero > 5:
			somma += numero
	es.consegna(somma)

def es_8():
	es = Verifica.inizia_esercizio(8)
	somma = 0
	for i in range(len(es.dati)):
		if i % 2 == 0:
			somma += es.dati[i]
	es.consegna(somma)

def es_9():
	es = Verifica.inizia_esercizio(9)
	somma = 0
	for numero in es.dati:
		if numero % 2 != 0:
			somma += numero
	es.consegna(somma)

def es_10():
	es = Verifica.inizia_esercizio(10)
	es.dati.sort()
	es.consegna(es.dati)

def es_11():
	es = Verifica.inizia_esercizio(11)
	soluzione = []
	es.dati.sort()
	for i in es.dati:
		soluzione.append(i.lower())
	soluzione.sort()
	es.consegna(soluzione)

def es_12():
	es = Verifica.inizia_esercizio(12)
	soluzione = []
	for i in es.dati:
		soluzione.append(i-1)
	es.consegna(soluzione)

def es_13():
	es = Verifica.inizia_esercizio(13)
	soluzione = []
	lunghezza = len(es.dati)
	count = 0
	for i in es.dati:
		if count == lunghezza-1:
			somma = i
		else:
			somma = i + es.dati[count+1]
		soluzione.append(somma)
		count += 1
	es.consegna(soluzione)

def es_14():
	es = Verifica.inizia_esercizio(14)
	soluzione = {"positivi": 0, "negativi": 0, "zeri": 0}
	positivi = 0
	negativi = 0
	zeri = 0
	for i in es.dati:
		if i > 0:
			positivi += 1
		if i == 0:
			zeri += 1
		if i < 0:
			negativi += 1
	soluzione["positivi"] = positivi
	soluzione["negativi"] = negativi
	soluzione["zeri"] = zeri
	es.consegna(soluzione)

def es_15():
	es = Verifica.inizia_esercizio(15)
	soluzione = []
	for i in es.dati:
		if len(i) % 2 == 0:
			soluzione.append(i.upper())
		else:
			soluzione.append(i.lower())
	es.consegna(soluzione)

def es_16():
	es = Verifica.inizia_esercizio(16)
	soluzione = ""
	count = 0
	for i in es.dati:
		if count < len(es.dati)-1:
			soluzione = soluzione + i + " "
		elif count >= len(es.dati)-1:
			soluzione += i
		count += 1
	es.consegna(soluzione)

def es_17():
	es = Verifica.inizia_esercizio(17)
	soluzione = ""
	for i in es.dati:
		soluzione += i[-1]
	es.consegna(soluzione)

def es_18():
	es = Verifica.inizia_esercizio(18)
	soluzione = ""
	for i in es.dati:
		if len(i) > 4:
			soluzione += i[0]
	es.consegna(soluzione)

def es_19():
	es = Verifica.inizia_esercizio(19)
	soluzione = []
	for divisore in range(1, es.dati+1):
		if es.dati % divisore == 0:
			soluzione.append(divisore)
		
	es.consegna(soluzione)

def es_20():
	es = Verifica.inizia_esercizio(20)
	soluzione = []
	for persona in es.dati:
		soluzione.append(len(persona["figli"]))
	es.consegna(soluzione)

def es_21():
	es = Verifica.inizia_esercizio(21)
	soluzione = []
	for n in es.dati:
		if n <= 5:
			soluzione.append(n)
	es.consegna(soluzione)

def es_22():
	es = Verifica.inizia_esercizio(22)
	soluzione = []
	for n in es.dati:
		if n >= 3 and n <= 6:
			soluzione.append(n)
	es.consegna(soluzione)

def es_23():
	es = Verifica.inizia_esercizio(23)
	soluzione = 0
	for persona in es.dati:
		soluzione += persona["anni"]
	es.consegna(soluzione)

def es_24():
	es = Verifica.inizia_esercizio(24)
	soluzione = []
	for persona in es.dati:
		if persona["cognome"][0] == "C":
			soluzione.append(persona["nome"])
	es.consegna(soluzione)

def es_25():
	es = Verifica.inizia_esercizio(25)
	soluzione = 0
	for stringa in es.dati:
		soluzione += stringa.count("a")
	es.consegna(soluzione)

def es_26():
	es = Verifica.inizia_esercizio(26)
	soluzione = []
	for numero in es.dati:
		soluzione.append(numero*-1)
	es.consegna(soluzione)

def es_27():
	es = Verifica.inizia_esercizio(27)
	dictio = es.dati
	listone = dictio["negozio"] + dictio["magazzino"]

	for elemento in listone:
		while listone.count(elemento) > 1:
			listone.remove(elemento)
	
	listone.sort()
	es.consegna(listone)

def es_28():
	es = Verifica.inizia_esercizio(28)
	dictio = es.dati
	soluzione = {}

	for elemento in dictio["negozio"]:
		soluzione[elemento] = dictio["magazzino"].count(elemento) + dictio["negozio"].count(elemento)
		
	es.consegna(soluzione)

def es_29():
	es = Verifica.inizia_esercizio(29)
	fattoriale = 1
	for i in range(1, es.dati+1):
		fattoriale *= i
	es.consegna(fattoriale)

def es_30():
	es = Verifica.inizia_esercizio(30)
	soluzione = {}

	es.consegna(soluzione)

es_1()
es_2()
es_3()
es_4()
es_5()
es_6()
es_7()
es_8()
es_9()
es_10()
es_11()
es_12()
es_13()
es_14()
es_15()
es_16()
es_17()
es_18()
es_19()
es_20()
es_21()
es_22()
es_23()
es_24()
es_25()
es_26()
es_27()
es_28()
es_29()
#es_30()

Verifica.stampa_voto()