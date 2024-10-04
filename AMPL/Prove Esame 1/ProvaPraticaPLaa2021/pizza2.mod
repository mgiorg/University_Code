set FARINE0;
set FARINEINT;
set FARINE = FARINE0 union FARINEINT;
set OLI;
set INGREDIENTI := FARINE union OLI;
set QUALITA;

param QtaFarina; # grammi
param QtaOlio; # grammi
param Costo{INGREDIENTI};  # al kg
param Contenuto{INGREDIENTI,QUALITA}; # per 100 grammi
param RequisitiMin{QUALITA}; # grammi per teglia
param RequisitiMax{QUALITA}; # grammi per teglia
param PercMinIntegrale;
param ub{INGREDIENTI}; # grammi

var Qta{i in INGREDIENTI} >= 0, <= ub[i]; # grammi

minimize costo_teglia:
  sum{i in INGREDIENTI} (Costo[i]/1000)*Qta[i];

subject to qta_farina:
  sum{i in FARINE} Qta[i] = QtaFarina;

subject to qta_olio:
  sum{i in OLI} Qta[i] = QtaOlio;

subject to requisiti {j in QUALITA}:
  RequisitiMin[j] <= sum{i in INGREDIENTI} (Contenuto[i,j]/100)*Qta[i] <= RequisitiMax[j];

subject to integrale:
  sum{i in FARINEINT} Qta[i] >= PercMinIntegrale * sum{i in FARINE} Qta[i];

