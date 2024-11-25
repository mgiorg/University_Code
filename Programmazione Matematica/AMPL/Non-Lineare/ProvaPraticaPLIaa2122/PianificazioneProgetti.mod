
# File: PianificazioneProgetti.mod

# Set
set PROGETTI;
set PERIODI ordered;

# Parametri
param FlussoCassa{PROGETTI, PERIODI};
param Budget{PERIODI};
param TassoInteresse;

# Variabili
var Attiva{PROGETTI} binary;

# Funzione obiettivo
maximize NPV:
    sum{i in PROGETTI, t in PERIODI}
        (FlussoCassa[i, t] / (1 + TassoInteresse)^(ord(t, PERIODI) - 1)) * Attiva[i];

# Vincoli
subject to RispettoBudget{t in PERIODI}:
    - sum{i in PROGETTI} (FlussoCassa[i, t] * Attiva[i]) <= Budget[t];

# Vincoli logici
subject to Dipendenza1:
    3 * Attiva[4] <= Attiva[1] + Attiva[2] + Attiva[7];

subject to Dipendenza2:
    3 * Attiva[5] <= Attiva[1] + Attiva[2] + Attiva[7];
