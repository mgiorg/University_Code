def A_Ex3(l,n):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""
    if l == []:
        return ''
    else:
        s = ''
        for i in range(len(l)):
            if n>=len(l[i]):
                s = s + '!'
            else:
                prova = l[i]
                s = s + prova[n]
        return s



###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex3, [['tanto', 'va', 'la', 'gatta', 'al', 'lardo'], 3], 't!!t!d')
    counter_test_positivi += tester_fun(A_Ex3, [['tanto', 'va', 'la', 'gatta', 'al', 'lardo', 'che', 'ci', 'lascia', 'lo', 'zampino'], 4], 'o!!a!o!!i!i')
    counter_test_positivi += tester_fun(A_Ex3, [['nel', 'mezzo', 'del', 'cammin', 'di', 'nostra', 'vita', 'mi', 'ritrovai'], 6], '!!!!!!!!a')
    counter_test_positivi += tester_fun(A_Ex3, [['nel', 'mezzo', 'del', 'cammin', 'di', 'nostra', 'vita', 'mi', 'ritrovai'], 0], 'nmdcdnvmr')
    counter_test_positivi += tester_fun(A_Ex3, [[], 0],'')

    print('La funzione',A_Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)