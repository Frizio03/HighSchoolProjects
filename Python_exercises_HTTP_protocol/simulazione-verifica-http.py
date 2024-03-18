import requests
import json

def accreditamento():
	url = "http://192.168.1.231:8080/accreditamento"
	response = requests.post(url, json = {"nome": "Nome Cognome"})
	print(response.json())

def esercizio_1():
	url = "http://192.168.1.231:8080/esercizi/1"
	response = requests.get(url, headers = {"x-data": "true"})
	print(response.json())
	
	data = response.json()["data"]
	soluzione = {"data": sum(data)}

	response2 = requests.post(url, json = soluzione)
	print(response2.json())

def esercizio_2():
	url = "http://192.168.1.231:8080/esercizi/2"
	response = requests.get(url, headers = {"x-data": "true"})
	print(response.json())
	
	data = response.json()["data"]
	lista_prodotto = []
	minore = min(data)

	for i in data:
		prodotto = i*minore
		lista_prodotto.append(prodotto)

	soluzione = {"data": lista_prodotto}

	response2 = requests.post(url, json = soluzione)
	print(response2.json())


accreditamento()
esercizio_1()
esercizio_2()