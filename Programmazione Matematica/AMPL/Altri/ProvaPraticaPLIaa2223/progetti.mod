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

subject to dipendenza1:
        4*x['Prog4'] <= x['Prog1']+x['Prog2']+x['Prog5']+x['Prog7'];

subject to dipendenza2:
        x['Prog7'] <= x['Prog1'];

