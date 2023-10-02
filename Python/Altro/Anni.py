#Anni.py
#
#Programma per contare il giorno inserito da terminale
#e dirti il numero del giorno dell'anno inserito

def giornoDellAnno(giorno, mese, anno):
	x = 0
	giorni = 0

	if (anno % 100 == 0) and (anno % 400 == 0):
		x = 1
	elif anno%4 == 0:
		x = 1
	else: x = 0

	if x == 1:

		i = 1
		while i < mese:
			if i==1 or i==3 or i==5 or i==7 or i==8 or i==10 or i==12:
				giorni = giorni + 31
			elif i==2:
				if x==1:
					giorni = giorni + 29
				else: giorni = giorni + 28
			else: giorni = giorni + 30
			i = i+1
		giorni = giorni + giorno
	return giorni

giorno = input("Inserire il giorno: ")
mese = input("Inserire il mese: ")
anno = input("Inserire l'anno: ")

g_totali = giornoDellAnno(int(giorno), int(mese), int(anno))
print("Il giorno che hai inserito è il", g_totali, "-esimo dell'anno!!")


