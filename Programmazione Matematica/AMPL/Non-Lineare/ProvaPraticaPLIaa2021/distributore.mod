set ACQUE;
set BIBITE;
set BEVANDE := ACQUE union BIBITE;
set SNACK;
set PRODOTTI := BEVANDE union SNACK;

param prezzo{PRODOTTI};
param capacita;
param minBevande;
param minSnack;
param u{PRODOTTI};
param minPercAcqueVsBibite;
param costoFisso{PRODOTTI};
param maxTipiSnack;

var qta{i in PRODOTTI} integer, >= 0, <= u[i];
var y{PRODOTTI} binary;

maximize profitto:
  sum{i in PRODOTTI} (prezzo[i]*qta[i] - costoFisso[i]*y[i]);

subject to minimo_bevande:
  sum{i in BEVANDE} qta[i] >= minBevande;

subject to minimo_snack:
  sum{i in SNACK} qta[i] >= minSnack;

subject to contenuto:
  sum{i in PRODOTTI} qta[i] <= capacita;

subject to acque_vs_bibite:
  sum{i in ACQUE} qta[i] >= minPercAcqueVsBibite * sum{i in BIBITE} qta[i];

subject to attivazione_delta {i in PRODOTTI}:
  qta[i] <= u[i]*y[i];

subject to tipi_snack:
  sum{i in SNACK} y[i] <= maxTipiSnack;
