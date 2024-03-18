// Require
const fetch = require("node-fetch")

//Codice
const linkapi = "https://jsonplaceholder.typicode.com/posts"

//Stampare sul terminale l'id di tutti i post con un numero pari di parole nel titolo
fetch(linkapi)
    .then(res => res.json())
    .then(data => {
        lista3 = [];
        let totaleParole
        data
            .forEach(e => {
                totaleParole = 1
                for(let i=0; i<e.title.length; i++){
                    if(e.title[i] === " ")
                        totaleParole +=1
                }
                if(totaleParole === 7)
                    lista3.push(e.id)
            })
        console.log(lista3)
    })