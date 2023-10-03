#Scrivere un programma che prende in input un carattere 
#e stampa un quadrato di lato 3 usando quel carattere. 
#Ad esempio se il carattere è ‘*’ il programma deve stampare:
#***
#***
#***

c = input("Inserire carattere: ")
print(c*3 + '\n' + c*3 + '\n' + c*3)