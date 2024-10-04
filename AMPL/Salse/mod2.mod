set PROD;
set ING;
set QUAL;
set REP;

param Prezzo{PROD};
param CostoBase{PROD};
param LimiteMin{PROD};
param LimiteMax{PROD};
param Consumi{REP,PROD};
param CostoIng{ING};
param Carat{QUAL,ING};
param MinC{QUAL,PROD};
param MaxC{QUAL,PROD};
param Budget{REP};
param PercMin{PROD};

var Quantita_p{i in PROD} >= LimiteMin[i], <= LimiteMax[i];
var Quantita_i{ING,PROD} >= 0;

maximize profitto:
	sum{p in PROD} (Prezzo[p]-CostoBase[p])*Quantita_p[p] 
	- sum{p in PROD, i in ING} CostoIng[i]*Quantita_i[i,p];

#Vincoli della parte 1
subject to maxProduzione{j in PROD}:
	Quantita_p[j] <= PercMin[j]*sum{i in PROD}Quantita_p[i];
subject to maxTempo {j in REP}:
	sum{i in PROD} Quantita_p[i] * Consumi[j,i] <= Budget[j];
	
#Vincoli della parte 2
subject to maxIngredienti {p in PROD}:
	sum{i in ING} Quantita_i[i,p] >= Quantita_p[p];

subject to requisitiMin {q in QUAL, p in PROD}:
	MinC[q,p]*Quantita_p[p] <= sum{i in ING}Carat[q,i]*Quantita_i[i,p];
subject to requisitiMax {q in QUAL, p in PROD}:
	sum{i in ING}Carat[q,i]*Quantita_i[i,p] <=MaxC[q,p]*Quantita_p[p];
	