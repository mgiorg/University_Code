def A_Ex8(n):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""

       

###############################################################################

"""NON MODIFICARE IL SEGUENTE CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""
    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex8, [2],'**\n**\n')
    counter_test_positivi += tester_fun(A_Ex8, [5],'*****\n** **\n* * *\n** **\n*****\n')
    counter_test_positivi += tester_fun(A_Ex8, [6],'******\n**  **\n* ** *\n* ** *\n**  **\n******\n') 
    counter_test_positivi += tester_fun(A_Ex8, [1],'*\n')
    counter_test_positivi += tester_fun(A_Ex8, [-1],'ERRORE')

    print('La funzione',A_Ex8.__name__,'ha superato',counter_test_positivi,'test su',total_tests)

    
