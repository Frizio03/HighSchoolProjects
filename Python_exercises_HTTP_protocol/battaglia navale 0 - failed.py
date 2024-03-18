import requests
import time

def signup():
	url = "http://192.168.1.231:8000/signup"
	response = requests.post(url, json = {"name": "Fuego"})
	print(response.json())

def info():
	url = "http://192.168.1.231:8000/info"
	response = requests.get(url)
	print(response.json())
	high = response.json()["field"]["h"]
	width = response.json()["field"]["w"]
	print(high, width)
	return high
	return width

def colpisci():
	url = "http://192.168.1.231:8000"
	response = requests.post(url)
	print(response.json())
	campo = response.json()["field"]["grid"]
	count_colonna = 0
	count_cella = 0
	for colonna in campo:
		count_colonna += 1
		for cella in colonna:
			count_cella += 1
			if cella == 1:
				if count_colonna == 

#signup()
info()

'''
100 = fuori
110 = colpo vuoto
120 = colpito
130 = affondato
140 = attendere
150 = già colpito
campo field = h - w --> 1 based;
campo grid: range (w) di range (h)
'''