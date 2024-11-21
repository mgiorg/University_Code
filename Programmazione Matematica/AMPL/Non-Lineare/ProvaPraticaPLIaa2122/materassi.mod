set MODELLI;
set MATERIALI;
set SPESSORI;

param PrezzoModelli{MODELLI};
param RincaroMateriali{MATERIALI};
param RincaroSpessori{SPESSORI};
param NumMaterassi;
param NumMinimo;
param NumMinTipiModello;
param NumMinTipiMateriale;
param NumMinTipiSpessore;
param CostoFisso{MODELLI};
param M := NumMaterassi;

var Quantita{MODELLI,MATERIALI,SPESSORI} >= 0, integer;
var y{MODELLI,MATERIALI,SPESSORI} binary;
var z{1..3} binary;

maximize guadagno:
  sum{i in MODELLI, j in MATERIALI, k in SPESSORI} (PrezzoModelli[i]*RincaroMateriali[j]*RincaroSpessori[k]*Quantita[i,j,k]
    - CostoFisso[i]*y[i,j,k]);

subject to numero_massimo:
  sum{i in MODELLI, j in MATERIALI, k in SPESSORI} Quantita[i,j,k] = NumMaterassi;

subject to attivazione1_y {i in MODELLI, j in MATERIALI, k in SPESSORI}:
  Quantita[i,j,k] <= NumMaterassi*y[i,j,k];

subject to attivazione2_y {i in MODELLI, j in MATERIALI, k in SPESSORI}:
  Quantita[i,j,k] >= NumMinimo*y[i,j,k];

subject to tipi_minimi_modello {i in MODELLI}:
  sum{j in MATERIALI, k in SPESSORI} y[i,j,k] >= NumMinTipiModello;

subject to tipi_massimi_materiale {j in MATERIALI}:
  sum{i in MODELLI, k in SPESSORI} y[i,j,k] >= NumMinTipiMateriale;

subject to tipi_massimi_spessore {k in SPESSORI}:
  sum{i in MODELLI, j in MATERIALI} y[i,j,k] >= NumMinTipiSpessore;

subject to disj1:
  sum{j in MATERIALI, k in SPESSORI} Quantita['nature',j,k] >= 0.3*NumMaterassi - M*z[1];

subject to disj2:
  Quantita['comfort','memory','40cm'] <= 0 + M*z[2];

subject to disj3:
  sum{j in MATERIALI, k in SPESSORI} y['essential',j,k] <= 5 + M*z[3];

subject to disjunctive:
  sum{u in 1..3} z[u] <= 2;

