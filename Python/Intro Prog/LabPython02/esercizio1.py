s = input("Inserire una stringa")

if len(s) == 0:
    print("La stringa è vuota")

else:
    if s[0] == s[len(s)-1]:
        print("Caratteri iniziale e finale uguali")
    else:
        print("Carattere iniziale e finale diversi")