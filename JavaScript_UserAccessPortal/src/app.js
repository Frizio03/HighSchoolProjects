const path = require('path')
const express = require('express')
const hbs = require('hbs')
const mysql = require('mysql')
const dotenv = require('dotenv')
const bodyParser = require('body-parser')

const app = express()

// Define paths for Express config
const publicDirectoryPath = path.join(__dirname, '../public')
const viewsPath = path.join(__dirname, '../templates/views')
const partialsPath = path.join(__dirname, '../templates/partials')
dotenv.config({ path: './.env' })

// Setup handlebars engine and views location
app.set('view engine', 'hbs')
app.set('views', viewsPath)
app.use(express.json())
app.use(express.urlencoded({extended: true}))
hbs.registerPartials(partialsPath)

//Setup DB connection
const db = mysql.createConnection({
    host: process.env.MYSQL_HOST,
    user: process.env.USER,
    password: process.env.PASSWORD,
    database: "test",
    port: process.env.MYSQL_PORT
  })
  db.connect((err) => {
    if (err) throw err
    console.log('DB connected!')
  })

//Define functions
const dbQuery = (queryString) => {
return new Promise((resolve) => {
    db.query(queryString, (error, result) => {
    if (error) {
        throw error
    } else {
        resolve(result)
    }
    })
})
}

const loginUser = async (req, res) => {
    try {
      const users = await dbQuery(
        `SELECT * FROM Persons WHERE email="${req.email}"`
      )
      //console.log(req.psw)
      userData = users[0]
      //console.log(userData)
      if (req.email === userData.email && req.psw === userData.password) {
        res.render('userData', {
          email: userData.email,
          firstName: userData.firstName,
          lastName: userData.lastName,
          city: userData.city
        })
      } else{
        res.render('error', { errorMessage: 'Incorrect username or password' })
      }
    } catch (err) {
      console.log(err)
      res.render('signup', { errorMessage: 'An error has occurred. Incorrect username or password' })
    }
  }

  const subscribeUser = async (req, res) => {
    try {
      const users = await dbQuery(
        `SELECT * FROM Persons WHERE email="${req.email}"`
      )
      userData = users[0]
      console.log(users)
      if(users === []){
        res.render('error', { errorMessage: 'This email is already subscribed' })
      }
      else{
        await dbQuery(
          `INSERT INTO Persons (firstName, lastName, city, email, password)
          VALUES ("${req.name}", "${req.surname}", "${req.city}", "${req.email}", "${req.psw}")`
        )
        res.render('success', {message: "User succesfully subscribed!!"})
      }
    } catch (err) {
      console.log(err)
      res.render('signup', { message: 'An error has occurred. Please try again' })
    }
  }

const seeder = () => {
  dbQuery(`DROP TABLE Persons`)
  dbQuery(
      `CREATE TABLE IF NOT EXISTS Persons (
      personID int UNIQUE NOT NULL AUTO_INCREMENT,
      lastName varchar(255),
      firstName varchar(255),
      city varchar(255),
      email varchar(255) UNIQUE NOT NULL,
      password varchar(255)
      )`
  )
  dbQuery(
    `DELETE FROM Persons`
  )
  dbQuery(
    `INSERT INTO Persons (firstName, lastName, city, email, password)
    VALUES ("Mario", "Rossi", "Reggio Emilia", "mario.rossi@gmail.com", "red")`
  )
  dbQuery(
    `INSERT INTO Persons (firstName, lastName, email, password)
    VALUES ("Fabrizio", "Tedeschi", "fabri.tedeschi@gmail.com", "sdjfhsd67ge89de9")`
  )
  dbQuery(
    `INSERT INTO Persons (firstName, lastName, email, password)
    VALUES ("Gianluca", "Ghinazzi", "gian.luca@hotmail.it", "1234")`
  )
  dbQuery(
    `INSERT INTO Persons (firstName, lastName, city, email, password)
    VALUES ("Luca", "Bianchi", "Milano", "luca.bianchi@gmail.com", "white")`
  )
  console.log("Tables created and seeded")
}

seeder()

// Setup static directory to serve
app.use(express.static(publicDirectoryPath))

app.get('', (req, res) => {
    res.render('index', {
        logoPath: "./public/img/lock.png",
        title: 'User Acces Portal',
        author: 'Fabri e Gianlu'
    })
})

app.get('/login', (req, res) => {
    res.render('login', {
        title: "User Acces Portal",
        messaggio: 'Hello! Login NOW!',
        author: 'Fabri e Gianlu'
    })
})

app.post('/login', (req, res) => {
    //console.log(req.body)
    loginUser(req.body, res)
})

app.get('/signup', (req, res) => {
    res.render('signup', {
        title: "User Acces Portal",
        author: 'Fabri e Gianlu'
    })
})

app.post('/signup', (req, res) => {
  console.log(req.body)
  subscribeUser(req.body, res)
})


app.get('*', (req, res) => {
    res.render('404', {
        title: '404',
        name: 'Andrew Mead',
        errorMessage: 'Page not found.'
    })
})

const port = 8080
app.listen(port, () => {
    console.log('Server is up on port ' + port)
})