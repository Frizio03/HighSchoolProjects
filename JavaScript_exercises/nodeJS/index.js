// Require
const fetch = require("node-fetch")

//Codice

//Dato un elenco di utenti e le loro info vengono stampate le mail di ogni utente
const linkapi = "https://jsonplaceholder.typicode.com/users"
fetch(linkapi)
    .then(res => res.json())
    .then(data => {
        for (let index = 0; index < 10; index++) {
            console.log("Utente " + data[index].id + " " + data[index].email)
        }
    })

//Dato un elenco di post di vari utenti si stampano i titoli dei post di un utente stabilito
const linkapi2 = "https://jsonplaceholder.typicode.com/posts"
fetch(linkapi2)
    .then(res => res.json())
    .then(data => {
        data
            .filter(e => e.userId === 5)
            .forEach((e, index) => console.log(index+1, e.title))
    })