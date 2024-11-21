# Modello per la Parte 1

# Set
set ORIGINI;  # Aree geografiche
set TIPI;     # Tipi di fave di caffè

# Parametri
param costo{ORIGINI, TIPI};           # Costo per tonnellata
param domanda{TIPI};                  # Domanda mensile in tonnellate
param max_quantita{ORIGINI, TIPI};    # Massime quantità acquistabili
param perc_africa;                    # Percentuale minima da Africa

# Variabili di decisione
var acquisto{ORIGINI, TIPI} >= 0;     # Quantità acquistata

# Funzione obiettivo
minimize CostoTotale:
    sum {o in ORIGINI, t in TIPI} costo[o, t] * acquisto[o, t];

# Vincoli
subject to Domanda {t in TIPI}:
    sum {o in ORIGINI} acquisto[o, t] = domanda[t];

subject to CapacitaMassima {o in ORIGINI, t in TIPI}:
    acquisto[o, t] <= max_quantita[o, t];

subject to PercentualeAfrica:
    sum {t in TIPI} acquisto["Africa", t] >= perc_africa * sum {o in ORIGINI, t in TIPI} acquisto[o, t];
