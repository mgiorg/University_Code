set PRODOTTI;
set REPARTI;

param Prezzo{PRODOTTI};
param Costo{PRODOTTI};
param LimMin{PRODOTTI};
param LimMax{PRODOTTI};
param Consumo{REPARTI,PRODOTTI};
param Budget{REPARTI};
param PercMax{PRODOTTI};

var Quantita_p{p in PRODOTTI} >= LimMin[p], <= LimMax[p];

maximize profitto:
 sum{p in PRODOTTI} (Prezzo[p]-Costo[p])*Quantita_p[p];

subject to tempi_reparti {r in REPARTI}:
 sum{p in PRODOTTI} Consumo[r,p]*Quantita_p[p] <= Budget[r];

subject to percentuali_massime {p in PRODOTTI}:
 Quantita_p[p] <= PercMax[p]*sum{k in PRODOTTI} Quantita_p[k];
