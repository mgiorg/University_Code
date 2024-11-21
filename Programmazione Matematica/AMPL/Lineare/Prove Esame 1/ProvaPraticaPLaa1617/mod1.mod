set CULTIVAR;
set REPARTI;

param Prezzo{CULTIVAR};
param QtaMin{CULTIVAR};
param QtaMax{CULTIVAR};
param Resa{CULTIVAR};
param Acidita{CULTIVAR};
param OreMax{REPARTI};
param Tempo{CULTIVAR, REPARTI};
param ProduzioneMin;
param AciditaMax;

var x{CULTIVAR} >= 0;

minimize costo:
    sum{i in CULTIVAR} Prezzo[i] * x[i];

subject to produzione_olio:
    sum{i in CULTIVAR} Resa[i] * x[i] >= ProduzioneMin;

subject to vincolo_acidita:
    sum{i in CULTIVAR} Acidita[i] * Resa[i] * x[i] / ProduzioneMin <= AciditaMax;

subject to vincolo_quantita {i in CULTIVAR}:
    QtaMin[i] <= x[i] <= QtaMax[i];

subject to vincolo_reparti {j in REPARTI}:
    sum{i in CULTIVAR} Tempo[i,j] * x[i] <= OreMax[j];