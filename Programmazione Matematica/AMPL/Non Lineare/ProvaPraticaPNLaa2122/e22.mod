set PUNTI;

param x1{PUNTI};
param x2{PUNTI};
param x3{PUNTI};
param y{PUNTI};

# Variabili da determinare
var c1;   # Coefficiente di x1^2
var c2;   # Coefficiente di x2^2
var c3;   # Coefficiente di x3^2
var c4;   # Coefficiente di x1*x2
var c5;   # Coefficiente di x2*x3
var c6;   # Coefficiente di x1*x3
var c7;   # Coefficiente di x1
var c8;   # Coefficiente di x2
var c9;   # Coefficiente di x3
var c10;  # Coefficiente costante

# Funzione obiettivo: Minimizzare l'errore quadratico totale
minimize Errore:
    sum{i in PUNTI} (c1 * x1[i]^2 + c2 * x2[i]^2 + c3 * x3[i]^2 +
                     c4 * x1[i] * x2[i] + c5 * x2[i] * x3[i] + c6 * x1[i] * x3[i] +
                     c7 * x1[i] + c8 * x2[i] + c9 * x3[i] + c10 - y[i])^2;
