// Require
const fetch = require("node-fetch")

//Codice
const linkapi = "https://jsonplaceholder.typicode.com/posts"

//Stampare sul terminale un’unica stringa che sia formata da tutti i body di tutti i post il cui titolo inizia per “s”
fetch(linkapi)
    .then(res => res.json())
    .then(data => {
        string = ""
        data
            .filter(e => e.title[0] === "s")
            .forEach(e => string += e.body)
        console.log(string)
    })