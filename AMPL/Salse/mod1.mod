set PROD;
set ING;
set QUAL;

param Prezzo{PROD};
param CostoBase{PROD};
param Q_Prodotto{PROD};
param CostoIng{ING};
param Carat{QUAL,ING};
param MinC{QUAL,PROD};
param MaxC{QUAL,PROD};

var Quantita{ING,PROD} >= 0;

maximize profitto:
	sum{p in PROD} (Prezzo[p]-CostoBase[p])*Q_Prodotto[p] 
	- sum{p in PROD, i in ING} CostoIng[i]*Quantita[i,p];

subject to maxIngredienti {p in PROD}:
	sum{i in ING} Quantita[i,p] >= Q_Prodotto[p];

subject to requisiti {q in QUAL, p in PROD}:
	MinC[q,p]*Q_Prodotto[p] <= sum{i in ING}Carat[q,i]*Quantita[i,p] <=MaxC[q,p]*Q_Prodotto[p];