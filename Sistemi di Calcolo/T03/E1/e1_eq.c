// Inserire qui il C equivalente
int min(int x, int y, int z) {
    int eax = x;
    int ecx = y;
    int edx = z;

    if(eax >= ecx) 
        goto CD;
    if(eax >= edx) 
        goto D;
    
    goto E;

CD:
    if(ecx >= edx)
        goto D;
    eax = ecx;
    goto E;

D:
    eax = edx;
    goto E;

E:
    return eax;
}
