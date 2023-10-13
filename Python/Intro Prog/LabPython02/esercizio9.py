a = int(input("Inserire lato: "))
b = int(input("Inserire lato: "))
c = int(input("Inserire lato: "))

if a>0 and b>0 and c>0 and a+b>c and a+c>b and b+c>a:
	if a == b and b == c:
		print("Triangolo Equilatero")
	elif a == b and a!= c:
		print("Triangolo Isoscele")
	elif b == c and a!= b:
		print("Triangolo Isoscele")
	elif a == c and a!= b:
		print("Triangolo Isoscele")
	else:
		print("Triangolo Scaleno")
else:
	print("NON é UN TRIANGOLO")