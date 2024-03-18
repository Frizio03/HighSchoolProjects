//Variabili e require
const fetch = require("node-fetch")
const IP = "http://192.168.178.33:8080"
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

const accreditamento = () => {
    fetch(IP+"/accreditamento", configAccreditamento)
        .then(res => res.json())
        .then(resBody => console.log(resBody))
        .catch(err => console.log(err))
}

const tentaEsercizio = (link, numeroEs, risultato) => {
    configEsercizioPOST.body = JSON.stringify({data: risultato})
    return fetch(link+"/esercizi/"+numeroEs, configEsercizioPOST)
        .then(res => res.json())
        .then(resBody => console.log(resBody))
        .catch(err => console.log(err))
}

const richiediEsercizio = (link, numeroEs) => {
    return fetch(link+"/esercizi/"+numeroEs, configEsercizioGET)
        .then(res => res.json())
        .then(resBody => {
            let data = resBody.data
            return data
        })
}

//Esporto funzioni
module.exports.accreditamento = accreditamento
module.exports.richiediEsercizio = richiediEsercizio
module.exports.tentaEsercizio = tentaEsercizio