set ORIG;
set DEST;
set MEZZI;

param QuantSped{ORIG,DEST};
param Dist{ORIG,DEST};
param Capacita{MEZZI};
param Costo{MEZZI};
param Costo100Km{MEZZI};
param MaxNum{MEZZI};
param Emissioni100Km{MEZZI};
param EmissMax;
param numMinVel;
param multa_emiss;
param multa_velocita;
param multa_suppl;
param M;

var Num{ORIG,DEST,k in MEZZI} integer, >= 0;
var y_emiss binary;
var y_velocita binary;
var y_suppl binary;

minimize costo_tot:
  sum{i in ORIG,j in DEST,k in MEZZI} (Costo[k]+(Costo100Km[k]/100)*Dist[i,j])*Num[i,j,k]
  + multa_emiss*y_emiss + multa_velocita*y_velocita + multa_suppl*y_suppl;

subject to quantita {i in ORIG,j in DEST}:
  sum{k in MEZZI} Capacita[k]*Num[i,j,k] >= QuantSped[i,j];

subject to massimo {k in MEZZI}:
  sum{i in ORIG,j in DEST} Num[i,j,k] <= MaxNum[k];

subject to emissioni:
  sum{i in ORIG,j in DEST, k in MEZZI} (Emissioni100Km[k]/100)*Dist[i,j]*Num[i,j,k] <= EmissMax + M*y_emiss;

subject to velocita:
  sum{i in ORIG,j in DEST} Num[i,j,'FurgVel'] >= numMinVel - M*y_velocita;

subject to logico:
  y_suppl >= y_emiss + y_velocita - 1;

