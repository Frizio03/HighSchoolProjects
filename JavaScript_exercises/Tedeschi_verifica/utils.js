"use strict"

const inserisciIntero = (messaggio, min, max) => {
    let numero
    do{
        numero = +prompt(messaggio)
    } while(numero<min || numero>max)
    return numero
}

//Inserire v1 come valore variabile e v2 come valore con cui confrontare v1
const confronto = (v1, v2) => {
    if(v1 === v2){console.log("Il valore inserito " + v1 + " risulta UGUALE di E = " + v2)}
    else if(v1 < v2){console.log("Il valore inserito " + v1 + " risulta MINORE di E = " + v2)}
    else{console.log("Il valore inserito " + v1 + " risulta MAGGIORE di E = " + v2)}
}

const maggiorenne = (V) => {
    if(V>=18){
        return true
    }
    else{
        return false
    }
}

//verifica se il parametro "valore" risulta multiplo di "numero"
const multiplodi = (valore, numero) => {
    if(valore%numero===0 && valore!==numero){console.log("Il valore inserito risulta multiplo di E")}
    else{console.log("Il valore inserito NON risulta multiplo di E")}
}

const percentualeMaggiorenni = (nM, nValori) => {
    return 100*nM/nValori
}