var h >= 0.001;
var r >= 0.001;

maximize volume: 3.14*r*r*h/3;

s.t. superficie: (3.14*r)^2*(h*h+r*r) <= (3 - 3.14*r*r)^2;

