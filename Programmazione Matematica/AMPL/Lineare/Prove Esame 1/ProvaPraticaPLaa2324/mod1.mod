set PROD;  # Prodotti
set REPARTI;  # Reparti di lavorazione

param Prezzo{PROD};  # Prezzi di vendita
param Costo{PROD};  # Costi di produzione
param LimiteMin{PROD};  # Limiti minimi di produzione
param LimiteMax{PROD};  # Limiti massimi di produzione
param Consumi{PROD, REPARTI};  # Consumi in minuti per kg
param TempoMax{REPARTI};  # Tempo massimo disponibile nei reparti

var Quantita{p in PROD} >= LimiteMin[p], <= LimiteMax[p];  # Quantità prodotte (kg)

maximize Profitto: 
    sum {p in PROD} Quantita[p] * (Prezzo[p] - Costo[p]);

subject to TempoReparti {r in REPARTI}:
    sum {p in PROD} Quantita[p] * Consumi[p, r] <= TempoMax[r];

subject to PercentualeKetchup:
    Quantita["Ketchup"] <= 0.4 * sum {p in PROD} Quantita[p];
