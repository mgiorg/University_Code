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

var x{SAPONI,MATERIE} >= 0;

maximize ricavo:
  sum{i in SAPONI, k in MATERIE} Prezzo[i]*x[i,k];

subject to risorse_reparti {j in REPARTI}:
  sum{i in SAPONI, k in MATERIE} (Tempo[i,j]/100)*x[i,k] <= 60*TempoMax[j];

subject to risorse_materie {k in MATERIE}:
  sum{i in SAPONI} (Consumo[i,k]/100)*x[i,k] <= Dispon[k];

subject to perc_min {i in SAPONI}:
  sum{k in MATERIE} x[i,k] >= PercMin[i]*sum{s in SAPONI, k in MATERIE} x[s,k];

subject to perc_max {i in SAPONI}:
  sum{k in MATERIE} x[i,k] <= PercMax[i]*sum{s in SAPONI, k in MATERIE} x[s,k];

subject to bound {i in SAPONI}:
  QtaMin <= sum{k in MATERIE} x[i,k] <= QtaMax[i];






