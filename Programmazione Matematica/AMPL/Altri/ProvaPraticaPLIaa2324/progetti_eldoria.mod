set PROGETTI;
set PERIODI ordered;

param FlussoCassa{PROGETTI,PERIODI};
param Budget{PERIODI};
param TassoInteresse;
param FlussoCassaAtt{i in PROGETTI,j in PERIODI} :=
 FlussoCassa[i,j]/(1+TassoInteresse)^(ord(j,PERIODI)-1);

var x{PROGETTI} binary;

maximize indici_reddita_tot:
 sum{i in PROGETTI} sum{j in PERIODI} FlussoCassaAtt[i,j]*x[i];

subject to limite_budget {j in PERIODI}:
 - sum{i in PROGETTI} FlussoCassa[i,j]*x[i] <= Budget[j];

subject to logico1:
 x['Agricola'] <= x['Ambientale'];

subject to logico2:
 x['Difese'] + x['Diplomazia'] + x['Economico'] >= 1;
