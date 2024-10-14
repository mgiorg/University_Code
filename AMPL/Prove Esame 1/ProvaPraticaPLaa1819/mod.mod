set STAB;
set REP;
set PROD;
set MATERIE;

param Prezzi{PROD};
param ConsumoMinuti{PROD, REP};
param DispOre{STAB, REP};
param ConsumoMaterie{PROD, MATERIE};
param DispMassima{STAB, MATERIE};
param MinBound{PROD, STAB};
param MaxBound{PROD, STAB};
param MinPerc{PROD} default 0;
param MaxPerc{PROD} default 1;
param MinPercCagliari:= 0.35;
param MaxPercMilano:= 0.35;

var Quantita{p in PROD, s in STAB} >= MinBound[p,s], <= MaxBound[p,s];

maximize profitto:
	sum{p in PROD, s in STAB} Prezzi[p] * Quantita[p,s];

subject to disp_ore {s in STAB, r in REP}:
	sum{p in PROD} ConsumoMinuti[p,r]*Quantita[p,s] <= DispOre[s,r] * 60;
subject to materie_prime {m in MATERIE, s in STAB}:
	sum{p in PROD} Quantita[p,s]*ConsumoMaterie[p,m] <= DispMassima[s,m];
subject to min_perc {p in PROD}:
	MinPerc[p]*sum{s in STAB, k in PROD}Quantita[k,s] <= sum{s in STAB} Quantita[p,s];
subject to max_perc {p in PROD}:
	MaxPerc[p]*sum{s in STAB, k in PROD}Quantita[k,s] >= sum{s in STAB} Quantita[p,s];
subject to minCagliari:
	sum{p in PROD} Quantita[p, 'Cagliari'] >= MinPercCagliari*sum{p in PROD, s in STAB} Quantita[p,s];
subject to maxMilano:
	sum{p in PROD} Quantita[p, 'Milano'] <= MaxPercMilano*sum{p in PROD, s in STAB} Quantita[p,s];