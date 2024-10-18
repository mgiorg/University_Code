set PRODOTTI;
set INGREDIENTI;
set QUALITA;

param Prezzo{PRODOTTI};
param Costo_base{PRODOTTI};
param Quantita_p{PRODOTTI};
param Costo_i{INGREDIENTI};
param Composizione{QUALITA,INGREDIENTI};
param MinQualita{QUALITA,PRODOTTI};
param MaxQualita{QUALITA,PRODOTTI};

var Quantita_i{INGREDIENTI,PRODOTTI} >= 0;

maximize profitto:
 sum{p in PRODOTTI} (Prezzo[p]-Costo_base[p])*Quantita_p[p] 
 - sum{p in PRODOTTI, i in INGREDIENTI} Costo_i[i]*Quantita_i[i,p];

subject to quantita_ingredienti {p in PRODOTTI}:
 sum{i in INGREDIENTI} Quantita_i[i,p] >= Quantita_p[p];

subject to qualita_prodotti {q in QUALITA, p in PRODOTTI}:
 MinQualita[q,p]*Quantita_p[p] <=
 sum{i in INGREDIENTI} Composizione[q,i]*Quantita_i[i,p] <=
 MaxQualita[q,p]*Quantita_p[p];
