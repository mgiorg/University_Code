set PUNTI;

param P{PUNTI,1..3};

var F{1..3};

minimize distanza:
 sum{i in PUNTI} sqrt( sum{j in 1..3} (P[i,j]-F[j])^2 );

subject to v:
 sum{j in 1..3} (P['D',j]-F[j])^2 <= 4;
