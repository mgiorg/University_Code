
# Modello per la Parte 3: Approssimazione quadratica minimizzando \|e\|_2^2
set PUNTI;
param x1{PUNTI};
param x2{PUNTI};
param x3{PUNTI};
param y{PUNTI};

var a1;
var a2;
var a3;
var c;  # Parametri della funzione quadratica
var eq{PUNTI};      # Errori quadratici

minimize ErroreNorma2Quad: sum{p in PUNTI} eq[p]^2;

subject to CalcolaErroreQuad{p in PUNTI}:
    eq[p] = a1 * x1[p]^2 + a2 * x2[p]^2 + a3 * x3[p]^2 + c - y[p];
