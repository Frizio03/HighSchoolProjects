import requests
from time import sleep
import random

def signup():
	url = "http://192.168.1.231:8000/signup"
	response = requests.post(url, json = {"name": "Fuego"})
	print(response.json())

def info_colpisci():
	url = "http://192.168.1.231:8000/info"
	url1 = "http://192.168.1.231:8000"
	#prendo informazioni su altezza e lunghezza del campo
	response = requests.get(url)
	high = response.json()["field"]["h"]
	width = response.json()["field"]["w"]
	
	for indice_colonna in range(int(width)):
		for indice_cella in range(int(high)):
			#prende informazioni aggiornate sulle celle ogni volta
			response = requests.get(url)
			campo = response.json()["field"]["grid"]
			#assegno ad una variabile la lista della colonna
			colonna_corrente = campo[indice_colonna]
		#1° CONTROLLO per vedere se nella cella è stata colpita una nave
			if colonna_corrente[indice_cella] == 2:
				indice_extra = indice_colonna + 1
			#2° CONTROLLO per "out of bounds"	
				if indice_extra <= int(width):
					colonna_extra = campo[indice_extra]
				#3° CONTROLLO per controllare che la cella a SINISTRA non sia "already hit"
					if colonna_extra[indice_cella] != 1 and colonna_extra[indice_cella] != 2:
						response1 = requests.post(url1, json = {"x": indice_extra, "y": indice_cella})
						print(response1.json())
						sleep(3)
				
				indice_extra = indice_colonna + 2
				if indice_extra <= int(width):
					colonna_extra = campo[indice_extra]
				#3° CONTROLLO per controllare che la cella a DESTRA non sia "already hit"
					if colonna_extra[indice_cella] != 1 and colonna_extra[indice_cella] != 2:
						response1 = requests.post(url1, json = {"x": indice_extra, "y": indice_cella})
						print(response1.json())
						sleep(3)
		#se non è stata ancora colpita la cella la si colpisce
			elif colonna_corrente[indice_cella] == 0:
				response1 = requests.post(url1, json = {"x": indice_colonna, "y": indice_cella})
				print(response1.json())
				sleep(3)

				response = requests.get(url)
				campo2 = response.json()["field"]["grid"]

				x_random = random.randint(0, high)
				y_random = random.randint(0, width)

				colonna_corrente2 = campo2[x_random]
				cella_corrente = colonna_corrente2[y_random]

				if cella_corrente == 0:
					response1 = requests.post(url1, json = {"x": x_random, "y": y_random})
					print(response1.json())
					sleep(3)


signup()
info_colpisci()


'''
100 = fuori
110 = colpo vuoto
120 = colpito
130 = affondato
140 = attendere
150 = già colpito
campo field = h - w --> 1 based;
campo grid: array (w) formato da array (h)
'''
'''for i in range(3):
	print("ciao")
	sleep(3)'''