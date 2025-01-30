set PUNTI;

param x1{PUNTI};
param x2{PUNTI};
param x3{PUNTI};
param y{PUNTI};

var a12;
var m1;
var m2;
var m3;
var q;

# Funzione obiettivo: Minimizzare l'errore quadratico
minimize Errore:
    sum{i in PUNTI} (a12 * x1[i] * x2[i] + m1 * x1[i] + m2 * x2[i] + m3 * x3[i] + q - y[i])^2;
