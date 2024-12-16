set Citta ordered;
set Tipologie ordered;

param CostoAcquisto{Tipologie}; # Costo per unità di ogni tipologia
param Rendita{Tipologie, Citta}; # Rendita per unità di ogni tipologia in ogni città
param PercPub{Citta};
param PubblicitaSconto;
param PubblicitaRenditaRiduzione;
param Budget;
param MinAuto{Citta}; # Numero minimo di autovetture per città

var Auto{Tipologie, Citta} >= 0, integer; # Numero di auto per tipologia e città
var Pubblicita{Tipologie, Citta} >= 0, integer; # Auto pubblicitarie

# Variabili binarie per i requisiti in ogni città
var z1{Citta} binary; # Requisito 1: ogni tipologia >= 15
var z2{Citta} binary; # Requisito 2: ultracompatte > SUV + utilitarie
var z3{Citta} binary; # Requisito 3: SUV < 20

maximize RenditaTotale:
    sum{i in Tipologie, j in Citta}
        (Rendita[i, j] * Auto[i, j]
        + Rendita[i, j] * (1 - PubblicitaRenditaRiduzione) * Pubblicita[i, j]);

# Vincolo di budget corretto
subject to VincoloBudget:
    sum{i in Tipologie, j in Citta}
        (CostoAcquisto[i] * Auto[i, j] + (CostoAcquisto[i] - PubblicitaSconto) * Pubblicita[i, j]) <= Budget;

# Vincolo minimo per ciascuna città
subject to MinAutoCitta {j in Citta}:
    sum{i in Tipologie} (Auto[i, j]+ Pubblicita[i, j]) >= MinAuto[j];

# Vincolo massimo di pubblicità (30%)
subject to MaxPubblicita {j in Citta}:
    sum{i in Tipologie} Pubblicita[i, j] <= 
    PercPub[j] * sum{i in Tipologie} (Auto[i, j] + Pubblicita[i,j]);

# Requisito 1: ogni tipologia >= 15
subject to Requisito1 {j in Citta, i in Tipologie}:
    (Auto[i, j] + Pubblicita[i, j]) >= 15 - 1000 * z1[j];

# Requisito 2: ultracompatte > SUV + utilitarie
subject to Requisito2 {j in Citta}:
    (Auto["ultracompatta", j] + Pubblicita["ultracompatta", j]) >= 
    (Auto['SUV', j] + Pubblicita['SUV', j]) + 
    (Auto['utilitaria', j] + Pubblicita['utilitaria', j]) - 1000 * z2[j];

# Requisito 3: SUV < 20
subject to Requisito3 {j in Citta}:
    (Auto['SUV', j] + Pubblicita['SUV', j]) <= 20 + 1000 * z3[j];

# Vincolo logico: almeno 2 requisiti rispettati in ogni città
subject to VincoloLogicoRequisiti {j in Citta}:
    z1[j] + z2[j] + z3[j] <= 1;
