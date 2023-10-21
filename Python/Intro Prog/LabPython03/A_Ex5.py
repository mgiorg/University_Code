def A_Ex5(s):
    if s != '':
        x = s.count('-') #Conto quante volte il carattere si ripete
        list = [] #Creo una lista vuota
        stringa = s
        for i in range(x+1):
            t = stringa.find('-')
            print("i = ", i)
            print("t = ", t)
            print("stringa = ", stringa)
            if t == -1:
                list.append(stringa)
            else:
                list.append(stringa[:t])
                stringa = stringa[t+1:]
        max = 0
        for i in range(len(list)):
            if int(list[i]) >= max:
                max = int(list[i])
        return max


if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex5, ['12-123-45-6-78'] ,123)
    counter_test_positivi += tester_fun(A_Ex5, ['11-12-12'] ,12)
    counter_test_positivi += tester_fun(A_Ex5, ['80-40-80-40'] ,80)
    counter_test_positivi += tester_fun(A_Ex5, ['10'] ,10)
    counter_test_positivi += tester_fun(A_Ex5, ['1-2-3-4-5'] ,5)

    print('La funzione',A_Ex5.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
