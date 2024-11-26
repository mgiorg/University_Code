
set Progetti ordered;
set Periodi ordered;

param RhoBar; # Tasso di interesse minimo accettabile
param FlussoCassa{Progetti, Periodi};
param Budget{Periodi};
param FlussoCassaAtt{i in Progetti, t in Periodi} := (FlussoCassa[i, t] / (1 + RhoBar) ^ (ord(t, Periodi) - 1));

var Attivazione{Progetti} binary;

maximize ValoreAttualizzato:
    sum{i in Progetti, t in Periodi} FlussoCassaAtt[i, t] * Attivazione[i];

# Vincolo sul budget in ciascun periodo
subject to BudgetPeriodi {t in Periodi}:
    - sum{i in Progetti} FlussoCassa[i, t] * Attivazione[i] <= Budget[t];

# Vincoli di dipendenza
subject to DipendenzaProgetto4:
    2*Attivazione["Progetto4"] <= Attivazione["Progetto1"]+Attivazione["Progetto7"];

# Almeno due tra i progetti 5, 6 e 7 devono essere attivati
subject to AlmenoDue:
    Attivazione["Progetto5"] + Attivazione["Progetto6"] + Attivazione["Progetto7"] >= 2;
