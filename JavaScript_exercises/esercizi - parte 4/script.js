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

function inserisciVoti(){
    let lista = [];
    lista[0] = 0
    let voto
    let i
    //inizializzazione
    for(i=1; i<11; i++){
        lista[i] = 0
    }
    //controllo moda
    do{
        voto = +prompt("Inserisci un voto, per terminare inserisci 0")
        lista[voto] += 1
    }while(voto !== 0)
    let max = 0
    for(i=1; i<11; i++){
        if(lista[i] > lista[max]){
            max = i
        }
    }
    alert("Moda: " + max)
}

function indovinaNumero(num){
    let valore
    do{
        valore = +prompt("Inserisci un valore")
        if(valore<num){
            alert("Il valore inserito risulta MINORE rispetto al numero X")
        }
        else if(valore>num){
            alert("Il valore inserito risulta MAGGIORE rispetto al numero X")
        }
    }while(valore !== num)
    alert("Hai indovinato!!!!!")
}