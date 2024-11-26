
set CITY; # Cities

param K {CITY}; # Capacity of each city center
param d {CITY}; # Demand of each city
param f {CITY}; # Fixed activation cost of each center
param c {CITY, CITY}; # Cost of serving a city from another center

var y {CITY, CITY} >= 0, <= 1; # Flow of service
var x {CITY} binary; # Whether a center is activated

minimize cost:
    sum {i in CITY} f[i] * x[i] + sum {i in CITY, j in CITY} c[i,j] * y[i,j];

subject to capacity {i in CITY}:
    sum {j in CITY} y[i,j] * d[j] <= K[i] * x[i];

subject to activation {i in CITY}:
    sum{j in CITY} y[i,j] = 1;

subject to dependency:
    x["Latina"] <= x["Aprilia"];
