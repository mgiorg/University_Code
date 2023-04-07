#schema funzioni python
# .
#  .
#   .
   
type('argomento') #tipo di dato tra parentesi

max('valori')
min('valori') #funzione massimo e minimo

len('stringa o dato') #numero di oggetti tra parentesi

int()
float()
str() # conversione in int, float e string

import math #funzioni matematiche
math.log10('ratio')
math.sin('radianti')
math.cos('radianti')
math.sqrt('numero') #radice quadrata

math.pi #valore di pi-greco approssimato a 15 cifre

import random #gestione casuale di dati

#funzioni in random:
	random(): #genera numeri casuali nell'intervallo [0.0, 0.1)
	randint(low_value, high_value): #genera numeri casuali interi tra il minimo e il massimo (inclusi)

	t = [1, 2, 3]
	choice(t): #stampa random uno dei valori di t


#definizione funzioni:
def nomeFunzione('parametri'):
	'corpo'
	return valore

x = nomeFunzione('parametri')
