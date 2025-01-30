set RENNE;

param LatoX;  # Larghezza rettangolo
param LatoY;  # Altezza rettangolo
param DistanzaMin;  # Distanza minima tra centri
param RaggioMin{RENNE};  # Raggio minimo per ogni recinto
param pi := 3.14159265358979;

var CentroRecintoX{RENNE} >= 0, <= LatoX;  # Coordinata X dei centri
var CentroRecintoY{RENNE} >= 0, <= LatoY;  # Coordinata Y dei centri
var RaggioRecinto{i in RENNE} >= RaggioMin[i];  # Raggio dei recinti
var z;

# Funzione obiettivo: Massimizzare la somma delle aree dei recinti
maximize area_min: z;

subject to ausiliari {i in RENNE}:
	z <= pi * RaggioRecinto[i]^2;

# Vincolo: Ogni recinto deve stare all'interno del rettangolo
subject to Bordi_X1{i in RENNE}:
    RaggioRecinto[i] <= CentroRecintoX[i];

subject to Bordi_X2{i in RENNE}:
    CentroRecintoX[i] + RaggioRecinto[i] <= LatoX;

subject to Bordi_Y1{i in RENNE}:
    RaggioRecinto[i] <= CentroRecintoY[i];

subject to Bordi_Y2{i in RENNE}:
    CentroRecintoY[i] + RaggioRecinto[i] <= LatoY;

# Vincolo: Distanza minima tra i centri dei recinti
subject to DistanzaMinima{i in RENNE, j in RENNE: i != j}:
    (CentroRecintoX[i] - CentroRecintoX[j])^2 + 
    (CentroRecintoY[i] - CentroRecintoY[j])^2 >= 
    (RaggioRecinto[i] + RaggioRecinto[j] + DistanzaMin)^2;

