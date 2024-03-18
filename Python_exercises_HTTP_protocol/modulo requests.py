import requests

url = "http://192.168.1.231:8080/esercizio1"
headers = {"content-type": "application/json"}

r = requests.get(url)
body = r.json()

print(body["consegna"])
print(body["dati"])

risultato = sum(body["dati"])

body = {"data": risultato}

response = request.post(url, headers = headers, data = risultato)

body = r.json()
print(body)