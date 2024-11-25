
set Progetti; # Set di progetti
set Periodi ordered; # Set di periodi

param FlussoCassa{Progetti, Periodi}; # Flusso di cassa generato per progetto e periodo
param Budget{Periodi}; # Budget disponibile per periodo
param Interesse; # Tasso di interesse minimo accettabile

var Attivazione{Progetti} binary; # Variabile binaria di attivazione

maximize NPV:
    sum {p in Progetti, t in Periodi} FlussoCassa[p, t] * Attivazione[p] / (1 + Interesse)^(ord(t, Periodi) - 1);

subject to BudgetConstraint {t in Periodi}:
    - sum {p in Progetti} FlussoCassa[p, t] * Attivazione[p] <= Budget[t];

subject to DipendenzaProgetti:
    2*Attivazione["Progetto4"] <= Attivazione["Progetto1"] + Attivazione["Progetto7"];

subject to AlmenoDueTra567:
    Attivazione["Progetto5"] + Attivazione["Progetto6"] + Attivazione["Progetto7"] >= 2;
