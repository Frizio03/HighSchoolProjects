//variabili e require
const IP = "http://192.168.1.231:8080"
const f = require("./fetch-funct.js")

//Esercizi

const Es1 = (nes) => {
    let soluzione = null
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            soluzione = data.filter(e => e%2 === 0),

            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es2 = (nes) => {
    let soluzione = [];
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            for(i=0; i<data.length; i++){
                if(i%2 !== 0)
                    soluzione.push(data[i])
            }

            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es3 = (nes) => {
    let soluzione = [];
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            for(i=0; i<data.length; i++){
                if(data[i].length > 4)
                    soluzione.push(data[i].toUpperCase())
            }

            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es4 = (nes) => {
    let soluzione = [];
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            for(i=0; i<data.length; i++){
                let len = data[i].length
                if(data[i][len-1] === "E")
                    soluzione.push(data[i].toLowerCase())
            }

            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es5 = (nes) => {
    let soluzione = [];
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            for(i=0; i<data.length; i++){
                soluzione.push(data[i]-i)
            }

            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es6 = (nes) => {
    f.richiediEsercizio(IP, nes)
        .then(data => {
            let max = data[0];
            let soluzione = data[0];
            f.tentaEsercizio(IP, nes, data[data.length-2])
        })
        .catch(err => console.log(err))
}

const Es7 = (nes) => {
    let v = [];
    let soluzione = [];
    let parola = ""
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            console.log(data)
            v = data.split(" ")
            soluzione = v.filter(e => e[0] !== "a")
            f.tentaEsercizio(IP, nes, soluzione)
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
module.exports.Es7 = Es7