set MARKETS;  # Set dei mercati
param a {MARKETS};  # Coefficienti a_i delle funzioni di domanda inverse
param b {MARKETS};  # Coefficienti b_i delle funzioni di domanda inverse
param cost;         # Costo unitario di produzione
param Qmax;         # Capacità massima di produzione

var q {MARKETS} >= 0;  # Quantità prodotta per ogni mercato

# Funzione obiettivo: Massimizzare il profitto
maximize Profit:
    sum {i in MARKETS} (a[i] * q[i] - b[i] * q[i]^3 - cost * q[i]);

# Vincolo sulla capacità totale
subject to Capacity:
    sum {i in MARKETS} q[i] <= Qmax;
