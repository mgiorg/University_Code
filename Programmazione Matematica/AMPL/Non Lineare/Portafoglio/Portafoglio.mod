# File: portafoglio_titoli.mod

# Sets
set TITOLI;  # Set dei titoli
set PERIODI;  # Periodi storici

# Parameters
param prezzo_attuale {TITOLI};  # Prezzi odierni dei titoli
param prezzi_storici {TITOLI, PERIODI};  # Prezzi storici dei titoli
param budget_totale;  # Budget totale disponibile
param n_periodi := sum {t in PERIODI} 1;  # Numero di periodi storici

# Regressione lineare per ogni titolo
param sum_t := sum {t in PERIODI} t;  # Somma dei periodi
param sum_t_squared := sum {t in PERIODI} t^2;  # Somma dei quadrati dei periodi

param intercept {i in TITOLI} :=
    (sum {t in PERIODI} prezzi_storici[i, t] * sum_t - n_periodi * sum {t in PERIODI} t * prezzi_storici[i, t]) /
    (sum_t_squared - (sum_t)^2 / n_periodi);

param slope {i in TITOLI} :=
    (n_periodi * sum {t in PERIODI} t * prezzi_storici[i, t] - sum_t * sum {t in PERIODI} prezzi_storici[i, t]) /
    (n_periodi * sum_t_squared - (sum_t)^2);

param valore_previsto {i in TITOLI} :=
    intercept[i] + slope[i] * (n_periodi + 1);

# Variabili ausiliarie
param media_prezzi {i in TITOLI} :=
    (1 / n_periodi) * sum {t in PERIODI} prezzi_storici[i, t];

param varianza {i in TITOLI} :=
    (1 / n_periodi) * sum {t in PERIODI} (prezzi_storici[i, t] - media_prezzi[i])^2;

param covarianza {i in TITOLI, j in TITOLI} :=
    (1 / n_periodi) * sum {t in PERIODI} (prezzi_storici[i, t] - media_prezzi[i]) * (prezzi_storici[j, t] - media_prezzi[j]);

# Decision variables
var allocazione {TITOLI} >= 0;  # Allocazione del budget su ogni titolo
var budget_rimanente >= 0;  # Budget non utilizzato

# Objective
maximize CreditiFinali:
    sum {i in TITOLI} (allocazione[i] / prezzo_attuale[i]) * valore_previsto[i] + budget_rimanente;

# Constraints
s.t. BudgetConstraint:
    sum {i in TITOLI} allocazione[i] + budget_rimanente = budget_totale;

s.t. RischioConstraint:
    sum {i in TITOLI} varianza[i] * (allocazione[i] / prezzo_attuale[i])^2 +
    2 * sum {i in TITOLI, j in TITOLI: i != j} covarianza[i, j] * 
    (allocazione[i] / prezzo_attuale[i]) * (allocazione[j] / prezzo_attuale[j]) <= 0.4 * budget_totale;
