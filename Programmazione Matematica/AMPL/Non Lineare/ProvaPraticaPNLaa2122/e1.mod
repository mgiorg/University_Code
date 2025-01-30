param SuperficieTotale := 10;  # Materiale disponibile in mq
param MinDim := 0.3;          # Dimensioni minime in metri

var h1 >= MinDim;
var l1 >= MinDim;
var p1 >= MinDim;  # Dimensioni scatola 1
var h2 >= MinDim;
var l2 >= MinDim;
var p2 >= MinDim;  # Dimensioni scatola 2
var h3 >= MinDim;
var l3 >= MinDim;
var p3 >= MinDim;  # Dimensioni scatola 3

# Funzione obiettivo: Massimizzare il volume totale
maximize VolumeTotale:
    h1 * l1 * p1 + h2 * l2 * p2 + h3 * l3 * p3;

# Vincolo: Altezza della prima scatola doppia rispetto alla seconda
subject to Altezza1:
    h1 = 2 * h2;

# Vincolo: Superficie totale disponibile
subject to SuperficieTotaleVincolo:
    2 * (h1 * l1 + h1 * p1 + l1 * p1) +
    2 * (h2 * l2 + h2 * p2 + l2 * p2) +
    2 * (h3 * l3 + h3 * p3 + l3 * p3) <= SuperficieTotale;
