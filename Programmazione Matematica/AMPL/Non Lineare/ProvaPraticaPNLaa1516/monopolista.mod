set MERCATI;

param a{MERCATI};
param b{MERCATI};
param c;
param prod_max;

var q{MERCATI} >= 0;

maximize profitto: sum{i in MERCATI} ( (a[i]-b[i]*q[i]^2)*q[i] - c*q[i]);

subject to limite:
  sum{i in MERCATI} q[i] <= prod_max;
