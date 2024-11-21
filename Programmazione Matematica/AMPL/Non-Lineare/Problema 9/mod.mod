set GENERATORI;  # Set dei generatori

param CostoAttivazioneGiorno{GENERATORI};  # Costo di attivazione di giorno
param CostoAttivazioneNotte{GENERATORI};   # Costo di attivazione di notte
param CostoPerMW{GENERATORI};              # Costo per ogni MW prodotto
param CapacitaMax{GENERATORI};             # Capacità massima in MW
param RichiestaGiorno;                     # Richiesta minima giornaliera
param RichiestaNotte;                      # Richiesta minima notturna

var MWGiorno{g in GENERATORI} >= 0, <= CapacitaMax[g];  # MW prodotti di giorno
var MWNotte{g in GENERATORI} >= 0, <= CapacitaMax[g];   # MW prodotti di notte
var AttivoGiorno{GENERATORI} binary;                        # Binaria: 1 se il generatore è attivo di giorno
var AttivoNotte{GENERATORI} binary;                         # Binaria: 1 se il generatore è attivo di notte

minimize CostoTotale:
    sum {g in GENERATORI} (
        CostoAttivazioneGiorno[g] * AttivoGiorno[g] +
        CostoAttivazioneNotte[g] * AttivoNotte[g] +
        CostoPerMW[g] * (MWGiorno[g] + MWNotte[g])
    );

subject to RichiestaMinimaGiorno:
    sum {g in GENERATORI} MWGiorno[g] >= RichiestaGiorno;

subject to RichiestaMinimaNotte:
    sum {g in GENERATORI} MWNotte[g] >= RichiestaNotte;

subject to CapacitaAttivazioneGiorno {g in GENERATORI}:
    MWGiorno[g] <= CapacitaMax[g] * AttivoGiorno[g];

subject to CapacitaAttivazioneNotte {g in GENERATORI}:
    MWNotte[g] <= CapacitaMax[g] * AttivoNotte[g];
