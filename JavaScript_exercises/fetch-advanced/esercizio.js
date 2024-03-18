//variabili e require
const IP = "http://192.168.1.231:8080"
const linkDB = "https://jsonplaceholder.typicode.com"
const f = require("./fetch-funct.js")

//Esercizi

const Es1 = (nes, page) => {
    let soluzione = null
    f.richiedi(IP, nes)
        .then(data => {

            f.dataBase(linkDB + "/" + page)
                .then(data => {
                    
                    /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
                    console.log(data.email)
                    
                    /*CONSEGNA ESERCIZIO*/
                    f.consegna(IP, nes, soluzione)
                })
                .catch(err => console.log(err))
        })
        .catch(err => console.log(err))
}

const Es2 = (nes, page) => {
    let soluzione = null
    f.richiedi(IP, nes)
        .then(data => {

            f.dataBase(linkDB + "/" + page)
                .then(data => {
                    
                    /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
                    console.log(data.email)
                    
                    /*CONSEGNA ESERCIZIO*/
                    f.consegna(IP, nes, soluzione)
                })
                .catch(err => console.log(err))
        })
        .catch(err => console.log(err))
}

const Es3 = (nes, page) => {
    let soluzione = null
    f.richiedi(IP, nes)
        .then(data => {

            f.dataBase(linkDB + "/" + page)
                .then(data => {
                    
                    /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
                    console.log(data.email)
                    
                    /*CONSEGNA ESERCIZIO*/
                    f.consegna(IP, nes, soluzione)
                })
                .catch(err => console.log(err))
        })
        .catch(err => console.log(err))
}

const Es4 = (nes, page) => {
    let soluzione = null
    f.richiedi(IP, nes)
        .then(data => {

            f.dataBase(linkDB + "/" + page)
                .then(data => {
                    
                    /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
                    console.log(data.email)
                    
                    /*CONSEGNA ESERCIZIO*/
                    f.consegna(IP, nes, soluzione)
                })
                .catch(err => console.log(err))
        })
        .catch(err => console.log(err))
}

//Esporto funzioni
module.exports.Es1 = Es1
module.exports.Es2 = Es2
module.exports.Es3 = Es3
module.exports.Es4 = Es4
