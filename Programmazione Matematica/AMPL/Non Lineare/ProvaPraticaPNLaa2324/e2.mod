set RENNE;

param L; 
param H; 

param r_min{RENNE};  # Raggio minimo per ogni recinto
param pi := 3.14159265358979;

var x{RENNE} >= 0, <= L;  # Coordinata x del centro del recinto
var y{RENNE} >= 0, <= H;  # Coordinata y del centro del recinto
var r{i in RENNE} >= r_min[i];        # Raggio del recinto

# Funzione obiettivo: Massimizzare la somma delle aree dei recinti
maximize AreaTotale: sum{i in RENNE} pi * r[i]^2;

# Vincolo: Ogni recinto deve stare all'interno del rettangolo
subject to DentroRettangolo1{i in RENNE}:
    x[i] + r[i] <= L;

subject to DentroRettangolo2{i in RENNE}:
    r[i] <= x[i];

subject to DentroRettangolo3{i in RENNE}:
    y[i] + r[i] <= H;

subject to DentroRettangolo4{i in RENNE}:
   r[i] <= y[i];

# Vincolo: Distanza minima tra i centri dei recinti (20 m)
subject to DistanzaMinima{j in RENNE, k in RENNE: j != k}:
    (x[j] - x[k])^2 + (y[j] - y[k])^2 >= (20 + r[j] + r[k])^2;
