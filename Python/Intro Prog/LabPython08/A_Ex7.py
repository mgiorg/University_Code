def A_Ex7(fileName):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""
    f = open(fileName, encoding = 'utf-8')
    s = f.read()
    f.close()

    somma = 0
    stringa = ''
    for i in s:
        
        if ord(i) >= ord('0') and ord(i) <= ord('9'):
            stringa += i
        if i == ' ' and stringa != '':
            somma += int(stringa)
            stringa = ''
    
    return somma

#A_Ex7("/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/file1.txt")
 
###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex7, ["/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/file1.txt"] , 14)
    counter_test_positivi += tester_fun(A_Ex7, ["/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/file2.txt"] , 17)
    counter_test_positivi += tester_fun(A_Ex7, ["/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/file3.txt"] , 18)
    counter_test_positivi += tester_fun(A_Ex7, ["/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/file4.txt"] , 20)
    counter_test_positivi += tester_fun(A_Ex7, ["/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/file5.txt"] , 0)

    print('La funzione',A_Ex7.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
