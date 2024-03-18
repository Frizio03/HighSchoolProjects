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

	sol = []
	for i in data:
		if i % 5 == 0:
			sol.append(i)
	
	soluzione = {"data": sol}

	response2 = requests.post(url, json = soluzione)
	print(response2.json())

def esercizio_2():
	url = "http://192.168.1.231:8080/esercizi/2"
	response = requests.get(url, headers = {"x-data": "true"})
	print(response.json())
	data = response.json()["data"]

	sol = []
	string = ""
	
	for i in data:
		string = i.lower()
		if string[0] == "a" or string[0] == "e" or string[0] == "i" or string[0] == "o" or string[0] == "u":
			sol.append(string)

	soluzione = {"data": sol}

	response2 = requests.post(url, json = soluzione)
	print(response2.json())


def esercizio_3():
	url = "http://192.168.1.231:8080/esercizi/3"
	response = requests.get(url, headers = {"x-data": "true"})
	print(response.json())
	data = response.json()["data"]

	sol = []
	for i in data:
		if i > 0:
			sol.append(i)

	soluzione = {"data": len(sol)}

	response2 = requests.post(url, json = soluzione)
	print(response2.json())

accreditamento()
esercizio_1()
esercizio_2()
esercizio_3()