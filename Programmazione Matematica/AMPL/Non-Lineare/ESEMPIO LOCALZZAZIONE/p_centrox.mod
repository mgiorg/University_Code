set SITI;   # Siti candidati per i centri
set QUARTIERI;   # Quartieri da servire

param p;  # Numero di centri da attivare
param c{SITI, QUARTIERI};  # Tempi medi di percorrenza

var x{i in SITI} binary;  # Variabile: attivazione del sito i
var y{i in SITI, j in QUARTIERI} binary;  # Variabile: assegnazione del quartiere j al sito i
var z >= 0;  # Tempo massimo da minimizzare

# Funzione obiettivo: Minimizzare il tempo massimo di percorrenza
minimize tempo_massimo: z;

# Vincoli
subject to copertura{j in QUARTIERI}:
    sum {i in SITI} y[i, j] = 1;  # Ogni quartiere è servito da un sito

subject to attivazione{i in SITI, j in QUARTIERI}:
    y[i, j] <= x[i];  # Quartiere j può essere servito solo se il sito i è attivo

subject to limite_p:
    sum {i in SITI} x[i] = p;  # Esattamente p centri devono essere attivati

subject to tempo_massimo_vinc{j in QUARTIERI}:
    z >= sum {i in SITI} c[i, j] * y[i, j];  # Definizione di z come tempo massimo
