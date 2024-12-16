set LAMPADE;

param a_E{LAMPADE};
param a_sigma2{LAMPADE};
param m;
param qta_tot;
param rischio_max;

var qta{LAMPADE} integer, >= 0;

maximize profitto:
  sum{i in LAMPADE} (a_E[i]-m*qta[i])*qta[i];

subject to totale:
  sum{i in LAMPADE} qta[i] = qta_tot;

subject to rischio:
  sum{i in LAMPADE} a_sigma2[i]*(qta[i]/qta_tot)^2 <= rischio_max;

