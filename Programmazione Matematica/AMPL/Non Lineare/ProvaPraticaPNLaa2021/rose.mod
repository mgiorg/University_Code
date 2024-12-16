set FORNITORI;

param costo_media{FORNITORI};
param costo_varianza{FORNITORI};
param varianza_max;
param prezzo_base;
param prezzo_variazione;

var qta{FORNITORI} >= 0;

maximize profitto:
  (prezzo_base - prezzo_variazione*(sum{i in FORNITORI} qta[i])) * (sum{i in FORNITORI} qta[i]) - (sum{i in FORNITORI} costo_media[i] * qta[i]);

subject to rischio:
  sum{i in FORNITORI} costo_varianza[i] * qta[i]^2 <= varianza_max * (sum{i in FORNITORI} qta[i])^2;

