set PROD;
set REPARTI;

param Ricavo{PROD};
param DomMax{PROD};
param TempoMax{REPARTI};
param Ritmo{PROD,REPARTI};

var Quantita{i in PROD} >= 0, <= DomMax[i];

maximize Profitto:
	sum{i in PROD}Quantita[i]*Ricavo[i];
	
subject to Tempo{j in REPARTI}:
	sum{i in PROD}Quantita[i]*(1/Ritmo[i,j])<= TempoMax[j];
	