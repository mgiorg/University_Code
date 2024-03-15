// Inserire qui il C equivalente
unsigned int fib(unsigned int n) {
    unsigned int edx = 0, eax = 1;
    unsigned int ecx = n;
    if (ecx != 0) goto A;
    eax = edx;
    goto E;
A:
    if (ecx != 1) goto B;
    // eax = eax;
    goto E;
B:
L:
    if (ecx <= 1) goto E;
    ecx--;
    edx = edx + eax;
    edx = edx + eax;
    eax = -eax;
    eax = edx + eax;
    edx = edx - eax;
    goto L;
E:
    return eax;
}