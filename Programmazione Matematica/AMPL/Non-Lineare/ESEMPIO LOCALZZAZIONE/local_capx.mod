
set SITI;   # Siti candidati
set QUARTIERI;   # Quartieri da servire

param c{SITI, QUARTIERI};  # Costi/tempi di trasporto
param K{SITI};  # Capacità massima dei siti
param d{QUARTIERI};  # Domanda di ogni quartiere
param costi_fissi{SITI};  # Costi fissi per attivare i siti

var x{i in SITI} binary;  # Variabile: attivazione del sito i
var y{i in SITI, j in QUARTIERI} >= 0, <= 1;  # Frazione della domanda del quartiere j assegnata al sito i

# Funzione obiettivo: Minimizzare il costo complessivo (fissi + trasporto)
minimize costo_totale:
    sum {i in SITI} costi_fissi[i] * x[i] +
    sum {i in SITI, j in QUARTIERI} c[i, j] * y[i, j];

# Vincoli
subject to copertura{j in QUARTIERI}:
    sum {i in SITI} y[i, j] = 1;  # Ogni quartiere è completamente servito

subject to attivazione{j in QUARTIERI, i in SITI}:
    y[i, j] <= x[i];  # La domanda può essere soddisfatta solo da centri attivi

subject to capacita{i in SITI}:
    sum {j in QUARTIERI} d[j] * y[i, j] <= K[i] * x[i];  # Capacità rispettata solo se il centro è attivo
