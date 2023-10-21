def isIntero(s):
	x = 1
	for i in s:
		stringa = '0123456789'
		if i != '+' and i != '-' and i not in stringa:
			x = 0
	if x == 1:
		return True
	else:
		return False
	

def divisoreNonComune(n1, n2, d):
	if n1 >0 and n2 >0 and d >0:
		if n1%d == 0 and n2%d != 0:
			return True
		else:
			return False
	else:
		return False