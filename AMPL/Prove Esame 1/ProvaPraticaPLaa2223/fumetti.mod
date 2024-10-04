set SUPEREROI;
set FORMATI_ECO;
set FORMATI_DEL;
set FORMATI = FORMATI_ECO union FORMATI_DEL;
set REPARTI;

param Ricavo{FORMATI}; # a pagina
param ConsTempo{FORMATI,REPARTI}; # secondi per pagina
param BudgTempo{REPARTI}; # ore
param MinNum{SUPEREROI};
param MaxNum{SUPEREROI};
param MinPercEco;
param MinPercDel;

var Quantita{SUPEREROI,FORMATI} >= 0; # in pagine

maximize profitto:
  sum{i in SUPEREROI,j in FORMATI} Ricavo[j]*Quantita[i,j];

subject to tempo {k in REPARTI}:
  sum{i in SUPEREROI,j in FORMATI} ConsTempo[j,k]*Quantita[i,j]/60 <= BudgTempo[k]*60;

subject to limiti {i in SUPEREROI}:
  MinNum[i] <= sum{j in FORMATI} Quantita[i,j] <= MaxNum[i];

subject to formati_eco:
  sum{i in SUPEREROI,j in FORMATI_ECO} Quantita[i,j] >= MinPercEco * sum{i in SUPEREROI,j in FORMATI} Quantita[i,j];

subject to formati_del:
  sum{i in SUPEREROI,j in FORMATI_DEL} Quantita[i,j] >= MinPercDel * sum{i in SUPEREROI,j in FORMATI} Quantita[i,j];

