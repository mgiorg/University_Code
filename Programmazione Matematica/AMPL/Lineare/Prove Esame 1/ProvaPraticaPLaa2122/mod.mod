set ESERCIZI;
set GESTI;

param Contributo{GESTI, ESERCIZI};
param MinJoule{GESTI};
param PercEsercizi{ESERCIZI};

var tempo_min{ESERCIZI} >= 10;

minimize tempo_allenamento:
	sum{e in ESERCIZI} tempo_min[e];

subject to joule_minimi {g in GESTI}:
	sum{e in ESERCIZI} tempo_min[e]*Contributo[g,e] >= MinJoule[g];
subject to perc_min {e in ESERCIZI}:
	tempo_min[e] >= PercEsercizi[e] * (sum{k in ESERCIZI}tempo_min[k]);
