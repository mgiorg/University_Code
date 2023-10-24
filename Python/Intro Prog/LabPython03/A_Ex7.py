def A_Ex7(b1,b2):
    #b1 = una stringa qualunque
    #b2 = una stringa qualsiasi
    #restituisce una stringa che rappresenta il risultato dell'operazione
    if len(b1) == 0:
        return '0'*len(b2)
    elif len(b2) == 0:
        return '0'*len(b1)
    else:
        if len(b1) > len(b2):
            max_len = len(b1)
        else:
            max_len = len(b2)
    
        


###############################################################################

"""NON MODIFICARE IL SEGUENTE CODICE (codice di test della funzione)"""
if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA"""

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex7, ['1011','100'],'1000')
    counter_test_positivi += tester_fun(A_Ex7, ['','111'],'000')
    counter_test_positivi += tester_fun(A_Ex7, ['1','1'],'1')
    counter_test_positivi += tester_fun(A_Ex7, ['111','10'],'100')
    counter_test_positivi += tester_fun(A_Ex7, ['1010',''],'0000')

    print('La funzione',A_Ex7.__name__,'ha superato',counter_test_positivi,'test su',total_tests)




