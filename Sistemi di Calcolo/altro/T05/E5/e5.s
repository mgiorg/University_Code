.globl f

f:  # int f(int x, int y) {
    pushl %ebx
    pushl %edi
    pushl %esi
    subl $8, %esp
    # ERRORE!!!!
    # offset di spiazzamento da ESP calcolari in modo errato
    # prima parametro si trova a: 4 + ESP + 12 (tre push) + 8 (due parametri)
    movl 24(%esp), %ebx         # int b = x;
    movl 28(%esp), %edi         # int di = y;
    movl %ebx, (%esp)
    movl %edi, 4(%esp)
    call g                      # int a = g(b, di);
    movl %eax, %esi             # int si = a;
    movl %edi, (%esp)
    movl %ebx, 4(%esp)
    call g                      # a = g(di, b);
    addl %esi, %eax             # a = a + si;
    # ERRORE!!!!
    # occorre prima deallocare lo spazio per i parametri e poi fare le pop
    addl $8, %esp
    # ERRORE!!!!
    # l'ordine delle pop deve essere inverso a quello delle push!
    popl %esi
    popl %edi
    popl %ebx
    ret             # return a;