param n;
param X_1{1..n};
param X_2{1..n};
param X_3{1..n};
param Y{1..n};

var a_12;
var m_1;
var m_2;
var m_3;
var q;

minimize errore:
  sum{i in 1..n} ( a_12*X_1[i]*X_2[i]+m_1*X_1[i]+m_2*X_2[i]+m_3*X_3[i]+q - Y[i] )^2;
