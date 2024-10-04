set PRODOTTI;
set MACCHINE;
set IMPIANTI;

param DispOre{MACCHINE,IMPIANTI};
param ConsOre{PRODOTTI,MACCHINE,IMPIANTI};
param ConsMat;
param Prezzo{PRODOTTI};
param DispMat{IMPIANTI};

var x{PRODOTTI,IMPIANTI} >= 0;

maximize ricavo:
  sum{k in IMPIANTI, i in PRODOTTI} Prezzo[i]*x[i,k];

subject to materiale {k in IMPIANTI}:
  sum{i in PRODOTTI} ConsMat*x[i,k] <= DispMat[k];

subject to ore {j in MACCHINE, k in IMPIANTI}:
  sum{i in PRODOTTI} ConsOre[i,j,k]*x[i,k] <= DispOre[j,k];



