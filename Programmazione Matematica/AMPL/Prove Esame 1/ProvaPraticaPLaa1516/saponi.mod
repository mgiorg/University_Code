set SAPONI;
set REPARTI;
set MATERIE;

param Prezzo{SAPONI};
param QtaMin;
param QtaMax{SAPONI};
param TempoMax{REPARTI};
param Tempo{SAPONI,REPARTI};
param Dispon{MATERIE};
param Consumo{SAPONI,MATERIE};
param PercMin{SAPONI} default 0;
param PercMax{SAPONI} default 1;

var x{i in SAPONI} >= QtaMin, <= QtaMax[i];

maximize ricavo:
  sum{i in SAPONI} Prezzo[i]*x[i];

subject to risorse_reparti {j in REPARTI}:
  sum{i in SAPONI} (Tempo[i,j]/100)*x[i] <= 60*TempoMax[j];

subject to risorse_materie {k in MATERIE}:
  sum{i in SAPONI} (Consumo[i,k]/100)*x[i] <= Dispon[k];

subject to perc_min {i in SAPONI}:
  x[i] >= PercMin[i]*sum{s in SAPONI} x[s];

subject to perc_max {i in SAPONI}:
  x[i] <= PercMax[i]*sum{s in SAPONI} x[s];



