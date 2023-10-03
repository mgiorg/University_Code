#Scrivere un programma che prende in input 2 numeri reali x e y, 
#e un numero intero n e stampa il risultato della divisione di x per y, 
#arrotondato ad n cifre decimali.

x = float(input("Inserire numero: "))
y = float(input("Inserire numero: "))
n = int(input("Inserire arrotondamento: "))

a = x/y
b = round(a, n)
print("\n", b)
