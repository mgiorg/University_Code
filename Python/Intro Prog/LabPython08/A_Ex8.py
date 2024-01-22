def A_Ex8(fileName):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""
    f = open(fileName, encoding = 'utf-8')

    riga = 0
    r = 1
    count = 0
    max = 0

    for elem in f:

        for i in elem:

            if i.isupper():
                count += 1
            
            if count >= max:
                max = count
                riga = r
        r+=1
        count = 0
    
    return riga

 
###############################################################################

"""TEST FUNZIONE, NON MODIFICARE"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex8, ["/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/file1.txt"] , 2)
    counter_test_positivi += tester_fun(A_Ex8, ["/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/file2.txt"] , 2)
    counter_test_positivi += tester_fun(A_Ex8, ["/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/file3.txt"] , 2)
    counter_test_positivi += tester_fun(A_Ex8, ["/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/file4.txt"] , 3)
    counter_test_positivi += tester_fun(A_Ex8, ["/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/file5.txt"] , 3)

    print('La funzione',A_Ex8.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
