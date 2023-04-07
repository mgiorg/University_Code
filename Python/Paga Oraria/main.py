#Stipendio con maggiorazione di 1,5 volte la paga per le ore di straordinario (dopo le 40)
try: 
	x = input('Inserire ore di lavoro settimanali: ')
	ore = int(x)

	x = input('Inserire paga oraria: ')
	paga = float(x) #salvo il valore come float, mi servirà dopo

	if ore > 40:
		straordinario = ore - 40 

		totale = 40 * paga + straordinario * (paga * 1.5)

	else:
		straordinario = 0

		totale = ore * paga

	print('Il totale dei soldi guadagnati questo mese è di: ', totale, ' euro')

except: #esce dal programma se ha riscontrato errori
	print('Prego inserire un numero valido per il calcolo')
