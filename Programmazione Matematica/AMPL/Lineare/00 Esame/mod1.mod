set MATERIALI;
set CARAT;
set CAPITALI;

param Costo{MATERIALI};
param Caratteristiche{CARAT, MATERIALI};
param NumeroCapi{CAPITALI};
param PercMat{MATERIALI,CAPITALI}; #Residuo dopo il lavoro
param ReqMinimi{CARAT, CAPITALI};
param dimT;

var Quantita{MATERIALI, CAPITALI} >= 0;

minimize costo:
	sum{m in MATERIALI, c in CAPITALI} Quantita[m,c]*Costo[m];

s.t. quantitaTshirt {c in CAPITALI}:
   sum{m in MATERIALI} Quantita[m,c] * PercMat[m,c]/ dimT = NumeroCapi[c];

s.t. reqMinimi {c in CAPITALI, cc in CARAT}:
	(sum{m in MATERIALI} Quantita[m,c] * Caratteristiche[cc,m]*PercMat[m,c]) >= ReqMinimi[cc, c] * (NumeroCapi[c]*dimT);
