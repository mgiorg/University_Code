set PROGETTI; # Progetti disponibili
set PERIODI ordered; # Periodi temporali

param flusso {PROGETTI, PERIODI}; # Flusso di cassa per progetto e periodo
param budget {PERIODI}; # Budget disponibile per periodo
param tasso := 0.03; # Tasso minimo accettabile
param FlussoCassaAtt {i in PROGETTI, t in PERIODI}:= 
	flusso[i,t] / (1 + tasso)^(ord(t,PERIODI)-1);

var x {PROGETTI} binary; # Attivazione dei progetti

maximize npv:
    sum {i in PROGETTI, t in PERIODI} FlussoCassaAtt[i, t] * x[i];

subject to budget_limit {t in PERIODI}:
    -sum {i in PROGETTI} flusso[i,t] * x[i] <= budget[t];

subject to vincoli_logici_1:
    4*x["Progetto 4"] <= x["Progetto 1"] + x["Progetto 2"] + x["Progetto 5"] + x["Progetto 7"];

subject to vincoli_logici_2:
    x["Progetto 7"] <= x["Progetto 1"];