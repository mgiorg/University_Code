x = int(input("Inserire numero compreso tra 0 e 10 inclusi: "))
y = int(input("Inserire numero compreso tra 0 e 10 inclusi: "))

for i in range(11):
	if i != x and i != y:
		print(i)