def Ex1(s,l):
    insiemeLettere = set(s)
    conta = 0
    for el in l:
        insiemeParola = set(el)
        if insiemeParola == insiemeLettere:
            conta += 1
    return conta
    

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex1, ['canto',['canto', 'conto', 'cotanto', 'taccone']],2)
    counter_test_positivi += tester_fun(Ex1, ['canto',['canto', 'conta', 'cotta', 'tacco', 'cccaa', 'acnott']],3)
    counter_test_positivi += tester_fun(Ex1, ['canta',['canto', 'conta', 'tanca', 'tacconata']],1)
    counter_test_positivi += tester_fun(Ex1, ['pappa',['papa', 'appare', 'aappp', 'tacco']],2)
    counter_test_positivi += tester_fun(Ex1, ['papa',['pappe', 'papato']],0)  

    # test aggiuntivi
    
    counter_test_positivi += tester_fun(Ex1, ['cento',['cento', 'conte', 'cotte', 'tecco']],2)
    counter_test_positivi += tester_fun(Ex1, ['cento',['cento', 'conte', 'cotte', 'tecco', 'cccee', 'ecnott']],3)
    counter_test_positivi += tester_fun(Ex1, ['cente',['cento', 'conte', 'tence', 'tecconete']],1)
    counter_test_positivi += tester_fun(Ex1, ['peppe',['pepe', 'eppere', 'eeppp', 'tecco']],2)
    counter_test_positivi += tester_fun(Ex1, ['pepe',['peppa', 'pepeto']],0)  

    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
