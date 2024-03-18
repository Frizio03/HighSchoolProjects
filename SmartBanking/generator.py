#import pyperclip
import random
import os
import time
from termcolor import colored

def generaPSW(numbercharacter):
	letters = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
	numbers = ["1","2","3","4","5","6","7","8","9","0"]
	symbols = ["|", "!", "£", "$", "%", "&", "/", "(", ")", "=", "?", "^", "[", "]", "{", "}", "*", "+", "@", "°", "#", "§", "-", "_", ".", ":", "·", ",", ";", "<", ">"]
	menugenerator = "1. Solo lettere (CAPITAL and lowercase).\n2. Lettere e numeri.\n3. Con caratteri speciali (es. @, $, !, ecc...)."
	possiblechoices = ["1", "2"]
	possiblechoices2 =["1", "2", "3"]
	choice = ""
	choicemenu = ""
	x = 0
	password = ""
	
	while choice not in possiblechoices2:
		print(menugenerator)
		print()
		choice= input("_Seleziona una delle opzioni_ ")
	choice=int(choice)
	while True:
		try:
			if numbercharacter>=20:
				print(colored("La password contiene "+str(numbercharacter)+" caratteri.", "green"))
				break
			else:
				print(colored("La password deve avere almeno 20 caratteri!!!", "yellow"))
				return ""
		except ValueError:
			print("\n")
			print(colored("Inserisci un intero, sono accettati solo valori numerici!!!", "yellow"))
			continue
	if choice==1:
		while x<numbercharacter:
			x+=1
			element=random.choice(letters)
			password+=str(element)
		#print("The generate password is: ", password)
	elif choice==2:
		while x<numbercharacter:
			x+=1
			chosenlist=random.randint(1, 2)
			if chosenlist==1:
				element=random.choice(letters)
				password+=str(element)
			elif chosenlist==2:
				element=random.choice(numbers)
				password+=str(element)
		#print("The generate password is: ", password)
	elif choice==3:
		while x<numbercharacter:
			x+=1
			chosenlist=random.randint(1, 3)
			if chosenlist==1:
				element=random.choice(letters)
				password+=str(element)
			elif chosenlist==2:
				element=random.choice(numbers)
				password+=str(element)
			elif chosenlist==3:
				element=random.choice(symbols)
				password+=str(element)
		#print("The generate password is: ", password)
	return password