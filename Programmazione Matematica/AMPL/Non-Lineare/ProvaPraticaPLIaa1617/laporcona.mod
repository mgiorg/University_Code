set P_MAGRE;
set P_GRASSE;
set P_SAPORI;
set INGR := P_MAGRE union P_GRASSE union P_SAPORI;
set QUAL;

param Costo{INGR};
param Compos{INGR,QUAL};
param Peso;
param Lb{QUAL};
param Ub{QUAL};

var q{INGR} >= 0;
var y{INGR} binary;
var z1 binary;
var z2 binary;

minimize costi:
  sum{i in INGR} Costo[i]*q[i]/1000;

subject to peso_tot:
  sum{i in INGR} q[i] = Peso;

subject to richieste {j in QUAL}:
  Lb[j] <= sum{i in INGR} Compos[i,j]*q[i]/1000 <= Ub[j];

subject to minimo_p_magre:
  sum{i in P_MAGRE} q[i] >= 1;

subject to minimo_p_grasse:
  sum{i in P_GRASSE} q[i] >= 1;

subject to minimo_p_sapori:
  sum{i in P_SAPORI} q[i] >= 1;

subject to attiva {i in INGR}:
  q[i] <= Peso*y[i];

subject to cond_p_magre:
  sum{i in P_MAGRE} y[i] <= 2;

subject to cond_p_grasse:
  sum{i in P_GRASSE} y[i] <= 2;

subject to cond_p_sapori:
  sum{i in P_SAPORI} y[i] <= 2;

subject to lardo_fegato:
  y['lar'] + y['feg'] <= 1;

subject to cond1:
  sum{i in INGR} Compos[i,'pro']*q[i]/1000 >= 46 - Peso*z1;

subject to cond2_1:
  sum{i in P_MAGRE} q[i] >= 0.6*Peso - Peso*z2;

subject to cond2_2:
  sum{i in INGR} Compos[i,'sal']*q[i]/1000 <= 0.5 + Peso*z2;

subject to disj:
  z1 + z2 <= 1;

