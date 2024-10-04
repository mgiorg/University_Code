set PROD;
set REPARTI;

param Profitto{PROD};
param Consumo{REPARTI,PROD};
param Dispon{REPARTI};

var Quantita{PROD} >= 0;

maximize profitto_tot:
 sum{i in PROD} Profitto[i]*Quantita[i];

subject to risorsa_tempo {j in REPARTI}:
 sum{i in PROD} Consumo[j,i]*Quantita[i] <= Dispon[j];
