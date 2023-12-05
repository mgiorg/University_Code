def A_Ex8(l):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""

###############################################################################

"""NON MODIFICARE IL SEGUENTE CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""
    counter_test_positivi = 0
    total_tests = 4

    counter_test_positivi += tester_fun(A_Ex8, [[('pippo',['blu','giallo']),('minnie', ['rosa']),('pippo', ['rosso', 'blu'])]] , [('minnie',{'rosa'}), ('pippo', {'blu', 'rosso', 'giallo'})])
    counter_test_positivi += tester_fun(A_Ex8, [[('roma',['colosseo']),('parigi',['tour eiffel'])]],  [('parigi',{'tour eiffel'}),('roma',{'colosseo'})])
    counter_test_positivi += tester_fun(A_Ex8,[[('roma',['colosseo']),('parigi',['tour eiffel']),('roma',['fontana di trevi','colonna di traiano','colosseo'])]],  [('parigi',{'tour eiffel'}),('roma',{'colosseo','fontana di trevi','colonna di traiano'})])
    counter_test_positivi += tester_fun(A_Ex8, [[]] , [])


    print('La funzione',A_Ex8.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
