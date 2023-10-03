#Scrivere un programma che chiede in input all’utente un numero di ore hh, 
#numero di minuti mm e numero di secondi ss e stampa a video 
#l’equivalente in numero secondi. 
#Ad esempio, se hh = 2, mm = 1 e ss = 11, il programma deve stampare “7271”.

h = int(input("Inserire ore: "))
m = int(input("Inserire minuti: "))
s = int(input("Inserire secondi: "))

totale_secondi = h*3600 + m*60 + s
print(totale_secondi)