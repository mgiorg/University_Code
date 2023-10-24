def A_Ex1(s1,s2):
    stringa = ''
    if len(s1) > len(s2):
        max = len(s2)
    else:
        max = len(s1)

    if s1 == '' or s2 == '':
        return ''
        
    for i in range(max):
        if s1[i] == s2[i]:
            stringa = stringa + s1[i]
        else:
            return stringa
        
    return stringa

###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex1, ['amaca','amaranto'], 'ama')
    counter_test_positivi += tester_fun(A_Ex1, ['asso','assolato'], 'asso')
    counter_test_positivi += tester_fun(A_Ex1, ['','stringa'], '')
    counter_test_positivi += tester_fun(A_Ex1, ['stringa',''], '')
    counter_test_positivi += tester_fun(A_Ex1, ['ciao mamma','ciao '], 'ciao ')

    print('La funzione',A_Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
