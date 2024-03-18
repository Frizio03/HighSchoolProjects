import requests
import json

def accreditamento():
	url = "http://192.168.1.231:8080/accreditamento"
	response = requests.post(url, json = {"nome": "Nome Cognome"})
	print(response.json())

#rendere tutti i numeri positivi
def esercizio_1():
	url = "http://192.168.1.231:8080/esercizi/1"
	response = requests.get(url, headers = {"x-data": "true"})
	print(response.json())
	num = -1
	
	sol = []
	data = response.json()["data"]
	for i in data:
		if i < 0:
			i *= num
		sol.append(i)
	soluzione = {"data": sol}

	response2 = requests.post(url, json = soluzione)
	print(response2.json())

#restituire le iniziali delle parole
def esercizio_2():
	url = "http://192.168.1.231:8080/esercizi/2"
	response = requests.get(url, headers = {"x-data": "true"})
	print(response.json())
	
	data = response.json()["data"]
	lista_iniziali = []

	for i in data:
		lista_iniziali.append(i[0])

	soluzione = {"data": lista_iniziali}

	response2 = requests.post(url, json = soluzione)
	print(response2.json())

#considerare solo i valori maggiori della media dei valori della lista
def esercizio_3():
	url = "http://192.168.1.231:8080/esercizi/3"
	response = requests.get(url, headers = {"x-data": "true"})
	print(response.json())
	
	data = response.json()["data"]
	lista_maggiori = []
	somma = 0
	contatore = 0
	media = 0

	for i in data:
		somma += i
		contatore += 1

	media = somma / contatore

	for i in data:
		if i > media:
			lista_maggiori.append(i)

	soluzione = {"data": lista_maggiori}

	response2 = requests.post(url, json = soluzione)
	print(response2.json())

#ESECUZIONE
accreditamento()
esercizio_1()
esercizio_2()
esercizio_3()
