
# Modello per la Parte 2: Approssimazione lineare minimizzando \|e\|_\infty
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
var maxErrore >= 0; # Errore massimo (norma infinito)

minimize ErroreNormaInf: maxErrore;

subject to CalcolaErroreInf1{p in PUNTI}:
    e[p] <= maxErrore;

subject to CalcolaErroreInf2{p in PUNTI}:
    -e[p] <= maxErrore;

subject to CalcolaErrore{p in PUNTI}:
    e[p] = m1 * x1[p] + m2 * x2[p] + m3 * x3[p] + q - y[p];
