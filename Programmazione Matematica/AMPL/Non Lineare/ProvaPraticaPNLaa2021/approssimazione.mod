param n;
param X_1{1..n};
param X_2{1..n};
param Y{1..n};

var m_1;
var m_2;

minimize errore:
  sum{i in 1..n} ( m_1*X_1[i]+m_2*X_2[i] - Y[i] )^2;
