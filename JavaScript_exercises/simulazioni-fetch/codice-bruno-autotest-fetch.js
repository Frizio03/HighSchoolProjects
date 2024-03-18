const fetch = require("node-fetch")

//TODO accreditamento

//1. recupero il dato dal server verifica
/*
fetch("http://192.168.1.231:8080/esercizi/1", {
    headers: {
        "x-data": true
    }
})
    .then(res => res.json())
    .then(data => {
        ex1(data)
    })
    .catch(console.error)
*/

function ex1(n) {
    Promise.all([
        fetch("https://jsonplaceholder.typicode.com/photos").then(res => res.json()),
        fetch("https://jsonplaceholder.typicode.com/albums").then(res => res.json())
    ])
        .then(data => {
            const [photos, albums] = data
            const album = albums[n-1]
            album.photos = photos.filter(e => e.albumId === n).map(e => e.url)
            console.log(album)
        })
        .catch(console.error)
}

function ex2(n) {
    fetch("https://jsonplaceholder.typicode.com/photos")
        .then(res => res.json())
        .then(data => {
            const title = data[n-1].title
            const result = String.fromCharCode(
                Math.round(
                    title.split("")
                        .map(e => e.charCodeAt())
                        .reduce((acc, e) => acc += e, 0) / title.length
                )
            )
            console.log(result)
        })
        .catch(console.error)
}

function ex3(userIds) {
    fetch("https://jsonplaceholder.typicode.com/posts")
        .then(res => res.json())
        .then(data => {
            //console.log(data)
            const userMapping = userIds.reduce((acc, e) => {
                acc[e] = { userId: e, posts: 0 }
                return acc
            }, {})
            
            data.forEach(e => {
                if (userIds.includes(e.id)) {
                    userMapping[e.id].posts ++
                }
            })

            const result = Object.values(userMapping)
            console.log(result)
        })
        .catch(console.error)
}

ex3([1, 3, 5])
