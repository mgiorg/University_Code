def A_Ex6(s1,s2):  #somma due numeri in CP2
    
    if len(s1)!= len(s2):
        return 'ERRORE'
    else:
        if s1[0] != s2[0]:
            #la somma si può fare
            
        else:
            if s1[1]!= s2[1]:
                #la somma si può fare
            else:
                return 'ERRORE'


###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""
if __name__ == '__main__':
    from tester import tester_fun
    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex6, ['00','01'], '01')
    counter_test_positivi += tester_fun(A_Ex6, ['001','001'], '010')
    counter_test_positivi += tester_fun(A_Ex6, ['010','010'], 'ERRORE')
    counter_test_positivi += tester_fun(A_Ex6, ['00','010'], 'ERRORE')
    counter_test_positivi += tester_fun(A_Ex6, ['000','10'], 'ERRORE')

 
    print('La funzione',A_Ex6.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
    
