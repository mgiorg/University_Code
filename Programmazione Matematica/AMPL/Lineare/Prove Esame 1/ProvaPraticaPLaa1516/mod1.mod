set SAPONI;
set REPARTI;

param prezzo{SAPONI}; #kg
param maxQuantita{SAPONI};
param maxOre{REPARTI}; #ore
param dispTempo{SAPONI, REPARTI}; #minuti
param maxGli;
param maxGra;
param glicerina{SAPONI};
param grassi{SAPONI};

var Quantita{s in SAPONI} >= 500, <= maxQuantita[s]; #kg

maximize profitto:
	sum{s in SAPONI} Quantita[s]*prezzo[s];

subject to perc1:
	Quantita['neu'] >= 0.2*sum{s in SAPONI} Quantita[s];
subject to perc2:
	Quantita['ant'] <= 0.3*sum{s in SAPONI} Quantita[s];

subject to tempo {r in REPARTI}:
	sum{s in SAPONI} Quantita[s]*(dispTempo[s,r]/100) <= maxOre[r]*60;
subject to maxGlicerina:
	sum{s in SAPONI} Quantita[s]*(glicerina[s]/100) <= maxGli;
subject to maxGrassi:
	sum{s in SAPONI} Quantita[s]*(grassi[s]/100) <= maxGra;