set SAPONI;
set REPARTI;
set MATERIE;

param prezzo{SAPONI}; #kg
param maxQuantita{SAPONI};
param maxOre{REPARTI}; #ore
param dispTempo{SAPONI, REPARTI}; #minuti
param maxGli;
param maxGra;
param Consumo{SAPONI,MATERIE};
param Dispon{MATERIE};

var Quantita{SAPONI,MATERIE} >= 0; #kg

maximize profitto:
	sum{s in SAPONI, m in MATERIE} Quantita[s,m]*prezzo[s];

subject to perc1:
	sum{m in MATERIE}Quantita['neu',m] >= 0.2*sum{s in SAPONI, m in MATERIE} Quantita[s,m];
subject to perc2:
	sum{m in MATERIE}Quantita['ant',m] <= 0.3*sum{s in SAPONI, m in MATERIE} Quantita[s,m];

subject to bound {s in SAPONI}:
	500 <= sum{m in MATERIE}Quantita[s,m] <= maxQuantita[s];

subject to tempo {r in REPARTI}:
	sum{s in SAPONI, m in MATERIE} Quantita[s,m]*(dispTempo[s,r]/100) <= maxOre[r]*60;
subject to risorse_materie {m in MATERIE}:
	sum{s in SAPONI} (Consumo[s,m]/100)*Quantita[s,m] <= Dispon[m];
	