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

var Quantita{PROD, STAB, MATERIE} >= 0;

subject to bound {p in PROD, s in STAB}:
	MinBound[p,s] <= sum{m in MATERIE} Quantita[p,s,m] <= MaxBound[p,s];

maximize profitto:
	sum{p in PROD, s in STAB, m in MATERIE} Prezzi[p] * Quantita[p,s,m];

subject to disp_ore {s in STAB, r in REP}:
	sum{p in PROD, m in MATERIE} ConsumoMinuti[p,r]*Quantita[p,s,m] <= DispOre[s,r] * 60;
	
subject to materie_prime {s in STAB}:
	sum{p in PROD, m in MATERIE} Quantita[p,s,m]*ConsumoMaterie[p,m]*2 <= sum{m in MATERIE} DispMassima[s,m];
	
subject to min_perc {p in PROD}:
	MinPerc[p]*sum{s in STAB, k in PROD, m in MATERIE}Quantita[k,s,m] <= sum{s in STAB, m in MATERIE} Quantita[p,s,m];
	
subject to max_perc {p in PROD}:
	MaxPerc[p]*sum{s in STAB, k in PROD, m in MATERIE}Quantita[k,s,m] >= sum{s in STAB, m in MATERIE} Quantita[p,s,m];
	
subject to minCagliari:
	sum{p in PROD, m in MATERIE} Quantita[p, 'Cagliari',m] >= MinPercCagliari*sum{p in PROD, s in STAB, m in MATERIE} Quantita[p,s,m];
	
subject to maxMilano:
	sum{p in PROD, m in MATERIE} Quantita[p, 'Milano',m] <= MaxPercMilano*sum{p in PROD, s in STAB, m in MATERIE} Quantita[p,s,m];