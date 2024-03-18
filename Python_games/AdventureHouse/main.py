import json
from os import system #serve per eseguire tramite python i comandi del term
from random import choice
import sys

WRONG_INTERACTION_RESPONSES = [
    "non succede nulla",
    "non funziona",
    "niente da fare",
    "non credo sia la cosa giusta da fare",
    "non credo proprio",
    "non e'il caso"
]

#verifica il tipo di sistema opertivo tramite operazione booleana
IS_WINDOWS = sys.platform.lower() == "win32" 

#forgrund: colore del testo (un colore è un pezzo di testo che viene messo davanti ed alla fine di una stringa)
class Fg: 
    rs="\033[00m"
    black='\033[30m'
    red='\033[31m'
    green='\033[32m'
    orange='\033[33m'
    blue='\033[34m'
    purple='\033[35m'
    cyan='\033[36m'
    lightgrey='\033[37m'
    darkgrey='\033[90m'
    lightred='\033[91m'
    lightgreen='\033[92m'
    yellow='\033[93m'
    lightblue='\033[94m'
    pink='\033[95m'
    lightcyan='\033[96m'
#background: colore sello sfondo
class Bg: 
    rs="\033[00m"
    black='\033[40m'
    red='\033[41m'
    green='\033[42m'
    yellow='\033[43m'
    blue='\033[44m'
    magenta='\033[45m'
    cyan='\033[46m'
    white='\033[47m'
	#creazione di calsse per usare enum (strutura dati con valori annessi) in python
	#classe statica che ha 4 proprietà con valori numerici
class Directions:
    N = 0
    S = 1
    W = 2
    E = 3


class Entity:
    def __init__(self, room, x, y, graphic=None, color=None, name=None, description=None, interactions=None):
        self.room = room
        self.x = x
        self.y = y
        self.graphic = graphic
        self.color = color
        self.name = name
        self.description = description
        self.interactions = interactions
        self.game = self.room.game
    #la funzione set viene utilizzata per definire le caratt. di un'entità ma anche per mutare un istanza (no sostituzione - sì mutazione)
    def set(self, graphic, definition):
        self.graphic = graphic
        self.color = getattr(Bg, definition["color"]) #getattr recupera in modo programmatico una variabile da una classe statica
        self.name = definition["name"]
        self.description = definition["description"] #estrae dal dict una chiave che è obbligatoriamente descriptrion
        self.interactions = definition.get("interactions") #estrae dal dict il valore di una chiave e se non c'è restituisce None

    #prende come argomento l'oggetto con il quale si vuole interagire
    def interact(self, item=None):
        if self.interactions:#controllo se ci siano interazioni o meno
            action = None
            #controllo se si sta per interagire con anche un oggetto e se esiste un interazione con tale oggetto
            if item is not None and item.graphic in self.interactions:
                action = self.interactions[item.graphic]
            #controllo se si sta interagendo senza l'uso di oggetti e se esiste un interazione con "no-item"
            elif item is None and "no-item" in self.interactions:
                action = self.interactions["no-item"]

            #se si fanno interazioni senza senso la variabile action rimane vuota e si restituisce un messaggio base
            if action is not None:
                player = self.game.player

                if "message" in action:
                    print(action["message"])

                if "transform" in action:
                    transform = action["transform"]
                    if transform == " ":
                        self.room.entities.remove(self)
                    else: #si utilizza la funzione set per resettare le caratteristiche di una specifica entity
                        self.set(transform, Game.config["entities"][transform])

                if "pickup" in action:
                    player.inventory[self.graphic] = self
                #solo se c'è la variabile "remove_from_inventory" viene eliminato dall'inventario
                if item is not None and action.get("remove_from_inventory", False) == True :
                    del player.inventory[item.graphic]

                if "move_to_room" in action:
                    player.change_room(self.game.rooms[action["move_to_room"]])

                if "game_over" in action:
                    self.game.game_over(action["game_over"])

                if "win" in action:
                    self.game.win(action["win"])

                return
        #si stampa una a caso tra le wrong interactions
        print(choice(WRONG_INTERACTION_RESPONSES))

    def __str__(self):# __str__ è una funzione di python che converte ogni elemento in str prima di stamparlo --> override della funzione
        return self.color + " " + self.graphic + " " + Fg.rs + Bg.rs


class Mobile(Entity):
    def __init__(self, room, x, y, graphic, color):
        Entity.__init__(self, room, x, y, graphic, color)

    def change_room(self, room):
        from_room_number = self.room.number #variabile temporanea su cui mettere la stanza di partenza
        self.room = room #cambio dell'argomento room con il numero della stanza nuova
        for entity in self.room.entities: #scorrimento di tutte le entità controllando il numero di provenienza per il posizionamento del player
            if entity.graphic == str(from_room_number):
                self.x = entity.x
                self.y = entity.y
                break
        else:#eseguito solo se il ciclo termima spontaneamente senza interruzioni
            #comando che accetta una eccezione (=errore) e produce un errore che stampa un messaggio istanziando un'entità "excepion"
            raise Exception("this room has no {} door".format(from_room_number))

    def move(self, direction):#si controlla la direzione, se si è dentro al campo e se la casella è libera, poi si effettua il movimento
        if direction == Directions.N and self.y > 0 and self.room.get_entity_at_coords(self.x, self.y - 1) is None:
            self.y -= 1
        elif direction == Directions.S and self.y < self.room.h - 1 and self.room.get_entity_at_coords(self.x, self.y + 1) is None:
            self.y += 1
        elif direction == Directions.W and self.x > 0 and self.room.get_entity_at_coords(self.x - 1, self.y) is None:
            self.x -= 1
        elif direction == Directions.E and self.x < self.room.w - 1 and self.room.get_entity_at_coords(self.x + 1, self.y) is None:
            self.x += 1


