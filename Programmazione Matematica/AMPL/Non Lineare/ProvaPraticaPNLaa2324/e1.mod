set FABBRICHE;

param X{FABBRICHE};  # Coordinate X delle fabbriche
param Y{FABBRICHE};  # Coordinate Y delle fabbriche

var x1 >= 0;
var y1 >= 0;  # Coordinate del bastone 1
var x2 >= 0;
var y2 >= 0;  # Coordinate del bastone 2
var d{FABBRICHE} >= 0;  # Variabile unica per la distanza di ciascuna fabbrica

# Funzione obiettivo: Minimizzare la somma delle distanze minime
minimize SommaDistanze: sum{i in FABBRICHE} d[i];

# Vincolo: Calcolo della distanza minima tra i bastoni
subject to CalcolaDistanza1{i in FABBRICHE}:
    d[i]^2 >= (X[i]-x1)^2 + (Y[i]-y1)^2;

subject to CalcolaDistanza2{i in FABBRICHE}:
    d[i]^2 >= (X[i]-x2)^2 + (Y[i]-y2)^2;

# Vincolo: I due bastoni devono distare almeno 500 km
subject to DistanzaTraBastoni:
    (x1 - x2)^2 + (y1 - y2)^2 >= 500^2;
