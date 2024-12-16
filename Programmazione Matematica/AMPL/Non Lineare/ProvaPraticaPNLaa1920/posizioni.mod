param h1 := 10;
param h2 := 8;
param h3 := 12;

var x1>=10;
var y1>=1;
var x2<=-10;
var y2>=1;
var x3;
var y3<=-10;

minimize perimetro: sqrt((x1-x2)^2+(y1-y2)^2) +
                    sqrt((x1-x3)^2+(y1-y3)^2) +
                    sqrt((x2-x3)^2+(y2-y3)^2);

s.t. distanza_castello1: x1^2+y1^2 >= (h1+5)^2;
s.t. distanza_castello2: x2^2+y2^2 >= (h2+5)^2;
s.t. distanza_castello3: x3^2+y3^2 >= (h3+5)^2;

s.t. distanza_1_2: (x1-x2)^2+(y1-y2)^2 >= (20)^2;
s.t. distanza_1_3: (x1-x3)^2+(y1-y3)^2 >= (20)^2;
s.t. distanza_2_3: (x2-x3)^2+(y2-y3)^2 >= (20)^2;

