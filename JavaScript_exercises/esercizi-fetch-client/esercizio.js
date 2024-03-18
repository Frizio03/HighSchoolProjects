//variabili e require
const IP = "http://192.168.178.33:8080"
const f = require("./fetch-funct.js")

//Esercizi

const Es1 = (nes) => {
    let soluzione = null
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            soluzione = data.toLowerCase(),

            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es2 = (nes) => {
    let soluzione = null
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            soluzione = data*data

            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es3 = (nes) => {
    let soluzione = null
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            soluzione = data["cognome"]

            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es4 = (nes) => {
    let soluzione = null
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            soluzione = data.length
            console.log(soluzione)
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es5 = (nes) => {
    let soluzione = [];
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            data.forEach((el) => {soluzione.push(el.toUpperCase())})
            console.log(soluzione)
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es6 = (nes) => {
    let soluzione = null
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            soluzione = data.reduce((acc, el) => {return acc+el}, 0)
            console.log(soluzione)
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es7 = (nes) => {
    let v = [];
    let soluzione = 0
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            v = data.filter((elemento) => {
                if (elemento > 5)
                    return true
                else 
                    return false
                })
            soluzione = v.reduce((acc, el) => {return acc+el}, 0)
            console.log(soluzione)
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es8 = (nes) => {
    let v = [];
    let soluzione = 0
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            v = data.filter((elemento, indice) => {
                if (indice%2 === 0)
                    return true
                else 
                    return false
                })
            soluzione = v.reduce((acc, el) => {return acc+el}, 0)
            console.log(soluzione)
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es9 = (nes) => {
    let v = [];
    let soluzione = 0
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            v = data.filter((elemento) => {
                if (elemento%2 !== 0)
                    return true
                else 
                    return false
                })
            soluzione = v.reduce((acc, el) => {return acc+el}, 0)
            console.log(soluzione)
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es10 = (nes) => {
    let soluzione = null
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            soluzione = data.sort()
            console.log(soluzione)
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es11 = (nes) => {
    let soluzione = null
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            soluzione = data.map(e => e.toLowerCase())
            f.tentaEsercizio(IP, nes, soluzione.sort())
        })
        .catch(err => console.log(err))
}

const Es12 = (nes) => {
    let soluzione = null
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            soluzione = data.map(e => e -= 1)
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es13 = (nes) => {
    let soluzione = null
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            for(let i=0; i<data.length; i++){
                if(i !== (data.length-1)){
                    data[i] += data[i+1]
                }
            }
            f.tentaEsercizio(IP, nes, data)
        })
        .catch(err => console.log(err))
}

const Es14 = (nes) => {
    let soluzione = {positivi: 0, negativi: 0, zeri: 0}
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            data.forEach(e => {
                if(e === 0){soluzione.zeri+=1}
                else if (e>=0){soluzione.positivi +=1}
                else {soluzione.negativi +=1}
            })
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es15 = (nes) => {
    let soluzione = [];
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            for(let i=0; i<data.length; i++){
                if(data[i].length%2 === 0){
                    soluzione.push(data[i].toUpperCase())
                }
                else{
                    soluzione.push(data[i].toLowerCase())
                }
            }
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es16 = (nes) => {
    let soluzione = ""
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            data.forEach(e => {
                soluzione = soluzione + e + " "
            })
            len = soluzione.length
            soluzione = soluzione.substring(0, len-1)
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es17 = (nes) => {
    let soluzione = ""
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            data.forEach(e => {
                soluzione = soluzione + e[e.length-1]
            })
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es18 = (nes) => {
    let soluzione = ""
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            data.forEach(e => {
                if(e.length>4){
                    soluzione = soluzione + e[0]
                }
            })
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es19 = (nes) => {
    let soluzione = [];
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            for(let i=1; i<data+1; i++){
                if(data%i === 0){
                    soluzione.push(i)
                }
            }
            f.tentaEsercizio(IP, nes, soluzione.sort())
        })
        .catch(err => console.log(err))
}

const Es20 = (nes) => {
    let soluzione = [];
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            data.forEach(e => soluzione.push(e.figli.length))
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es21 = (nes) => {
    let soluzione = [];
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            soluzione = data.filter(e => e <= 5)
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es22 = (nes) => {
    let soluzione = [];
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            soluzione = data.filter(e => e >= 3 && e <=6)
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es23 = (nes) => {
    let soluzione = null
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            data2 = data.map(e => e.anni)
            soluzione = data2.reduce((acc, e) => {
                return acc + e
            })
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es24 = (nes) => {
    let soluzione = [];
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            for(let i=0; i<data.length; i++){
                if(data[i].cognome[0] === "C")
                    soluzione.push(data[i].nome)
            }
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es25 = (nes) => {
    let soluzione = null
    f.richiediEsercizio(IP, nes)
        .then(data => {
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            console.log(data)
            for(let i=0; i<data.length; i++){
                for(let j=0; j<data[i].length; j++){
                    if(data[i][j] === "a")
                        soluzione +=1
                }
            }
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es26 = (nes) => {
    let soluzione = [];
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            soluzione = data.map(e => e = e*-1)
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es27 = (nes) => {
    let soluzione = [];
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            console.log(data)
            data.negozio.forEach(e => {
                soluzione.push(e)
            })
            data.magazzino.forEach(e => {
                soluzione.push(e)
            })
            sol = soluzione.sort()
            
            for(i=0; i<sol.length; i++){
                if(sol[i] === sol[i+1])
                    sol.splice(i, 1)
            }
            
            f.tentaEsercizio(IP, nes, soluzione.sort())
        })
        .catch(err => console.log(err))
}

const Es28 = (nes) => {
    let dict = {};
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            //console.log(data)
            
            data.negozio.forEach(e => {
                dict[e] = 0
            })
            
            v = data.negozio.sort()
            for(i=0; i<v.length; i++){
                if(v[i] === v[i+1]){
                    x = v[i]
                    dict[x] += 1
                    v.splice(i, 1)
                }
            }

            //console.log(data.negozio)

            for(let i=0; i < v.length; i++){
                data.negozio.forEach(el => {
                    if(el === data.negozio[i]){
                        dict[el] += 1
                    }
                })
                data.magazzino.forEach(el => {
                    if(el === data.negozio[i]){
                        dict[el] += 1
                    }
                })
            }

            //console.log(dict)
            f.tentaEsercizio(IP, nes, dict)
        })
        .catch(err => console.log(err))
}

const Es29 = (nes) => {
    let soluzione = 1
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            for(i=1; i<data+1; i++){
                soluzione *= i
            }
            f.tentaEsercizio(IP, nes, soluzione)
        })
        .catch(err => console.log(err))
}

const Es30 = (nes) => {
    let soluzione = {x: 0, y: 0}
    f.richiediEsercizio(IP, nes)
        .then(data => {
            
            /*SCRIVERE QUI IL CODICE PER TROVARE LA SOLUZIONE*/
            //console.log(data)
            let rows = data.split("\n")
            //console.log(rows)
            for(y=0; y<rows.length; y++){
                for(x=0; x<rows[y].length; x++){
                    if(rows[y][x] === "X"){
                        soluzione.x = x
                        soluzione.y = y
                        break
                    }
                }
            }
            console.log(soluzione)
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
module.exports.Es8 = Es8
module.exports.Es9 = Es9
module.exports.Es10 = Es10
module.exports.Es11 = Es11
module.exports.Es12 = Es12
module.exports.Es13 = Es13
module.exports.Es14 = Es14
module.exports.Es15 = Es15
module.exports.Es16 = Es16
module.exports.Es17 = Es17
module.exports.Es18 = Es18
module.exports.Es19 = Es19
module.exports.Es20 = Es20
module.exports.Es21 = Es21
module.exports.Es22 = Es22
module.exports.Es23 = Es23
module.exports.Es24 = Es24
module.exports.Es25 = Es25
module.exports.Es26 = Es26
module.exports.Es27 = Es27
module.exports.Es28 = Es28
module.exports.Es29 = Es29
module.exports.Es30 = Es30