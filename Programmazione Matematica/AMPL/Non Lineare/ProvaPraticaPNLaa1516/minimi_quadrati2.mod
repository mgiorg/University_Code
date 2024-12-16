param n;
param X_1{1..n};
param X_2{1..n};
param Y{1..n};

var m_1;
var m_2;
var q;
var z;

minimize errore: z;

subject to limite1 {i in 1..n}:
  m_1*X_1[i]+m_2*X_2[i]+q - Y[i] <= z;

subject to limite2 {i in 1..n}:
  -(m_1*X_1[i]+m_2*X_2[i]+q - Y[i]) <= z;
