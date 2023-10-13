n = int(input("Inserire numero intero: "))
print('"', end = '')
for i in range(n+1):
	if i>0 and n%i == 0 and i<n:
		print(i, ', ', sep = '', end = '')
	if i == n:
		print(i, '"', sep = '')

