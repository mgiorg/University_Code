# File: Parte1_Trasporto.mod

# Set
set ORIGINI;
set DESTINAZIONI;
set MEZZI;

# Parametri
param Domanda{ORIGINI, DESTINAZIONI};
param Distanza{ORIGINI, DESTINAZIONI};
param Capacita{MEZZI};
param Costo{MEZZI};
param Costo100Km{MEZZI};
param MaxMezzi{MEZZI};
param Emissioni100Km{MEZZI};
param LimiteEmissioni;
param LimiteFurgoni;
param PenalitaEmissioni;
param PenalitaFurgoni;
param PenalitaCombinata;
param M default 1000000;  # Parametro grande per vincoli logici

# Variabili
var Num{ORIGINI, DESTINAZIONI, MEZZI} >= 0, integer;  # Numero di mezzi utilizzati
var y_emiss binary;       # Penalità per emissioni
var y_velocita binary;    # Penalità per furgoni veloci
var y_suppl binary;       # Penalità combinata

# Funzione obiettivo
minimize costo_tot:
    sum{o in ORIGINI, d in DESTINAZIONI, k in MEZZI}
        (Costo[k] + (Costo100Km[k] / 100) * Distanza[o, d]) * Num[o, d, k]
    + PenalitaEmissioni * y_emiss
    + PenalitaFurgoni * y_velocita
    + PenalitaCombinata * y_suppl;

# Vincoli
subject to SoddisfazioneDomanda{o in ORIGINI, d in DESTINAZIONI}:
    sum{k in MEZZI} Capacita[k] * Num[o, d, k] >= Domanda[o, d];

subject to LimitiMezzi{k in MEZZI}:
    sum{o in ORIGINI, d in DESTINAZIONI} Num[o, d, k] <= MaxMezzi[k];

subject to Emissioni:
    sum{o in ORIGINI, d in DESTINAZIONI, k in MEZZI}
        (Emissioni100Km[k] / 100) * Distanza[o, d] * Num[o, d, k] <= LimiteEmissioni + M * y_emiss;

subject to Velocita:
    sum{o in ORIGINI, d in DESTINAZIONI} Num[o, d, "furgone_veloce"] >= LimiteFurgoni - M * y_velocita;

subject to Logico:
    y_suppl >= y_emiss + y_velocita - 1;
