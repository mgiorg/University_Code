set TIPI; # tipi di fave di caffè
set AREE; # zone di provenienza fave

param Dom{TIPI}; # richiesta di tonnellate di fave
param Costi{AREE,TIPI}; # costi per tonnellata
param Max{AREE,TIPI}; # tonnellate massime acquistabili
param PercMin{AREE} default 0; # % minime da acquistare

var q{j in AREE, i in TIPI} >= 0, <= Max[j,i];

minimize costo_approvvigionamento:
  sum{j in AREE, i in TIPI} Costi[j,i]*q[j,i];

subject to approvvigionamento {i in TIPI}:
  sum{j in AREE} q[j,i] >= Dom[i];

subject to percentuale_minima {j in AREE}:
  sum{i in TIPI} q[j,i] >= PercMin[j]*sum{jj in AREE, i in TIPI} q[jj,i];

