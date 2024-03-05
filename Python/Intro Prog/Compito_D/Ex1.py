def Ex1(s,l):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""    

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex1, ['canto',['canto', 'conto', 'cotanto', 'taccone']],2)
    counter_test_positivi += tester_fun(Ex1, ['canto',['canto', 'conta', 'cotta', 'tacco', 'cccaa', 'acnott']],3)
    counter_test_positivi += tester_fun(Ex1, ['canta',['canto', 'conta', 'tanca', 'tacconata']],1)
    counter_test_positivi += tester_fun(Ex1, ['pappa',['papa', 'appare', 'aappp', 'tacco']],2)
    counter_test_positivi += tester_fun(Ex1, ['papa',['pappe', 'papato']],0)  
    
    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
