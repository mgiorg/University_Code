#Memorizzare la filastrocca:

s = "Apelle, figlio di Apollo\nFece una palla di pelle di pollo\nTutti i pesci vennero a galla\nPer vedere la palla di pelle di pollo\nFatta da Apelle figlio di Apollo"

# a) stampi la stringa in modo tale che vada a capo alla fine di ogni verso
print(s)

# b) stampi la lunghezza della stringa
print("La lunghezza della stringa è: ", len(s))

# c) stampi il numero totale di occorrenze di 'll'
print("Numero di occorrenze di 'll'", s.count("ll"))

# d) stampi il numero di occorrenze di 'll' in ogni verso
a = s.find("\n")
s1 = s[:a]
print("Nel verso 1, ‘ll’ compare ", s1.count('ll'), " volte")
a = s.find("\n")
s2 = s[1:a]
print("Nel verso 2, ‘ll’ compare ", s2.count('ll'), " volte")
a = s.find("\n")
s3 = s[2:a]
print("Nel verso 3, ‘ll’ compare ", s3.count('ll'), " volte")
a = s.find("\n")
s4 = s[3:a]
print("Nel verso 4, ‘ll’ compare ", s4.count('ll'), " volte")
s5 = s[4:a]
print("Nel verso 5, ‘ll’ compare ", s5.count('ll'), " volte")