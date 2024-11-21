# Modello per la Parte 2

set TIPI;       # Tipi di fave di caffè
set QUAL_G;     # Qualità in gradi (dolcezza, acidità, amarezza, caffeina)

param Peso;     # Peso confezione in kg
param Cont_G{QUAL_G, TIPI};          # Contenuti di qualità in gradi
param Min_G{QUAL_G};                 # Limiti minimi qualità in gradi
param Max_G{QUAL_G};                 # Limiti massimi qualità in gradi
param Perd_Perc_Tos{TIPI};           # Perdita peso % durante tostatura
param Min_Perc_Tos{TIPI};            # % minime peso fave per tostatura
param Max_Perc_Tos{TIPI};            # % massime peso fave per tostatura
param Perd_Perc_Mac{TIPI};           # Perdita peso % durante macinatura
param Min_Perc_Mac{TIPI};            # % minime peso chicchi per macinatura
param Max_Perc_Mac{TIPI};            # % massime peso chicchi per macinatura
param Costo{TIPI};                   # Costo al kg di fave

# Variabili
var q{TIPI} >= 0; # Peso delle fave acquistate (kg)

# Funzione obiettivo: minimizzare il costo delle fave
minimize costo_fave:
    sum {i in TIPI} Costo[i] * q[i];

# Vincoli
subject to qualita_gradi {j in QUAL_G}:
    Min_G[j] * Peso <= 
    sum {i in TIPI} Cont_G[j, i] * (1 - Perd_Perc_Mac[i]) * (1 - Perd_Perc_Tos[i]) * q[i]
    <= Max_G[j] * Peso;

subject to perc_peso_minima_tos {i in TIPI}:
    q[i] >= Min_Perc_Tos[i] * sum {ii in TIPI} q[ii];

subject to perc_peso_massima_tos {i in TIPI}:
    q[i] <= Max_Perc_Tos[i] * sum {ii in TIPI} q[ii];

subject to perc_peso_minima_mac {i in TIPI}:
    (1 - Perd_Perc_Tos[i]) * q[i] >= Min_Perc_Mac[i] * sum {ii in TIPI} (1 - Perd_Perc_Tos[ii]) * q[ii];

subject to perc_peso_massima_mac {i in TIPI}:
    (1 - Perd_Perc_Tos[i]) * q[i] <= Max_Perc_Mac[i] * sum {ii in TIPI} (1 - Perd_Perc_Tos[ii]) * q[ii];

subject to peso_finale:
    sum {i in TIPI} (1 - Perd_Perc_Mac[i]) * (1 - Perd_Perc_Tos[i]) * q[i] = Peso;
