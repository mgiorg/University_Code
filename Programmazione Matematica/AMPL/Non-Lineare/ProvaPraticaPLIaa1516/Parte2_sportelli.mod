
set COMUNI;
set ASL within COMUNI;

param distanza{COMUNI, COMUNI};
param p;

var Sportelli{ASL} binary;
var Collegamento{COMUNI, ASL} binary;
var DistanzaMassima;

minimize DistanzaTotale:
    DistanzaMassima;

subject to CollegamentoComune {c in COMUNI}:
    sum {a in ASL} Collegamento[c, a] = 1;

subject to LimiteSportelli:
    sum {a in ASL} Sportelli[a] = p;

subject to CollegamentoAttivo {c in COMUNI, a in ASL}:
    Collegamento[c, a] <= Sportelli[a];

subject to DefinizioneDistanza {c in COMUNI, a in ASL}:
    DistanzaMassima >= distanza[c, a] * Collegamento[c, a];

subject to AttivazioneCondizionata:
    Sportelli["C2"] <= Sportelli["C4"];
