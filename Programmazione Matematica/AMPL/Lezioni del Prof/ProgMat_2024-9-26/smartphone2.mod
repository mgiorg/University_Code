set MODEL;
set ROBOT;

param Profitto{MODEL};
param Consumo{ROBOT,MODEL}; # minuti
param Dispon{ROBOT}; # ore
param LimiteMin{MODEL};
param LimiteMax{MODEL};
param PercMin{MODEL};
param PercMax{MODEL};

var Quantita{MODEL,ROBOT} >= 0;

maximize profitto_tot:
  sum{i in MODEL, j in ROBOT} Profitto[i]*Quantita[i,j];
  
subject to tempo {j in ROBOT}:
  sum{i in MODEL} Consumo[j,i]*Quantita[i,j] <= Dispon[j]*60;
  
subject to perc_max {i in MODEL}:
  sum{j in ROBOT} Quantita[i,j] <= 
         PercMax[i]*sum{k in MODEL, j in ROBOT} Quantita[k,j];
  
subject to perc_min {i in MODEL}:
  sum{j in ROBOT} Quantita[i,j] >= 
         PercMin[i]*sum{k in MODEL, j in ROBOT} Quantita[k,j];

subject to box {i in MODEL}:
  LimiteMin[i] <= sum{j in ROBOT} Quantita[i,j] <= LimiteMax[i];
