set TIPI;
set CITTA;

param budget;
param costo{TIPI};
param rendita{TIPI,CITTA};
param scontoPubb;
param fattorePubb;
param maxPercPubb{CITTA};
param minimo{CITTA};
param minimoAlt1;
param massimoAlt3;
param M;

var auto{TIPI,CITTA} >= 0, integer;
var autoPubb{TIPI,CITTA} >= 0, integer;
var z1{CITTA} binary;
var z2{CITTA} binary;
var z3{CITTA} binary;

maximize rendita_tot:
  sum{i in TIPI, j in CITTA} ( rendita[i,j]*auto[i,j] +
                (1-fattorePubb)*rendita[i,j]*autoPubb[i,j] );

subject to acquisto:
  sum{i in TIPI, j in CITTA} ( costo[i]*auto[i,j] +
                (costo[i]-scontoPubb)*autoPubb[i,j] ) <= budget;

subject to pubblicita {j in CITTA}:
  sum{i in TIPI} autoPubb[i,j] <=
  maxPercPubb[j]*sum{i in TIPI} (auto[i,j] + autoPubb[i,j]);

subject to numero_minimo {j in CITTA}:
  sum{i in TIPI} (auto[i,j] + autoPubb[i,j]) >= minimo[j];

subject to alternativo1 {i in TIPI, j in CITTA}:
  (auto[i,j] + autoPubb[i,j]) >= minimoAlt1 - M*z1[j];

subject to alternativo2 {j in CITTA}:
  (auto['comp',j] + autoPubb['comp',j]) >= 
  (auto['SUV',j] + autoPubb['SUV',j]) + 
  (auto['util',j] + autoPubb['util',j]) - M*z2[j];

subject to alternativo3 {j in CITTA}:
  (auto['SUV',j] + autoPubb['SUV',j]) <= massimoAlt3 + M*z3[j];

subject to disgiuntivo {j in CITTA}:
  z1[j] + z2[j] + z3[j] <= 1;

