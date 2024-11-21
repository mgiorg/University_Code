set FERT;
set REP;

param Profitto{FERT};
param Consumo{REP,FERT};
param Dispon{REP};

var Quantita{FERT} >= 0; # Mi interessa che le quantità siano positive

# FUNZIONE OBIETTIVO
maximize profitto_tot:
	sum{i in FERT} Profitto[i] * Quantita[i];
	
# VINCOLO
subject to tempo {j in REP}:
	sum{i in FERT} Consumo[j,i]*Quantita[i] <= Dispon[j];