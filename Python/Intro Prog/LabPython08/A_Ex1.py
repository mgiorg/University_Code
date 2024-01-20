def A_Ex1(fileName):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""
    f = open(fileName, encoding = 'UTF-8') #Aperto il file con encoding per file di testo
    
    stringa = f.read() #Salvo tutto su una stringa
    s = stringa.split() #Tolgo tutti i caratteri speciali
    f.close()

    count = 0
    for i in s:
        for chr in i:
            if (ord(chr) >= ord('A') and ord(chr) <= ord('z')) or ord(chr) == ord('à') or ord(chr) == ord('è') or ord(chr) == ord('é') or ord(chr) == ord('ì') or ord(chr) == ord('ò') or ord(chr) == ord('ù') :
                count += 1
    
    return count 

#A_Ex1('/Users/massimogiordano/Desktop/Programmazione/University_Code/Python/Intro Prog/LabPython08/Esempio2.txt')

###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex1, ["/Users/massimogiordano/Desktop/Programmazione/University_Code/Python/Intro Prog/LabPython08/Esempio1.txt"], 7)
    counter_test_positivi += tester_fun(A_Ex1, ["/Users/massimogiordano/Desktop/Programmazione/University_Code/Python/Intro Prog/LabPython08/Esempio2.txt"], 53)
    counter_test_positivi += tester_fun(A_Ex1, ["/Users/massimogiordano/Desktop/Programmazione/University_Code/Python/Intro Prog/LabPython08/Esempio3.txt"], 26)
    counter_test_positivi += tester_fun(A_Ex1, ["/Users/massimogiordano/Desktop/Programmazione/University_Code/Python/Intro Prog/LabPython08/I_Malavoglia_50.txt"], 11808)
    counter_test_positivi += tester_fun(A_Ex1, ["/Users/massimogiordano/Desktop/Programmazione/University_Code/Python/Intro Prog/LabPython08/I_Malavoglia.txt"], 382468)

    print('La funzione',A_Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)