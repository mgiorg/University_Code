
set FONTI;

param Domanda;
param Costo{FONTI};
param CostoFisso{FONTI} default 0;
param QtaMax{FONTI};
param MaxPetrolioCarbone;
param MinSolareEolico;
param M := Domanda;
param RapportoPetrolioCarbone;

var Produzione{f in FONTI} >= 0, <= QtaMax[f];
var Attivazione{FONTI} binary;
var z_green1 binary;
var z_green2 binary;

minimize CostoTotale:
    sum {f in FONTI} ((Produzione[f] * Costo[f] / 1000) + (CostoFisso[f] * Attivazione[f]));

subject to SoddisfareDomanda:
    sum {f in FONTI} Produzione[f] = Domanda;

subject to LimitePetrolioCarbone:
    Produzione["petrolio"] + Produzione["carbone"] <= 0.5 * Domanda + z_green1 * M;

subject to MinimoSolareEolico:
    Produzione["solare"] + Produzione["eolico"] >= 0.2 * Domanda - z_green2 * M;

subject to LogicaVincoliGreen:
    z_green1 + z_green2 <= 1;

subject to RapPetCarb:
    Produzione["petrolio"] >= RapportoPetrolioCarbone * Produzione["carbone"];

subject to EsclusioneIdroelettricoGas:
    Attivazione["idroelettrico"] + Attivazione["gas"] <= 1;

subject to CollegamentoProduzioneAttivazione {f in FONTI}:
    Produzione[f] <= QtaMax[f] * Attivazione[f];
