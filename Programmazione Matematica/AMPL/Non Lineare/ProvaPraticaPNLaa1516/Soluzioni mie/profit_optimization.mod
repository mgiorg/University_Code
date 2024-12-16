
# File: profit_optimization.mod

# Sets and Parameters
set MARKETS;  # Mercati
param a {MARKETS};  # Parametri della funzione di domanda inversa
param b {MARKETS};  # Coefficienti quadratici
param cost;         # Costo unitario di produzione
param Qmax;         # Capacità massima di produzione

# Variables
var q {MARKETS} >= 0;  # Quantità prodotta per ogni mercato

# Objective: Massimizzare il profitto
maximize Profit:
    sum {m in MARKETS} (a[m] * q[m] - b[m] * q[m]^2) - cost * sum {m in MARKETS} q[m];

# Vincolo: Capacità massima di produzione
subject to Capacity:
    sum {m in MARKETS} q[m] <= Qmax;
