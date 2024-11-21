set MATERIALI;
set CARAT;
set CAPITALI;

param Costo{MATERIALI};
param Caratteristiche{CARAT, MATERIALI};
param NumeroCapi{CAPITALI};
param PercMat{MATERIALI,CAPITALI}; #Residuo dopo il lavoro
param ReqMinimi{CARAT, CAPITALI};
param dimT;
param CostoTrasferimento{CAPITALI, CAPITALI};

var Trasporto{MATERIALI, CAPITALI, CAPITALI} >= 0;

minimize costo_totale:
    sum {m in MATERIALI, c1 in CAPITALI, c2 in CAPITALI} Trasporto[m, c1, c2] * (Costo[m] + CostoTrasferimento[c1, c2]);

s.t. quantitaTshirt {c2 in CAPITALI}:
    sum {m in MATERIALI, c1 in CAPITALI} Trasporto[m, c1, c2]*PercMat[m,c1]/ dimT = NumeroCapi[c2];

s.t. reqMinimi {c2 in CAPITALI, cc in CARAT}:
    sum {m in MATERIALI, c1 in CAPITALI} Trasporto[m, c1, c2] * Caratteristiche[cc, m] * PercMat[m,c1] >= ReqMinimi[cc, c2] * sum{m in MATERIALI, c1 in CAPITALI}Trasporto[m,c1,c2]*PercMat[m,c1];