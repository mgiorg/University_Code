#Scrivere un programma che 
#prende in input un reale x che rappresenta un valore in 
#gradi e restituisce il valore del coseno di x.

import math

x = float(input("Inserire angolo in gradi: "))
c = math.cos(math.radians(x))
print(c)
