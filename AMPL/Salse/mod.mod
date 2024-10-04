set PROD;
set REP;

param Prezzo{PROD};
param Costo{PROD};
param LimiteMin{PROD};
param LimiteMax{PROD};
param Consumi{REP,PROD};
param Budget{REP};
param PercMin{PROD};

var Quantita{i in PROD} >= LimiteMin[i], <= LimiteMax[i];

maximize profitto:
	sum{i in PROD} (Prezzo[i]-Costo[i])*Quantita[i];

subject to maxProduzione{j in PROD}:
	Quantita[j] <= PercMin[j]*sum{i in PROD}Quantita[i];
subject to maxTempo {j in REP}:
	sum{i in PROD} Quantita[i] * Consumi[j,i] <= Budget[j];