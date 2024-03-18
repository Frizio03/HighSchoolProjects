//variabili e require
const IP = "http://192.168.1.231:8080"
const f = require("./fetch-funct.js")

//Esercizi

const Es1 = (nes) => {
    let soluzione = null
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            soluzione = data.filter(e => e != 0),

            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es2 = (nes) => {
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            data.forEach(e => e.year = 2021)
            f.tentaEsercizio(IP, nes, data)
        })
        .catch(err => console.log(err))
}

const Es3 = (nes) => {
    let soluzione
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/

            soluzione = data.join("").replace(/[0-2]/g, "")

            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es4 = (nes) => {
    let soluzione = [];
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            sol = data.map(e => Math.trunc(e))
            soluzione = sol.filter(e => e%2 !== 0)

            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es5 = (nes) => {
    let soluzione = [];
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            soluzione = data.map(e => e.slice(1, -1).toUpperCase())
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es6 = (nes) => {
    let soluzione = ""
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            soluzione = data.sort((a, b) => a - b)

            f.tentaEsercizio(IP, nes, soluzione[3])
        })
        .catch(err => console.log(err))
}

//Esporto funzioni
module.exports.Es1 = Es1
module.exports.Es2 = Es2
module.exports.Es3 = Es3
module.exports.Es4 = Es4
module.exports.Es5 = Es5
module.exports.Es6 = Es6