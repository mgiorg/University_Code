s1 = input("Inserire stringa 1: ")
s2 = input("Inserire stringa 2: ")

for i in s1: 
    if s2.find(i) == -1:
        print(i, end = '')