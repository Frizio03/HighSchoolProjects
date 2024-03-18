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
	
	sol = []
	resto = 0
	data = response.json()["data"]
	for i in data:
		resto = i % 2
		if resto == 0:
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
	stringa = ""

	for i in data:
		if i == data[-1]:
			stringa = stringa + str(i)
		else:
			stringa = stringa + str(i) + "-"

	soluzione = {"data": stringa}

	response2 = requests.post(url, json = soluzione)
	print(response2.json())

#considerare solo i valori maggiori della media dei valori della lista
def esercizio_3():
	url = "http://192.168.1.231:8080/esercizi/3"
	response = requests.get(url, headers = {"x-data": "true"})
	print(response.json())
	
	data = response.json()["data"]
	somma_prec = 0
	maggiore = max(data)
	indice = data.index(maggiore)

	for i in range(0, indice):
		somma_prec += int(data[i])

	soluzione = {"data": somma_prec}

	response2 = requests.post(url, json = soluzione)
	print(response2.json())

#ESECUZIONE
accreditamento()
esercizio_1()
esercizio_2()
esercizio_3()
