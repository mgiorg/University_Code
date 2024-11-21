set GENERATORI;
set PERIODI;

param CostoPerMW{GENERATORI};
param CostoAttiv{GENERATORI,PERIODI};
param Richiesta{PERIODI};
param Capacita{GENERATORI};

var Quantita{i in GENERATORI,PERIODI} >= 0, <= Capacita[i];
var y{GENERATORI,PERIODI} binary;

minimize costo_tot:
 sum{i in GENERATORI,j in PERIODI} (CostoPerMW[i]*Quantita[i,j] +
                                    CostoAttiv[i,j]*y[i,j]);

subject to richieste_minime {j in PERIODI}:
 sum{i in GENERATORI} Quantita[i,j] >= Richiesta[j];

subject to attivazioni {i in GENERATORI,j in PERIODI}:
 Quantita[i,j] <= Capacita[i]*y[i,j];
