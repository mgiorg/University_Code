param n;
param X_1{1..n};
param X_2{1..n};
param Y{1..n};

var a_1;
var a_2;
var b_1;
var b_2;
var c;

minimize errore:
  sum{i in 1..n} ( a_1*X_1[i]^2+a_2*X_2[i]^2+b_1*X_1[i]+b_2*X_2[i]+c - Y[i] )^2;
