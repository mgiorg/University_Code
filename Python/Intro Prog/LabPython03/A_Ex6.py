def A_Ex6(s):
    max = 0
    x = 0
    for i in s:
        if ord(i)>=65 and ord(i)<=90:
            if s.count(i) >= max:
                max = s.count(i)
            
        
    return max
	
	
###############################################################################

"""NON MODIFICARE IL SEGUENTE CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun
    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA"""

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex6, ['aHa^^&^HH'], 3)
    counter_test_positivi += tester_fun(A_Ex6, [''], 0)
    counter_test_positivi += tester_fun(A_Ex6, ['&&YH&Y'], 2)
    counter_test_positivi += tester_fun(A_Ex6, ['stri%$p'], 0)
    counter_test_positivi += tester_fun(A_Ex6, ['CIAO'], 1)

    print('La funzione',A_Ex6.__name__,'ha superato',counter_test_positivi,'test su',total_tests)

###############################################################################

