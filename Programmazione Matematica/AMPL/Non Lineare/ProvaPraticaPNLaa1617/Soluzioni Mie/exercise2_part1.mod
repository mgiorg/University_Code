
# Modello per la Parte 1: Approssimazione lineare minimizzando \|e\|_2^2
set PUNTI;
param x1{PUNTI};
param x2{PUNTI};
param x3{PUNTI};
param y{PUNTI};

var m1;
var m2;
var m3;
var q;
var e{PUNTI};       # Errori

minimize ErroreNorma2: sum{p in PUNTI} e[p]^2;

subject to CalcolaErrore{p in PUNTI}:
    e[p] = m1 * x1[p] + m2 * x2[p] + m3 * x3[p] + q - y[p];
