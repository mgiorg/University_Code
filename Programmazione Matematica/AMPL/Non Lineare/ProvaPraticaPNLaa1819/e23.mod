# Modello per la Parte 3: Funzione quadratica senza termini lineari
set PUNTI;
param x1{PUNTI};
param x2{PUNTI};
param x3{PUNTI};
param y{PUNTI};

var a1;
var a2;
var a3;
var q;
var e{PUNTI};       # Errori

minimize ErroreNorma2_3: sum{p in PUNTI} e[p]^2;

subject to CalcolaErrore_3{p in PUNTI}:
    e[p] = a1 * x1[p]^2 + a2 * x2[p]^2 + a3 * x3[p]^2 + q - y[p];
