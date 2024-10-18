set MODEL;
set ROBOT;

param Profitto{MODEL};
param Consumo{ROBOT,MODEL}; # minuti
param Dispon{ROBOT}; # ore
param LimiteMin{MODEL};
param LimiteMax{MODEL};
param PercMin{MODEL};
param PercMax{MODEL};

var Quantita{i in MODEL} >= LimiteMin[i], <= LimiteMax[i];

maximize profitto_tot:
  sum{i in MODEL} Profitto[i]*Quantita[i];
  
subject to tempo {j in ROBOT}:
  sum{i in MODEL} Consumo[j,i]*Quantita[i] <= Dispon[j]*60;
  
subject to perc_max {i in MODEL}:
  Quantita[i] <= PercMax[i]*sum{k in MODEL} Quantita[k];
  
subject to perc_min {i in MODEL}:
  Quantita[i] >= PercMin[i]*sum{k in MODEL} Quantita[k];
