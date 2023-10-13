n1 = int(input("Inserire numero intero: "))
n2 = int(input("Inserire numero intero: "))

x = n2//n1
if n2//n1 == False:
	print("Input non valido")

for i in range(x+1):
	if i != 0:
		print(n1*i)
