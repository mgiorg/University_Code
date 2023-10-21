from funzioni_esercizi import isIntero
	
s = input("Inserire numero intero: ")

controllo = isIntero(s)
if controllo == True:
	print("Ok")

else:
	print("Riprova")
			
		