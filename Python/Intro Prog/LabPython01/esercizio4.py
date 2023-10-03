#Scrivere un programma che prenda in ingresso i 3 coefficienti (a, b e c) di un’equazione 
#di secondo grado (y = a x2 + b x + c) ed un valore per la x e stampi il corrispondente 
#valore della y

import math

a = float(input("Inserire coefficiente a: "))
b = float(input("Inserire coefficiente b: "))
c = float(input("Inserire coefficiente c: "))

x = float(input("Inserire valore per la x: "))
y = float(a*math.pow(x, 2) + b*x + c)

print("La soluzione è y = ", y)