class Player(Mobile):
    def __init__(self, room, x, y):
        Mobile.__init__(self, room, x, y, "P", Bg.blue)
        self.inventory = {}
    #l'inventario è un dict --> non avere più volte lo stesso oggetto
    def draw_inventory(self):
        print("Inventario:")
        if len(self.inventory) == 0:
            print("\t- vuoto")
        else:
            for entity in self.inventory.values():
                print("\t- {} {}: {}".format(entity, entity.name, entity.description))
                #\t = stampa di un tab (-->|) vuoto
    def change_player_room(self, room):
        # self.room.number
        self.room = room
        # todo set player coords based on previous room
    #si scorrono le caselle vicino al player per vedere se ci sono entity vicine
    def get_nearby_entities(self):
        nearby_entities = []
        for y in range(-1, 2):
            for x in range(-1, 2):
                if not x == y == 0:
                    entity = self.room.get_entity_at_coords(self.x + x, self.y + y)#date le coordinate del player si controllano quelle vicine
                    if entity and type(entity) is not Wall:
                        nearby_entities.append(entity)

        return nearby_entities


class Wall(Entity):
    def __init__(self, room, x, y):
        Entity.__init__(self, room, x, y, " ", Bg.black)


class Game:
    config = {}
    #caricamento dei file di configurazione
    for key in ("entities", "rooms", "game"):
        file = open("./config/{}.json".format(key))
        config[key] = json.load(file) #dato un file lo trasforma in un dictionary
        file.close()
    #si recuperano i dati nel file rooms che vengono appese alla lista di stanze
    def __init__(self):
        self.rooms = []
        for i in range(len(Game.config["rooms"])):
            room_data = Game.config["rooms"][str(i)]
            self.rooms.append(Room(self, i, room_data["color"], room_data["name"], room_data["description"]))
        #il simbolo * prende tutti gli arg della lista e li passa come argomento alla funzione
        self.player = Player(self.rooms[Game.config["game"]["start_room"]], *Game.config["game"]["start_coords"])
        #viene aggiunto un riferimento del player in ogni stanza. Il player ha un rifermimento alla stanza. Serve per far risaltare il player sopra altre entità.
        for room in self.rooms:
            room.entities.insert(0, self.player)

    def get_current_room(self):
        return self.player.room

    def win(self, message):
        print(message)
        print(Fg.green + "HAI VINTO!" + Fg.rs)
        input()
        exit()

    def game_over(self, message):
        print(message)
        print(Fg.red + "HAI PERSO!" + Fg.rs)
        input()
        exit()
    #è la funzione che viene chiamato all'infinito in g.update 
    def update(self):
        if IS_WINDOWS:
            system("cls")
        else:
            system("clear")

        print()
        self.get_current_room().draw()
        print()
        self.player.draw_inventory()
        print()
        print("Azioni:")
        print("\t- muovi con W A S D")
        nearby_entities = self.player.get_nearby_entities()
        for entity in nearby_entities:
            print("\t- {}: {}; interagisci con {}".format(entity.name, entity.description, entity))
            for inventory_entity in self.player.inventory.values():
                print("\t- usa {} con {} con {}{}".format(inventory_entity.name, entity.name, inventory_entity, entity))

        print("\t- QUIT per uscire")

        action = input().upper()
        if action == "W":
            self.player.move(Directions.N)
        elif action == "S":
            self.player.move(Directions.S)
        elif action == "A":
            self.player.move(Directions.W)
        elif action == "D":
            self.player.move(Directions.E)
        elif action == "QUIT": 
            quit()
        else:
            item = None
            action = action.replace(" ", "")
            if len(action) > 1:
                item = self.player.inventory.get(action[0])
                action = action[1]

            for entity in nearby_entities:
                if action == entity.graphic:
                    entity.interact(item)
                    input("premi un tasto per continuare...")
                    break
	#ricavare un elemento da un dict in modo programmatico significa ricavare un valore programmando qualcosa


class Room:
    def __init__(self, game, number, color, name, description):
        #il self passato a room sta ad indicare l'istanza del game
        self.game = game
        self.number = number
        self.color = getattr(Bg, color) #recupera un valore in modo programmatico da una classe: getattr(where, what)
        self.name = name
        self.description = description
        #viene eseguito un parsing (traduzione) di un file
        file = open("./config/{}.room".format(number))
        rows = file.readlines()
        file.close()
        self.h = len(rows)
        self.w = len(rows[0]) - 1
        self.entities = []
        # scorrimento delle righe e poi colonne ed inserimento delle entities
        for y in range(self.h):
            for x in range(self.w):
                char = rows[y][x].upper()
                if char == "#":
                    self.entities.append(Wall(self, x, y))
                elif char in Game.config["entities"]:#ricerca del carattere tra le chiavi del dict
                    e = Entity(self, x, y)
                    e.set(char, Game.config["entities"][char])
                    self.entities.append(e)
    #restituisce un entità che sta alle coordinate fornite
    def get_entity_at_coords(self, x, y):
        for e in self.entities:
            if e.x == x and e.y == y:
                return e #il return interrompe l'esecuzione della funzione
    #stampa nome, descrizione della room e disegna le entità nella stanza
    def draw(self):
        print(self.name)
        print(self.description)
        for y in range(self.h):
            for x in range(self.w):
                e = self.get_entity_at_coords(x, y)
                if e:# = if e is not None
                    print(e, end="")
                else:
                    print(self.color + "   " + Bg.rs, end="")
            print()


g = Game()

while True:
    g.update()

#si dice "cast" qualsiasi conversione di un elemento: int / str / ...