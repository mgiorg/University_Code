def veroFalso():
    ##############################################################################################
    # Modificare il valore del return elencando le lettere delle domande che valutate essere vere
    # Ad esempio, se pensate che B, C, e D siano vere la funzione deve restituire 'BCD'
    ##############################################################################################

    d=eval(open('/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/Compito_A/VeroFalsoA.txt',encoding="UTF-8").read())
    print(d)
    for dom in 'ABCDEFGH':
        print(dom+')', end='')
        print(d[dom]['premessa'])
        print(d[dom]['domanda'])
        print(d[dom]['ris'])
        print()
    return 'ABCDF'

veroFalso()
print('**** Modificare il valore restituito dalla funzione ****')
