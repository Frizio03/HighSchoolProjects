"use strict"

function numeroCasuale(min, max){
    min = Math.ceil(min)
    max = Math.floor(max)
    return Math.floor(Math.random()*(max-min)) //Max escluso e Min incluso
}

const inserisciPari = () => {
    let valore
    do{
        valore = +prompt("Inserisci un valore PARI")
    }while(valore%2 !== 0)
    alert("numero inserito correttamente")
    return valore
}

function inserisciIntero(messaggio, min, max){
    let numero
    do{
        numero = +prompt(messaggio)
    } while(numero<min || numero>max)
    return numero
}

function stampaDivisori(n){
    let i
    let count = 0
    for(i=0; i<=n; i++){
        if(n%i === 0){
            count++
        }
    }
    return count
}

const isPari = number => {
    if(number % 2 === 0){return true}
    else {return false}
}

const isPrimo = number => {
    let divisori = 0
    let i
    for(i=1; i<=number; i++){
        if(number%i === 0){divisori++}
    }
    if(divisori>2){return false}
    else {return true}
}

const isPerfetto = number => {
    let i
    let sommaDivisori = 0
    for(i=1; i<number; i++){
        if(number%i === 0){
            sommaDivisori += i
        }
    }
    if(sommaDivisori === number){return true}
    else {return false}
}

const media = (lista, N) => {
    let i
    let somma = 0
    for (i=0; i<N; i++){
        somma += lista[i];
    }
    return somma/N
}