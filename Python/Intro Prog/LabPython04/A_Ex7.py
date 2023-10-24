def A_Ex7(ex,cp2):   #riceve due numerali di lunghezza uguale e >0, EX CP2 e restituisce 'ex' se (ex)ex>(cp2)cp2
    "MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"



###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""
if __name__ == '__main__':
    from tester import tester_fun
    counter_test_positivi = 0
    total_tests = 5

  
    counter_test_positivi += tester_fun(A_Ex7, ['000','01'], 'ERRORE')
    
    counter_test_positivi += tester_fun(A_Ex7, ['001','001'], 'cp2')

    counter_test_positivi += tester_fun(A_Ex7, ['010','010'], 'cp2')
    counter_test_positivi += tester_fun(A_Ex7, ['00','010'], 'ERRORE')
    counter_test_positivi += tester_fun(A_Ex7, ['001','110'], 'ex')

    
 
    print('La funzione',A_Ex7.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
    
