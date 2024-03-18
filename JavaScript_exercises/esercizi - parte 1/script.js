let nome = prompt("Dimmi il tuo nome")
alert("Il tuo nome: " + nome)
let anni = null
while(anni <= 0 | anni >= 100){
    anni = prompt("Dimmi quanti anni hai")
}
if(anni >= 18){
    alert("Sei " + nome + " e hai " + anni + " anni quindi sei MAGGIORENNE")
}
else {
    alert("Sei " + nome + " e hai " + anni + " anni quindi sei MINORENNE")
}
alert("EQUAZIONE DI SECONDO GRADO")
let a = 0
let b = 0
let c = 0
let delta = 0
let soluzione1 = 0
let soluzione2 = 0
while (a === 0){
    a = prompt("Inserisci il coefficiente A")
}
b = prompt("Inserisci il coefficiente B")
c = prompt("Inserisci il coefficiente C")
delta = (b**2)-(4*a*c)
alert("Il DELTA corrisponde a: " + delta)
if(delta > 0){
    soluzione1 = (-b+Math.sqrt(delta))/(2*a)
    soluzione2 = (-b-Math.sqrt(delta))/(2*a)
    alert("Le soluzioni distintte sono: x1 = " + soluzione1 + " x2 = " + soluzione2)
}
else if (delta === 0){
    soluzione1 = (-b)/(2*a)
    alert("Le soluzioni coincidenti sono: x1 = x2 = " + soluzione1)
}
else{
    alert("Le soluzioni sono complesse")
}

alert("MEDIA ARITMETICA")
let numero = 0
let somma = 0
let N = 0
while (N <= 0){
    N = prompt("Quanti valori vuoi inserire?")
}
for (numero = 0; numero < N; numero++){
    somma = somma + prompt("Inserisci valore")
}
let media = somma/N
alert(`La media ${media}`)