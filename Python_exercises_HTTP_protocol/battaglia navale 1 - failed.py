import requests
from time import sleep
import random

def signup():
	url = "http://192.168.1.231:8000/signup"
	response = requests.post(url, json = {"name": "Fuego"})
	print(response.json())
'''
def info():
	url = "http://192.168.1.231:8000/info"
	response = requests.get(url)
	print(response.json())
	high = response.json()["field"]["h"]
	width = response.json()["field"]["w"]
	print(high, width)
	return high
	return width'''

def colpisci():
	url = "http://192.168.1.231:8000/info"
	url1 = "http://192.168.1.231:8000"
	response = requests.get(url)
	high = response.json()["field"]["h"]
	width = response.json()["field"]["w"]
	campo = response.json()["field"]["grid"]
	count_colonna = 0
	count_cella = 0
	
	for colonna in campo:
		
		for cella in colonna:
			
			if count_colonna >= 0 and count_colonna <= int(high):
				if count_cella >= 0 and count_cella <= int(width):
					if cella != 1 and cella != 2:
						response2 = requests.post(url1, json = {"x": count_colonna, "y": count_cella})
						print(response2.json())
						sleep(3)
			count_cella += 1
		count_colonna += 1

signup()
colpisci()


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
'''for i in range(3):
	print("ciao")
	sleep(3)'''