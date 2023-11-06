def Ex10(s):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""



###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione
  
    counter_test_positivi += tester_fun(Ex10, ['casale'],'acels')
    counter_test_positivi += tester_fun(Ex10, ['casa'],'acs')
    counter_test_positivi += tester_fun(Ex10, ['cavallo'],'aclov')
    counter_test_positivi += tester_fun(Ex10, ['Tanto va la Gatta'],' GTalnotv')
    counter_test_positivi += tester_fun(Ex10, ['1234567890'],'0123456789') 
   
    print('La funzione',Ex10.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
