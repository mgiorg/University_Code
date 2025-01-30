# Modello per l'Esercizio 3
set TITOLI;

param r{TITOLI};      # Rendimento medio
param sigma2{TITOLI}; # Varianza del rendimento
param M := 1;         # Grande valore per vincolo binario

var x{TITOLI} >= 0;   # Proporzione del capitale investito
var y2 binary;        # Variabile binaria per il titolo 2

# Funzione obiettivo: Minimizzare il rischio
minimize Rischio: sum{i in TITOLI} sigma2[i] * x[i]^2;

# Vincolo: Il capitale totale è allocato
subject to CapitaleTotale:
    sum{i in TITOLI} x[i] = 1;

# Vincolo: Rendimento medio minimo
subject to RendimentoMedio:
    sum{i in TITOLI} r[i] * x[i] >= 8;

# Collegare y2 a x2
subject to CollegamentoY2:
    x[2] <= M * y2;

# Se y2 = 1, allora x4 >= 0.2
subject to InvestimentoTitolo2:
    x[4] >= 0.2 * y2;
