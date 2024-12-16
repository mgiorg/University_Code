param l_c;
param h_c_max;
param h_c_min;
param m;

var r >= 0;
var h >= 0;

maximize volume: r*r*3.14*h;

subject to base: 2*r <= l_c;

subject to altezza: h <= h_c_max - (h_c_max-h_c_min)*2*r/l_c;

subject to sup: 2*r*r*3.14 + 2*r*3.14*h <= m;

