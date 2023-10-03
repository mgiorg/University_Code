#Sostituire il carattere 'c' nela stringa

s = input("Inserire una stringa: ")
a = s.find('c')
s1 = s.replace(s[a], '1')
a = s.find('c')
s2 = s.replace(s[a], '2')
a = s.find('c')
s3 = s.replace(s[a], '3')

print(s1)
