var h1 >= 0;
var h2 >= 0;
var h3 >= 0;
var r1 >= 0;
var r2 >= 0;
var r3 >= 0;

maximize volume: r1*r1*3.14*h1 + r2*r2*3.14*h2 + r3*r3*3.14*h3;

s.t. base1: r1*r1*3.14 >= 2;
s.t. base2: r2*r2*3.14 >= 2;
s.t. base3: r3*r3*3.14 >= 2;
s.t. torre1: h1 >= 10;
s.t. torre2_1: 2*r2*3.14*h2 >= 80;
s.t. torre2_2: h2 >= 8;
s.t. torre3_1: h3 >= h1+2;
s.t. torre3_2: h3 >= h2+2;
s.t. superficie: 2*r1*3.14*h1 + 2*r2*3.14*h2 + 2*r3*3.14*h3 <= 200;

