set SMART;
set ROBOT;

param minPerc{SMART};
param maxPerc{SMART};
param minQ{SMART};
param maxQ{SMART};

param Dispon{ROBOT};	#ore
param Profitto{SMART};	
param Consumo{ROBOT,SMART};	#minuti

var Quantita{i in SMART} >= minQ[i], <= maxQ[i];

maximize profitto_tot:
	sum{i in SMART} Profitto[i] *  Quantita[i];

subject to tempo {j in ROBOT}:
	sum{i in SMART} Consumo[j,i] * Quantita[i] <= Dispon[j]*60;

subject to perc_min {i in SMART}:
	Quantita[i] >= minPerc[i] * sum{k in SMART} Quantita[k];
subject to perc_max {i in SMART}:
	Quantita[i] <= maxPerc[i] * sum{k in SMART} Quantita[k];