set PRODOTTI;
set INGREDIENTI;
set QUALITA;
set REPARTI;

param Prezzo{PRODOTTI};
param Costo_base{PRODOTTI};
param Costo_i{INGREDIENTI};
param Composizione{QUALITA,INGREDIENTI};
param MinQualita{QUALITA,PRODOTTI};
param MaxQualita{QUALITA,PRODOTTI};
param LimMin{PRODOTTI};
param LimMax{PRODOTTI};
param Consumo{REPARTI,PRODOTTI};
param Budget{REPARTI};
param PercMax{PRODOTTI};

var Quantita_p{p in PRODOTTI} >= LimMin[p], <= LimMax[p];
var Quantita_i{INGREDIENTI,PRODOTTI} >= 0;

maximize profitto:
 sum{p in PRODOTTI} (Prezzo[p]-Costo_base[p])*Quantita_p[p]
 - sum{p in PRODOTTI, i in INGREDIENTI} Costo_i[i]*Quantita_i[i,p];

subject to quantita_ingredienti {p in PRODOTTI}:
 sum{i in INGREDIENTI} Quantita_i[i,p] >= Quantita_p[p];

subject to qualita_prodotti_min {q in QUALITA, p in PRODOTTI}:
 MinQualita[q,p]*Quantita_p[p] <=
 sum{i in INGREDIENTI} Composizione[q,i]*Quantita_i[i,p];

subject to qualita_prodotti_max {q in QUALITA, p in PRODOTTI}:
 sum{i in INGREDIENTI} Composizione[q,i]*Quantita_i[i,p] <=
 MaxQualita[q,p]*Quantita_p[p];

subject to tempi_reparti {r in REPARTI}:
 sum{p in PRODOTTI} Consumo[r,p]*Quantita_p[p] <= Budget[r];

subject to percentuali_massime {p in PRODOTTI}:
 Quantita_p[p] <= PercMax[p]*sum{k in PRODOTTI} Quantita_p[k];
