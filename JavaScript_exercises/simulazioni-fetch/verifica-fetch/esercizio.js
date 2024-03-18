//variabili e require
const IP = "http://192.168.1.231:8080"
const f = require("./fetch-funct.js")

//Esercizi

const Es1 = (nes) => {
    let soluzione = null
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            soluzione = data.filter(e => e%5 === 0)

            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es2 = (nes) => {
    f.richiediEsercizio(IP, nes)
        .then(data => {
            let soluzione = [];
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            console.log(data)
            for(let i = 0; i<data.length; i++){
                if(data[i][0]==="A" || data[i][0]==="E" || data[i][0]==="I" || data[i][0]==="O" || data[i][0]==="U"){
                    soluzione.push(data[i].toLowerCase())
                }
            }

            console.log(soluzione)
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es3 = (nes) => {
    let soluzione
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            soluzione = data.filter(e => e > 0)
            let n = soluzione.length
            f.tentaEsercizio(IP, nes, n)
        })
        .catch(err => console.log(err))
}


//Esporto funzioni
module.exports.Es1 = Es1
module.exports.Es2 = Es2
module.exports.Es3 = Es3
