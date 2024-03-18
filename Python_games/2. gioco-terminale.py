'''creare una classe entity con X e Y
	fare una funzione move con un argomento direction che sia una stringa N-S-W-E

	
	creare una classe ereditaria player
		- cur_HP e max_HP

	creare una classe ereditata chiamata enemy
		- damage
		- funzione attack che prende il player come argomento --> solo se si trova ad una coordinata adiacente al player

	creare una classe ereditaria chiamata gold che il giocatore vince se raggiunge

'''
from random import randint
class Entity:
	def __init__(self, x, y):
		self.x = x
		self.y = y

	def move(self, direction):
		if direction == "W":
			self.x -= 1
			if self.x < 0:
				self.x += 1
		
		if direction == "D":
			self.y += 1
			if self.y > larghezza - 1:
				self.y -= 1

		if direction == "S":
			self.x += 1
			if self.x > altezza - 1:
				self.x -= 1

		if direction == "A":
			self.y -= 1
			if self.y < 0:
				self.y += 1

class Player(Entity):
	def __init__(self, x, y, max_HP, cur_HP):
		Entity.__init__(self, x, y)
		self.max_HP = max_HP
		self.cur_HP = cur_HP

class Enemy(Entity):
	def __init__(self, x, y, damage):
		Entity.__init__(self, x, y)
		self.damage = damage

	def attack(self, player):
		Player.cur_HP -= self.damage

class Gold(Entity):
		def __init__(self, x, y):
			Entity.__init__(self, x, y)

campo = []
altezza = 5
larghezza = 8
count_riga = 0
count_cella = 0
done = False

#definizione delle entità
Player = Player(1, 2, 100, 100)
Enemy = Enemy(randint(0, altezza-1), randint(0, larghezza-1), 20)
Gold = Gold(3, 3)

while not done:

	#creazione del campo di gioco
	for riga in range(altezza):
		riga_1 = []
		for cella in range(larghezza):
			if cella == Player.y and riga == Player.x:
				riga_1.append("[ P ]") 
			elif cella == Gold.y and riga == Gold.x:
				riga_1.append("[ G ]")
			elif cella == Enemy.y and riga == Enemy.x:
				riga_1.append("[ M ]")
			else:
				riga_1.append("[   ]")
		campo.append(riga_1)
		print(riga_1)
		print()

	#input direzione player e movimento
	print()
	direzione = str(input(" ---INSERISCI DIREZIONE: "))
	Player.move(direzione)
	
	#controllo ed esecuzione danno
	if Player.x+1 == Enemy.x and Player.y == Enemy.y:
		Enemy.attack(Player)
	elif Player.x-1 == Enemy.x and Player.y == Enemy.y:
		Enemy.attack(Player)
	elif Player.y+1 == Enemy.y and Player.x == Enemy.x:
		Enemy.attack(Player)
	elif Player.y-1 == Enemy.y and Player.x == Enemy.x:
		Enemy.attack(Player)
	elif Player.y == Enemy.y and Player.x == Enemy.x:
		Enemy.attack(Player)

	#stampa dei PV aggiornata
	print()
	print("PV = " + str(Player.cur_HP) + "/" + str(Player.max_HP))
	print()

	if Player.cur_HP <= 0:
		print()
		print("MALE!!  @Player  HAI PERSO")
		print()
		done = True
	elif Player.x == Gold.x and Player.y == Gold.y:
		print()
		print("BRAVO!!  @Player  HAI VINTO")
		print()
		done = True