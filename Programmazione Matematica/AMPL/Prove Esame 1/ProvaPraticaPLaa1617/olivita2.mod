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

var x{OLIVE,REP} >= 0;

minimize costo:
  sum{i in OLIVE, j in REP} Prezzo[i]*x[i,j];

subject to limite_reparti {j in REP}:
  sum{i in OLIVE} Cons[i,j]*x[i,j] <= OreMax[j];

subject to qta_olio:
  sum{i in OLIVE, j in REP} Resa[i]*x[i,j] = OlioQta;

subject to acidita:
  sum{i in OLIVE, j in REP} Acid[i]*Resa[i]*x[i,j] <= AcidMax * (sum{i in OLIVE, j in REP} Resa[i]*x[i,j]);

subject to bound {i in OLIVE}:
  QtaMin[i] <= sum{j in REP} x[i,j] <= QtaMax[i];

subject to percentuale:
  sum{j in REP} x['FR',j] >= 0.1 * sum{i in OLIVE, j in REP} x[i,j];





