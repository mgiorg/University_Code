def Ex3(file,n):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    # counter_test_positivi += tester_fun(Ex3, ['mosse1.csv',10],'Paolo')    
    # counter_test_positivi += tester_fun(Ex3, ['mosse1.csv',8],'Miriam')    
    # counter_test_positivi += tester_fun(Ex3, ['mosse2.csv',10],'Paolo')    
    # counter_test_positivi += tester_fun(Ex3, ['mosse2.csv',9],'Flavio')    
    # counter_test_positivi += tester_fun(Ex3, ['mosse2.csv',7],'Paolo')  
    counter_test_positivi += tester_fun(Ex3, ['mosse1.csv',10],'Paolo')    
    counter_test_positivi += tester_fun(Ex3, ['mosse1.csv',8],'Nessuno')    
    counter_test_positivi += tester_fun(Ex3, ['mosse2.csv',10],'Paolo')    
    counter_test_positivi += tester_fun(Ex3, ['mosse2.csv',9],'Flavio')    
    counter_test_positivi += tester_fun(Ex3, ['mosse2.csv',7],'Paolo')         
    
    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)

