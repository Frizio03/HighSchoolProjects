# Contenuto repository:
- Gestire un progetto JS
- Cosa sono i moduli - tipologie
- Esportare funzioni da un modulo
- Importare funzioni in un file tramite require()

*Gestire un progetto JS*
> Gestire un progetto di JavaScript spesso richiede ordine e chiarezza, per tale motivo spesso riuslta utile articolare il codice su diversi file. Quanto detto viene reso possibile dai moduli di JavaScript

*Module-methods - tipologie*
> Per utilizare i moduli in JS esistono vari metodi fra cui il module-method (node v.14) ancora in via di sviluppo. In questa repository tratteremo solo il metodo require()

*Esportare funzioni da un modulo*
```sh
module.exports.nuovoNomeFunzione = nomeFunzione
```

*Importare funzioni da un modulo*
```sh
const nomeLibreria = require("./nomeFile.js")
```