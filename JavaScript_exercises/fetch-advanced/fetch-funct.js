//Variabili e require
const fetch = require("node-fetch")
const myName = "Fabrizio Tedeschi"

//JSON di configurazione da passare al fetch

const configAccreditamento = {
    method: "post",
    body: JSON.stringify({nome: myName}),
    headers: {"Content-Type": "application/json"},
}

const configEsercizioGET = {
    method: "get",
    headers: {"x-data": "true"}
}

let configEsercizioPOST = {
    method: "post",
    headers: {"Content-Type": "application/json"}
}

//Funzioni principali

const accreditamento = (IP) => {
    fetch(IP+"/accreditamento", configAccreditamento)
        .then(res => res.json())
        .then(resBody => console.log(resBody))
        .catch(err => console.log(err))
}

const consegna = (link, numeroEs, risultato) => {
    configEsercizioPOST.body = JSON.stringify({data: risultato})
    return fetch(link+"/esercizi/"+numeroEs, configEsercizioPOST)
        .then(res => res.json())
        .then(resBody => console.log(resBody))
        .catch(err => console.log(err))
}

const richiedi = (link, numeroEs) => {
    return fetch(link+"/esercizi/"+numeroEs, configEsercizioGET)
        .then(res => res.json())
        .then(resBody => {
            console.log("ES", numeroEs + ":", resBody.message)
            let data = resBody.data
            return data
        })
        .catch(err => console.log(err))
}

const dataBase = (link) => {
    return fetch(link)
        .then(res => res.json())
        .catch(err => console.log(err))
}

//Esporto funzioni
module.exports.accreditamento = accreditamento
module.exports.richiedi = richiedi
module.exports.consegna = consegna
module.exports.dataBase = dataBase