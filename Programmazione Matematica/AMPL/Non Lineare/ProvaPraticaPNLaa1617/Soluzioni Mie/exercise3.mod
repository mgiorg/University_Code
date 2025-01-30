# Modello per posizionare la fonte di luce minimizzando la distanza cumulativa
set PUNTI;
param X{PUNTI};
param Y{PUNTI};
param Z{PUNTI};

var x_luce;
var y_luce;
var z_luce; # Coordinate della fonte di luce
var dist{PUNTI} >= 0;       # Distanza dalla fonte ai punti

# Funzione obiettivo: minimizzare la somma delle distanze (norma 2 cumulativa)
minimize DistanzaCumulativa: sum{p in PUNTI} dist[p];

# Calcolo delle distanze per ogni punto
subject to CalcolaDistanze{p in PUNTI}:
    dist[p]^2 = (X[p] - x_luce)^2 + (Y[p] - y_luce)^2 + (Z[p] - z_luce)^2;

# Vincolo: la fonte di luce non può essere più lontana di 2 dal punto D
subject to VincoloDistMax:
    (X["D"] - x_luce)^2 + (Y["D"] - y_luce)^2 + (Z["D"] - z_luce)^2 <= 2^2;
