def Ex1(s,l):
    listaLettere = list(s)
    listaLettere.sort()
    conta = 0
    for el in l:
        listaParola = list(el)
        listaParola.sort()
        if listaParola == listaLettere:
            conta += 1
    return conta
    

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex1, ['canto',['canto', 'conta', 'cotta', 'tacco']],2)
    counter_test_positivi += tester_fun(Ex1, ['canto',['canto', 'conta', 'cotta', 'tacco', 'cccaa', 'acnott']],2)
    counter_test_positivi += tester_fun(Ex1, ['canta',['canto', 'conta', 'tanca', 'tacconata']],1)
    counter_test_positivi += tester_fun(Ex1, ['pappa',['papa', 'appare', 'aappp', 'tacco']],1)
    counter_test_positivi += tester_fun(Ex1, ['papa',['pappa', 'papato']],0)  

    # test aggiuntivi
    
    counter_test_positivi += tester_fun(Ex1, ['cento',['cento', 'conte', 'cotte', 'tecco']],2)
    counter_test_positivi += tester_fun(Ex1, ['cento',['cento', 'conte', 'cotte', 'tecco', 'cccee', 'ecnott']],2)
    counter_test_positivi += tester_fun(Ex1, ['cente',['cento', 'conte', 'tence', 'tecconete']],1)
    counter_test_positivi += tester_fun(Ex1, ['peppe',['pepe', 'eppere', 'eeppp', 'tecco']],1)
    counter_test_positivi += tester_fun(Ex1, ['pepe',['peppe', 'pepeto']],0)  

    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
