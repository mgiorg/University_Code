param n;
param X_1{1..n};
param X_2{1..n};
param X_3{1..n};
param Y{1..n};

var a_1;
var a_2;
var a_3;
var b_1;
var b_2;
var b_3;
var m_1;
var m_2;
var m_3;
var q;

minimize errore:
  sum{i in 1..n} ( a_1*X_1[i]^2+a_2*X_2[i]^2+a_3*X_3[i]^2+b_1*X_1[i]*X_2[i]+b_2*X_2[i]*X_3[i]+b_3*X_3[i]*X_1[i]+m_1*X_1[i]+m_2*X_2[i]+m_3*X_3[i]+q - Y[i] )^2;
