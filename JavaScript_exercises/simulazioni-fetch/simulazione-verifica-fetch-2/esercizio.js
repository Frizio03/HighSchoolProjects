//variabili e require
const IP = "http://192.168.1.231:8080"
const f = require("./fetch-funct.js")

//Esercizi

const Es1 = (nes) => {
    let soluzione = null
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            soluzione = data.filter(e => e%3 === 0),

            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es2 = (nes) => {
    let soluzione = [];
    let s = [];
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            s = data.filter(e => e[e.length-1] === "E")
            soluzione = s.map(e => e.toLowerCase())
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es3 = (nes) => {
    let soluzione = 0
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            for(i=0; i<data.length; i++){
                if(data[i].length < 5)
                    soluzione += data[i].length
            }

            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}


//Esporto funzioni
module.exports.Es1 = Es1
module.exports.Es2 = Es2
module.exports.Es3 = Es3