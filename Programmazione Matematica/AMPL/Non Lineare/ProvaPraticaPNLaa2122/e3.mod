set TIPI;

param a{TIPI};       # Valore atteso di a
param sigma2{TIPI};  # Varianza di a
param TotaleProd := 1000;  # Totale lampade
param MaxVarianza := 0.2;

var q{TIPI} >= 0, integer;  # Quantità intera di ciascun tipo
var frazione{TIPI} >= 0;    # Frazione prodotta di ciascun tipo

# Funzione obiettivo: Massimizzare il profitto
maximize Profitto:
    sum{i in TIPI} q[i] * (a[i] - 0.002 * q[i]);

# Vincolo: Totale lampade prodotte
subject to TotaleLampade:
    sum{i in TIPI} q[i] = TotaleProd;

# Vincolo: Rischio (varianza)
subject to VincoloVarianza:
    sum{i in TIPI} sigma2[i] * frazione[i]^2 <= MaxVarianza;

# Vincolo: Calcolo frazioni
subject to CalcoloFrazione{i in TIPI}:
    frazione[i] = q[i] / TotaleProd;
