
set PROD; # Set of products

param p {PROD}; # Net profit per unit of product
param F {PROD}; # Fixed cost to include the product
param u {PROD}; # Maximum amount of each product
param max_snack_types; # Maximum number of snack types allowed
param max_capacity; # Total capacity of the distributor
param min_drinks; # Minimum quantity of drinks
param min_snacks; # Minimum quantity of snacks
param min_water_ratio; # Minimum water to drinks ratio

var x {i in PROD} integer, >= 0, <= u[i]; # Quantity of each product
var y {i in PROD} binary; # Whether a product is included

maximize profit:
    sum {i in PROD} (p[i] * x[i] - F[i] * y[i]);

subject to capacity:
    sum {i in PROD} x[i] <= max_capacity;

subject to drinks:
    sum {i in PROD : i in {"acqua naturale", "acqua frizzante", "cola", "gassosa", "chinotto", "cedrata"}} x[i] >= min_drinks;

subject to snacks:
    sum {i in PROD : i in {"arachidi", "anacardi", "pistacchi", "chips", "biscotti"}} x[i] >= min_snacks;

subject to water_ratio:
    sum {i in PROD : i in {"acqua naturale", "acqua frizzante"}} x[i] >= min_water_ratio * sum {i in PROD : i in {"cola", "gassosa", "chinotto", "cedrata"}} x[i];

subject to snack_types:
    sum {i in PROD : i in {"arachidi", "anacardi", "pistacchi", "chips", "biscotti"}} y[i] <= max_snack_types;

subject to inclusion_logic {i in PROD}:
    x[i] <= u[i] * y[i];
