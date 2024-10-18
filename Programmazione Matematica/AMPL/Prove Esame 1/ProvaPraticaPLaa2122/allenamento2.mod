set ATTIVITA;
set GESTI;

param Contributo_lavoro{GESTI,ATTIVITA};
param Minimo_lavoro{GESTI};
param Tempo_minimo;
param Percentuale_tempo_minima{ATTIVITA};
param Intensita{ATTIVITA};
param Intensita_minima;
param Intensita_massima;
param Tempo_massimo{ATTIVITA};

var Tempo{i in ATTIVITA} >= Tempo_minimo, <= Tempo_massimo[i];

minimize tempo_totale:
  sum{i in ATTIVITA} Tempo[i];

subject to requisiti_lavoro {j in GESTI}:
  sum{i in ATTIVITA} Contributo_lavoro[j,i]*Tempo[i] >= Minimo_lavoro[j];

subject to requisiti_percentuali {i in ATTIVITA}:
  Tempo[i] >= Percentuale_tempo_minima[i] * (sum{k in ATTIVITA} Tempo[k]);

subject to requisito_intensita_minima:
  sum{i in ATTIVITA} Intensita[i]*Tempo[i] >= Intensita_minima * (sum{i in ATTIVITA} Tempo[i]);

subject to requisito_intensita_massima:
  sum{i in ATTIVITA} Intensita[i]*Tempo[i] <= Intensita_massima * (sum{i in ATTIVITA} Tempo[i]);

