set FONTI;
param CostoFisso{FONTI};
param CostoVariabile{FONTI};
param MaxProduzione{FONTI};
param Domanda;
param ProporzioneCarbonePetrolio;
param PercentualeMassimaCarbonePetrolio;
param PercentualeMinimaSolareEolico;

var Produzione{f in FONTI} >= 0, <= MaxProduzione[f];
var Attivazione{f in FONTI} binary;
var y1 binary; # Indica scelta del vincolo sul 50% di petrolio e carbone
var y2 binary; # Indica scelta del vincolo sul 20% di solare ed eolico

minimize CostoTotale:
    sum{i in FONTI} (CostoFisso[i] * Attivazione[i] + (CostoVariabile[i] / 1000) * Produzione[i]);

subject to SoddisfaDomanda:
    sum{i in FONTI} Produzione[i] = Domanda;

# Vincolo disgiuntivo per "green"
subject to SceltaGreen:
    y1 + y2 = 1;

subject to Vincolo50PercPetCarb:
    sum{i in {"petrolio", "carbone"}} Produzione[i] <= 
    PercentualeMassimaCarbonePetrolio * Domanda + (1 - y1) * Domanda;

subject to Vincolo20PercSolEol:
    sum{i in {"solare", "eolico"}} Produzione[i] >= 
    PercentualeMinimaSolareEolico * Domanda - (1 - y2) * Domanda;

subject to CollegamentoProduzioneAttivazione {i in FONTI}:
    Produzione[i] <= MaxProduzione[i] * Attivazione[i];

subject to EsclusioneIdroGas:
    Attivazione["idroelettrico"] + Attivazione["gas"] <= 1;

subject to PetrolioAlmeno40Carbone:
    Produzione["petrolio"] >= ProporzioneCarbonePetrolio * Produzione["carbone"];
