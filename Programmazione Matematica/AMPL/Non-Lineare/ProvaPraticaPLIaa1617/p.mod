set Progetti;                        # Set dei progetti
set Periodi ordered;                         # Set dei periodi
param cashflow {Progetti, Periodi};  # Flussi di cassa
param budget {Periodi};              # Budget per periodo
param sconto {Periodi};              # Fattori di sconto per periodo (precalcolati)
param FlussoCassaAtt{i in Progetti,j in Periodi} :=
 cashflow[i,j]/(1+0.03)^(ord(j,Periodi)-1);

# Variabili
var z {Progetti}, binary;            # 1 se il progetto è attivato, 0 altrimenti

# Funzione obiettivo: massimizzare NPV
maximize NPV:
    sum {i in Progetti} sum{t in Periodi} FlussoCassaAtt[i, t] * z[i];

# Vincoli
subject to Budget {t in Periodi}:
    - sum {i in Progetti} cashflow[i, t] * z[i] <= budget[t];

subject to l1:
	z['P2'] <= z['P1'];

subject to l2:
	z['P4'] <= z['P3'];
	
subject to l3:
	z['P6'] <= z['P5'];
