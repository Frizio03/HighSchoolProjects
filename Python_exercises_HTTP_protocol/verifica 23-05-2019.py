from spalla import Verifica

Verifica.url = "http://192.168.1.231:8080"
Verifica.firma("Fabrizio Tedeschi")
Verifica.stampa_voto()

def es_1():
	es = Verifica.inizia_esercizio(1)
	somma = 0
	for i in es.dati:
		if i < 513:
			somma += i

	es.consegna(somma)

def es_2():
	es = Verifica.inizia_esercizio(2)
	numero = 0
	for i in es.dati:
		if len(i) < 4:
			numero += 1

	es.consegna(numero)

def es_3():
	es = Verifica.inizia_esercizio(3)
	soluzione = []
	for i in es.dati:
		if i < 4 and i % 2 == 0:
			soluzione.append(i)

	es.consegna(soluzione)

def es_4():
	es = Verifica.inizia_esercizio(4)
	soluzione = []
	for i in range(0, len(es.dati)):
		if es.dati[i] > 0:
			soluzione.append(i)

	es.consegna(soluzione)

def es_5():
	es = Verifica.inizia_esercizio(5)
	soluzione = []
	for parola in es.dati:
		if parola[0] != "e" and parola[-1] != "e" :
			soluzione.append(parola)

	es.consegna(soluzione)

def es_6():
	es = Verifica.inizia_esercizio(6)
	soluzione = []
	for numero in range(44, es.dati+1):
		if numero % 6 != 0:
			soluzione.append(numero)

	es.consegna(soluzione)

def es_7():
	es = Verifica.inizia_esercizio(7)
	soluzione = []
	for parola in es.dati.split():
		if parola[0] != "o" and parola[0] != "s" :
			soluzione.append(parola)

	es.consegna(soluzione)

es_1()
es_2()
es_3()
es_4()
es_5()
es_6()
es_7()


Verifica.stampa_voto()