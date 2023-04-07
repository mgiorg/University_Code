#voti in classe

try: 
	x = input('Inserire il voto compreso tra 0 e 10: ')
	voto = float(x)

	if voto > 10:
		print('Formato del voto non valido')
	elif voto >= 9:
		print('Hai preso A')
	elif voto >= 8:
		print('Hai preso B')
	elif voto >= 7:
		print('Hai preso C')
	elif voto >= 6:
		print('Hai preso D')
	else:
		print('Voto Insufficiente')

except: 
	print('Formato del voto non valido')