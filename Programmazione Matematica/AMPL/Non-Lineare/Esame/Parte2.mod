set LUOGHI;
set ASTRONAVI;

param M := 1000; # Big-M per vincoli logici
param TempoTotale; # Tempo massimo disponibile per ciascuna astronave
param TempoTeletrasporto {ASTRONAVI}; # Tempo per lavoratori normali
param Accelerato {ASTRONAVI}; # Tempo per lavoratori in modalità accelerata
param MaxAccelerato; # Massimo numero di lavoratori in modalità accelerata
param MinLavoratori {LUOGHI}; # Minimo lavoratori per ciascun luogo

var x {LUOGHI, ASTRONAVI} >= 0, <= M, integer; 
var y {LUOGHI, ASTRONAVI} >= 0, <= M, integer; 
var z {LUOGHI, ASTRONAVI} >= 0, <= M, integer; 
var acc {ASTRONAVI} binary; 

maximize TotaleLavoratori:
    sum {l in LUOGHI, a in ASTRONAVI} x[l, a];

subject to TempoMax {a in ASTRONAVI}:
    sum {l in LUOGHI} (y[l, a] * Accelerato[a] + z[l, a] * TempoTeletrasporto[a]) <= TempoTotale;

subject to Separazione {l in LUOGHI, a in ASTRONAVI}:
    x[l, a] = y[l, a] + z[l, a];

subject to MinimoLavoratori {l in LUOGHI}:
    sum {a in ASTRONAVI} x[l, a] >= MinLavoratori[l];

subject to LimiteAcceleratoAstronavi:
    sum {a in ASTRONAVI} acc[a] = 3;

subject to MassimoAccelerato:
    sum {l in LUOGHI, a in ASTRONAVI} y[l, a] <= MaxAccelerato;

subject to CollegamentoAccelerato {l in LUOGHI, a in ASTRONAVI}:
    y[l, a] <= acc[a] * x[l, a];

subject to RelazioneXY {l in LUOGHI, a in ASTRONAVI}:
    y[l, a] <= x[l, a];

subject to NoAcceleratoNonAttivo {l in LUOGHI, a in ASTRONAVI}:
    y[l, a] <= acc[a] * M;
