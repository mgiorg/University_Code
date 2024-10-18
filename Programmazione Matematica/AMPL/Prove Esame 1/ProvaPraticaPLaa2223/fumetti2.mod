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
param Reputazione{FORMATI};
param MinReputazione{SUPEREROI};
param MaxBundle{FORMATI};
param RicavoBundle{FORMATI};

var Quantita{SUPEREROI,FORMATI} >= 0; # in pagine
var Bundle{j in FORMATI} >= 0, <= MaxBundle[j]; # in pagine

maximize profitto:
  sum{i in SUPEREROI,j in FORMATI} Ricavo[j]*Quantita[i,j] +
  sum{j in FORMATI} RicavoBundle[j]*Bundle[j];

subject to tempo {k in REPARTI}:
  sum{i in SUPEREROI,j in FORMATI} ConsTempo[j,k]*Quantita[i,j]/60 
  + sum{j in FORMATI} ConsTempo[j,k]*Bundle[j]/60 <= BudgTempo[k]*60;

subject to limiti {i in SUPEREROI}:
  MinNum[i] <= sum{j in FORMATI} Quantita[i,j] <= MaxNum[i];

subject to formati_eco:
  sum{i in SUPEREROI,j in FORMATI_ECO} Quantita[i,j] + sum{j in FORMATI_ECO} Bundle[j]
  >= MinPercEco * (sum{i in SUPEREROI,j in FORMATI} Quantita[i,j] + sum{j in FORMATI} Bundle[j]);

subject to formati_del:
  sum{i in SUPEREROI,j in FORMATI_DEL} Quantita[i,j] + sum{j in FORMATI_DEL} Bundle[j]
  >= MinPercDel * (sum{i in SUPEREROI,j in FORMATI} Quantita[i,j] + sum{j in FORMATI} Bundle[j]);

subject to reputazione_limite {i in SUPEREROI}:
  sum{j in FORMATI} Reputazione[j]*(Quantita[i,j]+Bundle[j]/3) >= MinReputazione[i] * sum{j in FORMATI} (Quantita[i,j]+Bundle[j]/3);


