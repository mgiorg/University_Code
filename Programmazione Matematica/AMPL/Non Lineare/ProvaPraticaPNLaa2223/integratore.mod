set SOSTANZE;
set MICRO_EL;

param Quantita_totale;
param Costo{SOSTANZE};
param Costo_Max;
param Composizione{SOSTANZE,MICRO_EL};
param Valori_Min{MICRO_EL};
param Tossicita_Med{SOSTANZE};
param Tossicita_Cov{SOSTANZE,SOSTANZE};
param Tossicita_max;

var Quantita{SOSTANZE} >= 0;

minimize rischio:
  sum{i in SOSTANZE, k in SOSTANZE} Tossicita_Cov[i,k]*Quantita[i]*Quantita[k]/(Quantita_totale*Quantita_totale);

s.t. quantita_totale:
  sum{i in SOSTANZE} Quantita[i] = Quantita_totale;

s.t. costi:
  sum{i in SOSTANZE} Costo[i]*Quantita[i] <= Costo_Max;

s.t. micro_elementi {j in MICRO_EL}:
  sum{i in SOSTANZE} Composizione[i,j]*Quantita[i] >= Valori_Min[j];

s.t. tossicita_attesa:
  sum{i in SOSTANZE} Tossicita_Med[i]*Quantita[i] <= Tossicita_max;

