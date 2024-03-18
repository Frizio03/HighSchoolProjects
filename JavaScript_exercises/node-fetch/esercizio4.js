// Require
const fetch = require("node-fetch")

//Codice
const linkapi = "https://jsonplaceholder.typicode.com/posts"

function eliminaSpazi(stringa){
    for(let i; i<stringa.leght; i++){
        if (stringa[i]===" ")
            stringa[i] = ""
    }
    return stringa
}

fetch(linkapi)
    .then(res => res.json())
    .then(data => {
        lista4 = [];
        data
            .forEach(e => {
                e.body = eliminaSpazi(e.body)
            })
        data
            .filter(e => e.body.leght%3 === 0)
            .forEach(e => lista4.push(e.id))
        console.log(lista4)
    })