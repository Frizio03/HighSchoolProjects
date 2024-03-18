'use strict'

function InserisciIntero(messaggio, min, max){
    let numero = +prompt(messaggio)
    while(numero<min || numero>max){
        numero = +prompt(messaggio)
    }
    return numero
}

function pari(number){
    if(number % 2 === 0){
        return true
    }
    else{
        return false
    }
}

function esercizio(){
    //input valori
    let N = InserisciIntero("Inserire N > 0", 0, Infinity)
    let min
    let max
    do {
        min = InserisciIntero("Inserire MIN > 0", 0, Infinity)
        max = InserisciIntero("Inserire MAX > 0", 0, Infinity)
    } while(min>max);
    //input valori lista per valori pari
    let i
    let lista = [];
    for(i = 0; i < N; i++){
        lista.push(InserisciIntero("Inserire numero nella lista", 0, Infinity))
    }
    let npari = 0
    for(i = 0; i < N; i++){
        if(pari(lista[i]) === true){
            npari +=1
        }
    }
    alert("In questo intervallo ci sono " + N + " numeri e " + npari + " sono pari")
    //Media nlla seconda parte di intervallo [MIN, MAX]
    let somma = 0
    let count = 0
    let condizione = (min+max)/2
    for(i = min; i <= max; i++){
        if(i >= condizione){
            somma += i
            count++
        }
    }
    let media = somma/count
    alert("La media della seconda parte dei numeri inseriti: " + media)
}