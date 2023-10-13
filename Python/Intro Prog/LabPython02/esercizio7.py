n = int(input("Inserire un intero > 2: "))

for i in range(n+1):
    if i >= 2 and i%2 == 0:
        print('"', i, '"', sep = '')