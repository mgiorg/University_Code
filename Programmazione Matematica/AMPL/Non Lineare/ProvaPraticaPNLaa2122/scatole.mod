param num_scatole := 3;

var x{1..num_scatole} >= 0.3;
var y{1..num_scatole} >= 0.3;
var z{1..num_scatole} >= 0.3;

maximize volumi:
  sum{i in 1..num_scatole} x[i]*y[i]*z[i];

subject to altezze:
  z[1] = 2*z[2];

subject to superfici:
  sum{i in 1..num_scatole} (2*x[i]*y[i] + 2*x[i]*z[i] + 2*y[i]*z[i]) <= 10;

