from funzioni_esercizi import *

n1 = input("Inserire n1: ")
n2 = input("Inserire n2: ")
d = input("Inserire d: ")

c1 = isIntero(n1)
c2 = isIntero(n2)
c3 = isIntero(d)

if c1 == True and c2 == True and c3 == True:
	controllo = divisoreNonComune(int(n1), int(n2), int(d))

	if controllo == True:
		print(d, " è un divisore di ", n1, " non comune a ", n2, sep = '')
	
	else:
		print(d, " NON è un divisore di ", n1, " non comune a ", n2, sep = '')

else:
	print("Errore, non sono numeri interi")