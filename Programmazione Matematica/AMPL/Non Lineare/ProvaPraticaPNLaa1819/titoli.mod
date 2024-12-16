set TITOLI := 1..4;

param rm{TITOLI};
param var{TITOLI};
param rendimento_minimo;

var x{TITOLI} >= 0;
var delta binary;

minimize rischio:
  sum{i in TITOLI} var[i]*x[i]^2;

subject to frazioni:
  sum{i in TITOLI} x[i] = 1;

subject to rendimento:
  sum{i in TITOLI} rm[i]*x[i] >= rendimento_minimo;

subject to logico1:
  x[2] <= delta;

subject to logico2:
  delta*0.2 <= x[4];

