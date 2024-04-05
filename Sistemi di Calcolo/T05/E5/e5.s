.globl f

f:      # int f(int x, int y) {
    pushl %ebx
    pushl %edi
    pushl %esi
    subl $8, %esp
    movl 20(%esp), %ebx         # int b = x;
    movl 24(%esp), %edi         # int di = y;
    movl %ebx, (%esp)
    movl %edi, 4(%esp)
    call g                      # int a = g(b, di);
    movl %eax, %esi             # int si = a;
    movl %edi, (%esp)
    movl %ebx, 4(%esp)
    call g                      # a = g(di, b);
    addl %esi, %eax             # a = a + si;
    popl %ebx
    popl %edi
    popl %esi
    addl $8, %esp
    ret             # return a;