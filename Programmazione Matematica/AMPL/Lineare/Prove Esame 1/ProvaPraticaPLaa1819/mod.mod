# Modello Parte 1
set Prodotti;
set Stabilimenti;

param Prezzo {Prodotti};
param ConsumoRep {Prodotti, 1..3};
param DisponibilitaRep {Stabilimenti, 1..3};
param ConsumoMP {Prodotti, 1..2};
param DisponibilitaMP {Stabilimenti, 1..2};
param BoundMin {Stabilimenti, Prodotti};
param BoundMax {Stabilimenti, Prodotti};

var Produzione {Stabilimenti, Prodotti} >= 0;

maximize RicavoTotale:
    sum {s in Stabilimenti, p in Prodotti} Prezzo[p] * Produzione[s, p];

subject to CapacitaReparto {s in Stabilimenti, r in 1..3}:
    sum {p in Prodotti} ConsumoRep[p, r] * Produzione[s, p] <= DisponibilitaRep[s, r] * 60;

subject to CapacitaMateriePrime {s in Stabilimenti, mp in 1..2}:
    sum {p in Prodotti} ConsumoMP[p, mp] * Produzione[s, p] <= DisponibilitaMP[s, mp];

subject to BoundProduzione {s in Stabilimenti, p in Prodotti}:
    BoundMin[s, p] <= Produzione[s, p] <= BoundMax[s, p];

subject to PercentualePiatti:
    sum {s in Stabilimenti} Produzione[s, "piatto"] >= 0.3 * sum {s in Stabilimenti, p in Prodotti} Produzione[s, p];

subject to PercentualeBicchieri:
    sum {s in Stabilimenti} Produzione[s, "bicchiere"] >= 0.2 * sum {s in Stabilimenti, p in Prodotti} Produzione[s, p];

subject to PercentualeVasi:
    sum {s in Stabilimenti} Produzione[s, "vaso"] <= 0.3 * sum {s in Stabilimenti, p in Prodotti} Produzione[s, p];

subject to PercentualeCiotole:
    sum {s in Stabilimenti} Produzione[s, "ciotola"] <= 0.2 * sum {s in Stabilimenti, p in Prodotti} Produzione[s, p];

subject to ProduzioneCagliari:
    sum {p in Prodotti} Produzione["Cagliari", p] >= 0.35 * sum {s in Stabilimenti, p in Prodotti} Produzione[s, p];

subject to ProduzioneMilano:
    sum {p in Prodotti} Produzione["Milano", p] <= 0.35 * sum {s in Stabilimenti, p in Prodotti} Produzione[s, p];
