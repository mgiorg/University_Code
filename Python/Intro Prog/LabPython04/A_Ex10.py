def Ex10(s,c1,c2):
    "MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"





###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 4

    # test distribuzione
  
    counter_test_positivi += tester_fun(Ex10, ['casale','a','l'],2)
    counter_test_positivi += tester_fun(Ex10, ['casale','c','e'],6)
    counter_test_positivi += tester_fun(Ex10, ['casale','s','s'],1)
    counter_test_positivi += tester_fun(Ex10, ['casale','f','g'],0)
   
    print('La funzione',Ex10.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
