// Require
const fetch = require("node-fetch")

//Codice
const linkapi = "https://jsonplaceholder.typicode.com/posts"

//Stampare sul terminale l'id di tutti i post con userId dispari
fetch(linkapi)
    .then(res => res.json())
    .then(data => {
        lista2 = [];
        data
            .filter(e => e.userId%2 === 0)
            .forEach(e => lista2.push(e.id))
        console.log(lista2)
    })