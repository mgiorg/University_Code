set PROD;

param p_a{PROD};
param p_m;

var q{PROD} >= 0;

maximize profitto: sum{i in PROD} (p_a[i] - p_m * q[i]) * q[i];

s.t. vincolo: (p_a['p2'] - p_m * q['p2']) <= 0.5 * (p_a['p1'] - p_m * q['p1']);

