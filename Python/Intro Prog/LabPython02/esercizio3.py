n = int(input("Inserire numeratore: "))
d = int(input("Inserire denominatore: "))

if n < d:
    print("La frazione è PROPRIA!!!")

elif n == d or n%d == 0:
    print("La frazione è APPARENTE!!!")

elif n > d and n%d != 0:
    print("La frazione è IMPROPRIA!!!")