def A_Ex3(s):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""

###############################################################################

"""NON MODIFICARE IL SEGUENTE CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""
    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex3, ['mamma'],'amamm')
    counter_test_positivi += tester_fun(A_Ex3, [''],'') 
    counter_test_positivi += tester_fun(A_Ex3, ['Cane'],'Cane')
    counter_test_positivi += tester_fun(A_Ex3, ['campo scuola'],' scuolacampo')
    counter_test_positivi += tester_fun(A_Ex3, ['aMBRa'],'MBRaa')


    print('La funzione',A_Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
