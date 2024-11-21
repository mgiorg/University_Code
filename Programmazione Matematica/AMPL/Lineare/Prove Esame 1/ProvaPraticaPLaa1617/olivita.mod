set OLIVE;
set REP;

param Prezzo{OLIVE};
param QtaMin{OLIVE};
param QtaMax{OLIVE};
param Resa{OLIVE};
param Acid{OLIVE};
param OreMax{REP};
param Cons{OLIVE,REP};
param OlioQta;
param AcidMax;

var x{i in OLIVE} >= QtaMin[i], <= QtaMax[i];

minimize costo:
  sum{i in OLIVE} Prezzo[i]*x[i];

subject to limite_reparti {j in REP}:
  sum{i in OLIVE} Cons[i,j]*x[i] <= OreMax[j];

subject to qta_olio:
  sum{i in OLIVE} Resa[i]*x[i] = OlioQta;

subject to acidita:
  sum{i in OLIVE} Acid[i]*Resa[i]*x[i] <= AcidMax * (sum{i in OLIVE} Resa[i]*x[i]);

