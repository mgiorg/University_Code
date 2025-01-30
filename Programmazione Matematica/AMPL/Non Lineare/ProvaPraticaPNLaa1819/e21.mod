# Modello per la Parte 1: Funzione quadratica con termini lineari
set PUNTI;
param x1{PUNTI};
param x2{PUNTI};
param x3{PUNTI};
param y{PUNTI};

var a1;
var a2;
var a3;
var m1;
var m2;
var m3;
var q;
var e{PUNTI};                   # Errori

minimize ErroreNorma2_1: sum{p in PUNTI} e[p]^2;

subject to CalcolaErrore_1{p in PUNTI}:
    e[p] = a1 * x1[p]^2 + a2 * x2[p]^2 + a3 * x3[p]^2 +
           m1 * x1[p] + m2 * x2[p] + m3 * x3[p] + q - y[p];
