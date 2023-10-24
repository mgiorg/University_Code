def A_Ex9(s,n):
    "MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"





###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""
if __name__ == '__main__':
    from tester import tester_fun
    counter_test_positivi = 0
    total_tests = 5

  
    counter_test_positivi += tester_fun(A_Ex9, ['1',1], '1')
    counter_test_positivi += tester_fun(A_Ex9, ['01',2], '11')
    counter_test_positivi += tester_fun(A_Ex9, ['00',2], '00')
    counter_test_positivi += tester_fun(A_Ex9, ['11',3], '001')
    counter_test_positivi += tester_fun(A_Ex9, ['01000',5], '11000')


    print('La funzione',A_Ex9.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
    
