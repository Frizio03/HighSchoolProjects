'use strict'

function InserisciIntero(messaggio, min, max){
    let numero = +prompt(messaggio)
    if(numero>min && numero<max){
        return true
    }
    else{
        return false
    }
}

function deltaf(a, b, c){
    return (b**2)-(4*a*c)
}

function Equazione(){
    let a = 0
    let b = 0
    let c = 0
    let soluzione1 = 0
    let soluzione2 = 0
    let delta
    while (a === 0){
        a = +prompt("Inserisci il coefficiente A")
    }
    b = +prompt("Inserisci il coefficiente B")
    c = +prompt("Inserisci il coefficiente C")
    delta = deltaf(a, b, c)
    alert("Il DELTA corrisponde a: " + delta)
    if (delta > 0){
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
}

function maggiore(a, b){
    let max = a
    if(max<b){max=b}
    return max
}
function minore(a, b){
    let min = a
    if(min>b){min=b}
    return min
}
function sommaIntervallo(a, b){
    let count = 0
    let somma = 0
    for(count = a; count <= b; count++){
        somma += count
    }
    return somma
}
function prodottoIntervallo(a, b){
    let count = 0
    let prodotto = 1
    for(count = a; count <= b; count++){
        prodotto *= count
    }
    return prodotto
}
function stampaMultipliIntervallo(a, b, k){
    let resto
    let count = 0
    let lista = [];
    for(count = a; count <= b; count++){
        resto = count % k
        if(resto === 0){
            //alert(count + " multiplo di " + k)
            lista.push(count)
        }
    }
    return lista
}