set TipiAuto; # Tipologie di auto: utilitaria, SUV, ultracompatta
set Citta; # Città: Pomezia, Aprilia, Latina

param Costo{TipiAuto}; # Costo di acquisto per tipologia di auto
param Rendita{TipiAuto, Citta}; # Rendita per tipologia e città
param ScontoPubblicita; # Sconto sul costo per le auto pubblicitarie
param RiduzioneRendita; # Riduzione percentuale della rendita per pubblicità
param MinAuto{Citta}; # Minimo numero di auto richiesto per città
param Budget; # Budget totale
param MinTipologia; # Minimo per ogni tipologia di auto
param MaxSUV; # Massimo per il numero di SUV
param M:= 1000; # Grande valore per vincoli alternativi

var Auto{TipiAuto, Citta} >= 0, integer; # Numero di auto acquistate per tipo e città
var Pubblicita{TipiAuto, Citta} >= 0, integer; # Auto pubblicitarie
var z1{Citta} binary; # Vincolo 1 soddisfatto
var z2{Citta} binary; # Vincolo 2 soddisfatto
var z3{Citta} binary; # Vincolo 3 soddisfatto

maximize RenditaTotale:
    sum {t in TipiAuto, c in Citta}
        (Rendita[t, c] * Auto[t, c] +
         Rendita[t, c] * (1 - RiduzioneRendita) * Pubblicita[t, c]);

subject to BudgetLimit:
    sum {t in TipiAuto, c in Citta}
        (Costo[t] * Auto[t, c] + (Costo[t]-ScontoPubblicita) * Pubblicita[t, c]) <= Budget;

subject to MinAutoReq {c in Citta}:
    sum {t in TipiAuto} (Auto[t, c] + Pubblicita[t, c]) >= MinAuto[c];

subject to PubblicitaLimit {c in Citta}:
    sum {t in TipiAuto} Pubblicita[t, c] <= 
    0.3 * sum {t in TipiAuto} (Auto[t, c] + Pubblicita[t, c]);

subject to MinTipologiaReq {t in TipiAuto, c in Citta}:
   (Auto[t, c] + Pubblicita[t, c]) >= MinTipologia - M * z1[c];

subject to MaxSUVReq {c in Citta}:
    (Auto["SUV", c] + Pubblicita["SUV", c]) <= MaxSUV + M * z2[c];

subject to UltracompatteDominance {c in Citta}:
    Auto['ultracompatta', c]+Pubblicita['ultracompatta', c] >=
    (Auto['SUV', c]+Pubblicita['SUV', c]) + 
    (Auto['utilitaria', c]+Pubblicita['utilitaria', c]) - M*z2[c];

subject to AlternativeTwo {c in Citta}:
    z1[c] + z2[c] + z3[c] <= 1;
