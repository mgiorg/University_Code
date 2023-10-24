def A_Ex5(s):
    max = 0
    stringa = ''

    for i in range(len(s)):

        if s.count(s[i]) >= max:
            max = s.count(s[i])

    for i in range(len(s)):
        if s.count(s[i]) == max and s[i] not in stringa:
            stringa += s[i]

    if len(stringa) == 1:
        return stringa
    
    else:
        max = 0
        for i in stringa:
            if s.rfind(i) >= max:
                max = s.rfind(i)
        return s[max]
            
        


###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""

    counter_test_positivi = 0
    total_tests = 4
    
    counter_test_positivi += tester_fun(A_Ex5, ["pippo"], "p")
    counter_test_positivi += tester_fun(A_Ex5, ["clarabella"],"a")
    counter_test_positivi += tester_fun(A_Ex5, ["mamma"], "m")
    counter_test_positivi += tester_fun(A_Ex5, ["cannolo"], "o")
    
    print('La funzione',A_Ex5.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
