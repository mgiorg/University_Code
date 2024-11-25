
set PROGETTI;  # Set dei progetti disponibili
set PERIODI ordered;  # Periodi temporali ordinati

param FlussoCassa{PROGETTI, PERIODI};  # Flusso di cassa per ogni progetto e periodo
param Budget{PERIODI};  # Budget disponibile per ogni periodo
param TassoInteresse;  # Tasso di interesse annuo

# Parametro per il flusso di cassa attualizzato
param FlussoCassaAtt{i in PROGETTI, j in PERIODI} :=
    FlussoCassa[i, j] / (1 + TassoInteresse)^(ord(j, PERIODI) - 1);

var x{PROGETTI} binary;  # Variabile binaria: selezione del progetto

# Funzione obiettivo: Massimizzare il valore attualizzato netto (NPV)
maximize NPV:
    sum {i in PROGETTI} sum {j in PERIODI} FlussoCassaAtt[i, j] * x[i];

# Vincolo di budget
subject to vincolo_budget {j in PERIODI}:
    -sum {i in PROGETTI} FlussoCassa[i, j] * x[i] <= Budget[j];

# Vincolo di dipendenza tra progetti
subject to dipendenza_agricoltura:
    x["espansione_agricola"] <= x["protezione_ambientale"];

# Almeno uno tra i progetti richiesti deve essere attivato
subject to almeno_uno:
    x["potenziamento_difese"] + x["sviluppo_economico"] + x["diplomazia_alleanze"] >= 1;
