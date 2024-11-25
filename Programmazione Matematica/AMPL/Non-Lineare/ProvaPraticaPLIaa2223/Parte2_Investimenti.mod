# File: Parte2_Investimenti.mod

# Dichiarazione di set
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
    sum{i in PROGETTI} sum{t in PERIODI} 
        (FlussoCassa[i, t] / (1 + TassoInteresse)^(ord(t, PERIODI) - 1)) * Attiva[i];

# Vincoli
subject to RispettoBudget{t in PERIODI}:
    - sum{i in PROGETTI} (FlussoCassa[i, t] * Attiva[i]) <= Budget[t];

# Vincoli di dipendenza logici
subject to Dipendenza1:
    4 * Attiva[4] <= Attiva[1] + Attiva[2] + Attiva[5] + Attiva[7];

subject to Dipendenza2:
    Attiva[7] <= Attiva[1];
