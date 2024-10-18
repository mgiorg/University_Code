set ATTIVITA;
set GESTI;

param Contributo_lavoro{GESTI,ATTIVITA};
param Minimo_lavoro{GESTI};
param Tempo_minimo;
param Percentuale_tempo_minima{ATTIVITA};

var Tempo{ATTIVITA} >= Tempo_minimo;

minimize tempo_totale:
  sum{i in ATTIVITA} Tempo[i];

subject to requisiti_lavoro {j in GESTI}:
  sum{i in ATTIVITA} Contributo_lavoro[j,i]*Tempo[i] >= Minimo_lavoro[j];

subject to requisiti_percentuali {i in ATTIVITA}:
  Tempo[i] >= Percentuale_tempo_minima[i] * (sum{k in ATTIVITA} Tempo[k]);

