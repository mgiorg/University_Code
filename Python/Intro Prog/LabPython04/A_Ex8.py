def A_Ex8(numBin):
    "MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"


###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""
if __name__ == '__main__':
    from tester import tester_fun
    counter_test_positivi = 0
    total_tests = 5

  
    counter_test_positivi += tester_fun(A_Ex8, ['111.101'], '7.625')
    counter_test_positivi += tester_fun(A_Ex8, ['1.1'], '1.5')
      
    counter_test_positivi += tester_fun(A_Ex8, ['0.1'], '0.5')
    counter_test_positivi += tester_fun(A_Ex8, ['1.0'], '1.0')
    counter_test_positivi += tester_fun(A_Ex8, ['0.01'], '0.25')


    print('La funzione',A_Ex8.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
    
