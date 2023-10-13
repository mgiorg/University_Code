temp = int(input("Inserire la temperatura: "))
tipo = input("Inserire tipo: 'C' = Celsius, 'F' = Fahrenheit: ")

if tipo == 'F':
	celsius = (temp - 32)/1.8
else:
	celsius = temp

if celsius <= 0:
	print("Solida")
elif celsius >= 100:
	print("Gassosa")
else:
	print("Liquida")