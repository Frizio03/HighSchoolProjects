// Require
const fetch = require("node-fetch")

//Codice
const linkapi = "https://jsonplaceholder.typicode.com/posts"

//Stampare sul terminale l'id di tutti i post dell’utente con id 4
fetch(linkapi)
    .then(res => res.json())
    .then(data => {
        lista = [];
        data
            .filter(e => e.userId === 4)
            .forEach(e => lista.push(e.id))
        console.log(lista)
    })