"use strict"

const saluta = (nome) => {
    console.log("Hello " + nome + "!")
}

const bye = (nome, cognome) => {
    console.log("Bye " + nome + " " + cognome + " !")
}

//Esporto le funzioni - è possibile cambiare il loro nome di esportazione
module.exports.saluta = saluta
module.exports.arrivederci = bye