set REP;
set FORMATO;
set EROE;
set ECO;
set DEL;

param Ricavo{FORMATO};
param MaxTempo{REP}; #ore
param Consumo{FORMATO,REP}; #secondi
param MinPagine{EROE};
param MaxPagine{EROE};
param PercMinEco;
param PercMinDeluxe;

param Reputazione{FORMATO};
param ReputazioneMinima{EROE};
param RicavoBundle{FORMATO};
param MaxBundle{FORMATO};

var Quantita{FORMATO,EROE} >= 0;
var Quantita_b{j in FORMATO} >= 0, <= MaxBundle[j];

maximize profitto:
	sum{f in FORMATO, e in EROE} Ricavo[f]*Quantita[f,e] + 
	sum{f in FORMATO} RicavoBundle[f]*Quantita_b[f];
	
subject to maxTempo {r in REP}: #tutto in secondi
	sum{f in FORMATO, e in EROE} Consumo[f,r]*Quantita[f,e] + 
	sum{f in FORMATO} Consumo[f,r]*Quantita_b[f] <= MaxTempo[r]*3600;
	
subject to pagine {e in EROE}:
	MinPagine[e] <= sum{f in FORMATO} Quantita[f,e] <= MaxPagine[e];
	
subject to minPercEco:
	sum{i in ECO, e in EROE}Quantita[i,e] + sum{i in ECO} Quantita_b[i] 
	>= PercMinEco*(sum{f in FORMATO, e in EROE} Quantita[f,e] + Quantita_b['spi']);
subject to minPercDel:
	sum{i in DEL, e in EROE}Quantita[i,e] >= 
	PercMinDeluxe*(sum{f in FORMATO, e in EROE} Quantita[f,e] + Quantita_b['spi']);
subject to reputazione {e in EROE}:
	sum{f in FORMATO} Reputazione[f]*(Quantita[f,e] + Quantita_b[f]/3)
	>= ReputazioneMinima[e]*sum{f in FORMATO} (Quantita[f,e] + Quantita_b[f]/3);