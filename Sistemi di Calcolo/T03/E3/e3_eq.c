// Inserire qui il C equivalente
int comp(const void* xv, const void* yv) {
    int* ecx = (int*)xv;
    int* edx = (int*)yv;
    int eax = *ecx;
    eax = eax - *edx;
    return eax;
}