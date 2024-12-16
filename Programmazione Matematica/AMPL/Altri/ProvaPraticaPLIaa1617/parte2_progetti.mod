set Progetti ordered; # Insieme dei progetti
set Periodi ordered; # Insieme dei periodi (t = 1..n)

param RhoBar; # Tasso di interesse minimo accettabile
param FlussoCassa{Progetti, Periodi}; # Flusso di cassa generato da ciascun progetto in ciascun periodo
param Budget{Periodi}; # Budget disponibile in ciascun periodo

# Calcolo del flusso di cassa attualizzato
param FlussoCassaAtt{i in Progetti, j in Periodi} :=
    FlussoCassa[i, j] / (1 + RhoBar) ^ (ord(j, Periodi)-1);

var Attivazione{Progetti} binary; # 1 se il progetto è attivato, 0 altrimenti

maximize ValoreAttualizzato:
    sum{i in Progetti, t in Periodi} FlussoCassaAtt[i, t] * Attivazione[i];

# Vincolo sul budget in ciascun periodo
subject to VincoloBudget {t in Periodi}:
    - sum{i in Progetti} FlussoCassa[i, t] * Attivazione[i] <= Budget[t];

# Vincolo di dipendenza tra progetti dispari e pari successivi
subject to vinc1:
    Attivazione['P2'] <= Attivazione['P1'];
subject to vinc2:
    Attivazione['P4'] <= Attivazione['P3'];
subject to vinc3:
    Attivazione['P6'] <= Attivazione['P5'];
